#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

double pop(void);
void push(double);
int getop(char []);

void clearstack(void);
void swaptoptwo(void);
void duptop(void);
double peek(void);
/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("ERROR: ZERO DIVISOR\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ERROR: UNKNOWN COMMAND %s\n", s);
            break;
        }
    }

    return EXIT_SUCCESS;
}

double val[MAXVAL];
int sp = 0; /* next free stack postition */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: STACK FULL, cannot push %g\n", f);
        //fprintf(stderr, "ERROR: STACK IS FULL\n");
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else{
        //fprintf(stderr, "ERROR: STACK IS EMPTY\n");
        printf("ERROR: STACK IS EMPTY\n");
        return 0.0;
    }
}

/* return the top element of the stack without popping */
double peek(void)
{
    if (sp > 0)
        return val[sp - 1];
    else{
        /*
        fprintf(stderr, "ERROR: PEEK: STACK IS EMPTY");
        exit(EXIT_FAILURE);
        */
        printf("ERROR: PEEK: STACK IS EMPTY\n");
        return 0.0;
    }
    /* could pop and push instead of rewriting pop logic :| */
}

/* duplicate the top of the stack */
void duptop(void)
{
    push(peek());
    /*
     * double f = pop();
     * push(f);
     * push(f);
     */
}
/* swap top two elements of the stack */
void swaptoptwo(void)
{
    /*
    double d1, d2;
    d2 = pop();
    d1 = pop();
    push(d2);
    push(d1);
    */
    double tmp;
    if (sp > 1){
        tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }else{
        //fprintf(stderr, "ERROR: SWAPTOPTWO: TOO FEW ELEMENTS IN STACK\n");
        printf("ERROR: TOO FEW ELEMENTS IN STACK\n");
    }
}

/* clear stack */
void clearstack(void)
{
    sp = 0;
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch())) /* collect integer part */
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch())) /* collect fraction part */
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? (buf[--bufp]) : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
