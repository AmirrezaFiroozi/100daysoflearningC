#include <stdio.h>

#define MAXLEN 500

int main()
{
    int c, i;
    char s[MAXLEN+1];
    int lim = MAXLEN;
    for (i = 0; i < lim-1; ++i)
        if ((c=getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
    s[i] = '\0';
    printf("\n%s\n", s);



    return 0;
}
