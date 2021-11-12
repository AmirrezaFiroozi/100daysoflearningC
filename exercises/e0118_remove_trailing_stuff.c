#include <stdio.h>

/* remove trailing blanks and tabs from each line of input and delete completely blank lines */

// if the line length is 1 (or <2) skip

#define MAXLINE 100

int getCorrectedLine(char buf[], int limit);
int main()
{

    char buf[MAXLINE];
    int len;
    while ((len=getCorrectedLine(buf, MAXLINE)) > 0)
        if (len > 1)
            printf("%s\n", buf);

    return 0;
}
/* read a line, correct the line, return corrected line's length */
int getCorrectedLine(char buf[], int limit)
{
// get a line; have a last-non-blank-char position variable ; put a '\0' at the pos+1; print the line;
int c, bh, pos;
    // CTRL + C to break!
    pos = 0;
    for (bh = 0; bh < limit-1 && (c=getchar())!=EOF && c!='\n'; ++bh){
        buf[bh] = c;
        if (c!=' ' && c!='\t')
            pos = bh;
    }
    if (c == '\n'){
        buf[bh] = c;
        ++bh;
    }
    // move the buffer head to last nonblank char position; add '\0' after it
    if (pos < bh){
        bh = pos+1;
    }
    buf[bh] = '\0';

    return bh;
}
