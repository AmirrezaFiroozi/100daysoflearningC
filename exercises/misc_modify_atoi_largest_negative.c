#include <stdio.h>
#include <ctype.h>
#include <limits.h>

/* In a two's complement number representation, our version of atoi doesn't handle
 * the largest negative number, that is, the value of n equal to -(2^(wordsize-1)).
 * Explain why not. Modify it to print that value correctly, regardless of
 * the machine on which it runs.
 */
/*
 * When I wanted to solve e3-4 I misread itoa and ended up modifying atoi :|
 * I will leave this here and will do the real e3-4 as well
 */
int atoi(char s[]);
int main(void)
{
    int num;
    char numstr[30];
    sprintf(numstr, "%d", INT_MIN);
    printf("%s\n", numstr);
    printf("%d\n", atoi(numstr));
    return 0;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    /* decrement the number before sign multiplication */ 
    --n;
    /* increment or decrement n depending on sign after sign is applied */
    return sign * n + ((sign == 1) ? 1 : -1);
}
