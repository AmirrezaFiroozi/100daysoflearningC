#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

double pop(void);
void push(double);
int getop(char []);

/*
 * Exercise 4-3. Given the basic framework, it's straightforward to extend the
 * calculator. Add modulus (%) operator and provisions for negative numbers
 */

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
        case '%':
        case '/':
            op2 = pop();
            if (op2 != 0.0){
                if (type == '/')
                    push(pop() / op2);
                else
                    push((long) pop() % (long) op2);
            }else{
                printf("ERROR: ZERO DIVISOR\n");
            }
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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.'){
        if ((c == '-' || c == '+') && isdigit(s[1] = getch())){
            c = s[1];
            i = 1;
        }else{
            if (s[1] != '\0')
                ungetch(s[1]);
            s[1] = '\0';
            return c; /* not a number */
        }
    }

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
