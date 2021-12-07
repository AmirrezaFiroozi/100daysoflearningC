#include <stdio.h>

/*
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine.
 */

char *itoa(int n, char *s);
int main(void)
{
    char s[1000] = "Garbage really garbage";
    int n = -32145213;
    printf("%s\n", itoa(n, s));
    printf("\n");
    return 0;
}

char *itoa(int n, char *s)
{
    static int bh = 0;
    if (n < 0){
        //s[bh++] = '-';
        *(s + bh++) = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s);
    //s[bh++] = n % 10 + '0';
    //s[bh] = '\0';
    *(s + bh++) = n % 10 + '0';
    *(s + bh) = '\0';
    return s;
}
