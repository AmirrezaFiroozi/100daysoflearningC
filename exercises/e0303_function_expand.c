#include <stdio.h>

/* Write a function expand(s1, s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2
 * Allow for letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
 */

char* expand(char s1[], char s2[]);
int main()
{
    char lstr[] = "-a-b-c a-z0-9 -a-z z-a A-Z life goes on 9-0-";
    char test[1000];
    printf("%s\n%s", lstr, expand(lstr, test));
    return 0;
}

char* expand(char s1[], char s2[])
{
    int bh, cp, c; /* buffer head, copy head, current char */
    int lsc = 0, lec = 0; /* list starting char, list ending char */
    for (bh = 0, cp = 0; (c = s1[bh]) != '\0'; ++bh){
        if (c == '-'){
            lsc = 0;
            lec = 0;
            if(bh == 0 || s1[bh-1] == ' ' || s1[bh - 1] == '\t' || s1[bh + 1] == ' ' || s1[bh + 1] == '\n' || s1[bh + 1] == '\0')
                s2[cp++] = '-';
            else{
                // override the previous start of the list notation
                // (cause e.g. a in a-z not to be copied twice!)
                cp--;
                // - is part of a list notation a-z
                lsc = (s1[bh - 1]);
                lec = (s1[bh + 1]);
                printf("lsc: %d %c, lec: %d %c\n", lsc, lsc, lec, lec);
                if (lec > lsc)
                    while ( (s2[cp++] = lsc++) != lec - 1 )
                        ;
                else
                    // end < start; iterate backwards
                    while ( (s2[cp++] = lsc--) != lec + 1 )
                        ;
            }
        }else 
            s2[cp++] = c;
    }
    s2[cp] = '\0';
    return s2;
}
