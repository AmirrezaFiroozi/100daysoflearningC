#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 */

char *reverse(char s[]);
char *itoa(int n, char s[], int mfw);

int main(void)
{

    char buf[30];
    int i;
    for (i = 1; i < 1000000; i *= 4)
        printf("%s\n", itoa(i, buf, 6));
    return 0;
}

/* itoa: convert n to characters in s */
char *itoa(int n, char s[], int mfw)
{
    int i, dcnt;
    unsigned int num;
    num = (n > 0) ? n : -n ; /* store the abs of n in num */
    dcnt = 0; /* digit count */
    i = 0;
    do {
        dcnt++;
        s[i++] = (num % 10) + '0'; /* generate number characters in reverse order */
    }while ((num /= 10) > 0);

    mfw -= dcnt + 1; /* this many spaces to add */
    // mfw = mfw - dcnt - 1
    for (; mfw > 0; --mfw)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
    return s;
}

/* reverse string s */
char *reverse(char s[])
{
    int i, j, tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    return s;
}
