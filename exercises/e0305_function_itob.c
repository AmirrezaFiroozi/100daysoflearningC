#include <stdio.h>
#include <ctype.h>
#include <string.h> /* for strrev function */

/* Write the function itob(n, s, b) that converts the integer n into base b
 * character representation in the string s. In particular, itob(n, s, 16)
 * formats n as a hexadecimal integer in s. 
 */

/*
 * My routine handles only non negative numbers.
 * Because I have no idea how to represent negative
 * numbers in every base
 */

char *reverse(char s[]);
char *itob(unsigned n, char s[], unsigned b);
int main(void)
{
    char buf[1000];
    int b;
    unsigned int num = 0x47BD3FE4;
    /* print num in bases 2...36 */
    for (b = 2; b < 37; b++)
        printf("b: %d, %s\n",b ,itob(num, buf, b));
    return 0;
}

/* convert n to its string representation in base b */

/* max base 36 
 * 0-9: 10digits, A-Z: 26digits, 36 sensible digits in total...
 */
char *itob(unsigned n, char s[], unsigned b)
{
    /* if base is not in range return empty string */
    if (b < 2 || b > 36){
        s[0] = '\0';
        return s;
    }
    int i, digit, r;
    i = 0;
    /* generate digits in reverse order */
    do{
        r = (n % b);
        n /= b;
        digit = (r < 10) ? (r + '0') : (r - 10 + 'A');
        s[i++] = digit;
    }while (n > 0);
    s[i] = '\0';
    /* correct the order */
    reverse(s);
    return s;
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
