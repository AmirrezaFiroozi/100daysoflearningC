#include <stdio.h>
#include <ctype.h>

/* write the function htoi(s) which converts a string of hexadecimal digits
 * including an optional 0x or 0X into its equivalent integer value
 */

int htoi(char s[]);
int main()
{
    /* string is given to htoi which calculates int value, printf %x prints the int num in hexadecimal format
     * if htoi is working as expected, then what is printed should be the same string as htoi's input argument
     * */
    printf("%x\n", htoi("0xAff"));
return 0;
}

/* Converts a string of hex to int; assumes the string contains valid hex and that int can hold it */
/* Ignores anything other than 0-9 a-f A-F and behaves as if they weren't present 
 * E.g. "0xA9ZB2" --> "0xA9B2"
 */
int htoi(char s[])
{
    int i, n;
    unsigned char c;
    n = 0;
    for (i = 0; (c=tolower(s[i])) != '\0'; ++i){
        if (c >= '0' && c <= '9'){
//        if (isdigit(c)){
            c -= '0';
        }else if (c >= 'a' && c <= 'f'){
            c = c - 'a' + 10;
        }else 
            continue;
        n = n*16 + c;
    }
    return n;
}
