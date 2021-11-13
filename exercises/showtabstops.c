#include <stdio.h>

#define TS 8
int main()
{
    int i;
    for (i = 0; i < 150; ++i)
        if ((i%TS)==0)
            putchar('+');
        else
            putchar('-');
    putchar('\n');
}

