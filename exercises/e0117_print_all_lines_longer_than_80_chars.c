#include <stdio.h>

#define MAXLENGTH 500
#define ARRAYSIZE (MAXLENGTH+1)

int getLine(char buffer[], int limit);
/* print lines longer than 80 chars */
int main()
{
    char line[ARRAYSIZE];
    int len;
    while ((len=getLine(line, MAXLENGTH)) > 0)
        if (len > 80)
            printf("%s", line);

    return 0;
}
int getLine(char buffer[], int limit)
{
    int bh; /* buffer head */
    int c;
    for (bh = 0; bh < limit-1 && (c=getchar())!=EOF && c!='\n'; ++bh)
        buffer[bh] = c;
    if (c=='\n'){
        buffer[bh] = c;
        ++bh;
    }
    buffer[bh] = '\0';
    return bh;
}
