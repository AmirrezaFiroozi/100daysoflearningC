#include <stdio.h>
#include <stdlib.h> /* for abs function */
#include <limits.h>
#include <string.h>

/* Exercise 3-4. In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value
 * of n equal to -(2^(wordsize - 1)). Explain why not.
 * Modify it to print that value correctly,
 * regardless of the machine on which it runs
 */

/*
 * Explain why not:
 * if n is the largest negative number trying to make it positive with 
 * n = -n; 
 * causes data loss because abs(largest positive) = abs(largest negative) - 1
 * so int can't hold the positive equivalent of largest negative number!
 * Or one can say in a two's complement system the MSB has a value of -(2^(wordsize - 1))
 * and functions as the sign bit. so wordsize - 1 bits are left for positive integers
 * which can range from 0 to (2^(wordsize - 1) - 1)
 */

char *reverse(char s[]);
char *itoa(int n, char s[]);

int main(void)
{
    char buf[1000];
    int num = INT_MIN;
    printf("%s\n", itoa(num, buf));

    return 0;
}

/* itoa: convert n to characters in s */
char *itoa(int n, char s[])
{
    int i;
    unsigned int num; /* absolute value of n */
    num = (n < 0) ? -n : n;
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = num % 10 + '0'; /* get next digit */
    } while ((num /= 10) != 0); /* delete it */
    if (n < 0) /* check original numbers sign */
        s[i++] = '-';
    s[i] = '\0';
    return reverse(s);
}
/* reverse string s */
char *reverse(char s[])
{
    int i, j, tmp;
    for (i = 0, j = strlen(s) - 1; i < j ; i++, j--){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    return s;
}
