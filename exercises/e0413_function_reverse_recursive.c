#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Write a recursive version of the function
 * reverse(s), which reverses the string s in place.
 */

char *reverse(char *s);
int main(void)
{
    char buf[] = "lorem ipsum blah balh haha testing";
    char *buf2 = malloc(100);
    //char *buf3 = "This creates a constant string with a pointer to it. The behaviour is undefined if one tries to change this string!";
    if (!buf2)
        printf("ERROR WITH MALLOC");
    strcpy(buf2, "To be or not to be that is the question");
    printf("%s\n", reverse(buf));
    printf("%s\n", reverse(buf2));
    //printf("%s\n", reverse(buf3)); /* WRONG */
    free(buf2);
    return 0;
}

char *reverse(char *s)
{
//    // iterative version
//    int i, j;
//    char tmp;
//    for (i = 0, j = strlen(s) - 1; i < j ; i++, j--){
//        tmp = s[i];
//        s[i] = s[j];
//        s[j] = tmp;
//    }
    static int i = 0;
    int j = strlen(s) - 1 - i;
    //printf("i: %i, j: %i, s[i]: %c, s[j]: %c\n", i, j, s[i], s[j]);
    if (i >= j){
        i = 0;
        return s;
    }
    char tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    i++;
    reverse(s);
    return s;
}
