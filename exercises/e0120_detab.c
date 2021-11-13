#include <stdio.h>
#include <stdbool.h>

#define TS   8

/* replace tabs with proper number of spaces to get to the next tab stop */
// Tab stops have fixed values equal to k*TS k=0, 1, 2,..., 
int main()
{
    int c, i;
    int pos; /* keep track of position */

    //show position of tab stops
    //comment this block if you don't need the ruler :)
/*
    {
        for (i = 0; i < 150; ++i)
            if ((i%TS)==0)
                putchar('+');
            else
                putchar('-');
        putchar('\n');
    }
*/

        while ((c=getchar())!=EOF){
        if (c == '\t'){
            for (i = 0; i < (TS - pos); ++i)
                putchar(' ');
            pos = 0;
        }else{
            ++pos;
            if (c == '\n')
                pos = 0;
            putchar(c);
        }
        if (pos == TS)
            pos = 0;
    }

    return 0;
}
