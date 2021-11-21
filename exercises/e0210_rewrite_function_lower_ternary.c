#include <stdio.h>

/* Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else
 */
int lower(int c);
int main()
{
    printf("%c\n", lower('N'));
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
