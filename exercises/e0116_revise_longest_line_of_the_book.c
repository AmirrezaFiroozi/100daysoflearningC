#include <stdio.h>
#define MAXLINE 100 /* maximum input line size */

/*
 *  I didn't understand this question at the beginning which is why I googled its meaning... (not the code but the algorithm... so...)
 *  Also since I needed to exceed the MAXLINE limit, I reduced to just 100 (from 1000)
 *  Update:
 *      Reading pages 28-30 again I understood the exercise to some extend :)
 */

// renamed getline to getlinee to avoid name confilict
int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */ 
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    int c;

    max = 0;
    while ((len = getlinee(line, MAXLINE)) > 0){
        if (line[len-1] != '\n' && line[len-1] != EOF)
            while ((c=getchar())!=EOF && c!='\n')
                ++len;
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */
        printf("len: %d, line:\n%s\n",max, longest);
    return 0;
}

/* getlinee: read a line into s, return length */
int getlinee(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i]= c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
