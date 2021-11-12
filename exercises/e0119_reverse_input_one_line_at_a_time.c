#include <stdio.h>

#define MAXLINE 1000
/* A program that reverses its input a line at a time + reverse(s) func */

int getlinee(char buf[], int limit);
char* reverse(char s[]);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len=getlinee(line, MAXLINE)) > 0)
        printf("%s\n", reverse(line));

    return 0;
}

/* load a line into buf, return len */
int getlinee(char buf[], int limit)
{
    int c, bh;
    for (bh = 0; bh < limit-1 && (c=getchar()) != EOF && c != '\n'; ++bh)
        buf[bh] = c;
    if (c == '\n'){
        buf[bh] = c;
        ++bh;
    }
    buf[bh] = '\0';
    return bh;
}

/* reverse s[] (excludes '\n') expects nul terminated s[] returns the same pointer as its input for use in printf... */
char* reverse(char s[])
{
    char tmp[MAXLINE];
    int bh, th; /* buf head, tmp head */
    for (bh = 0; s[bh]!='\0' && s[bh]!='\n'; ++bh)
        tmp[bh] = s[bh];
    for (th = 0; th < bh; ++th)
        s[th] = tmp[bh-th-1];
    s[th] = '\0'; // could be omitted since it was already nul terminated?
    return s;
}
