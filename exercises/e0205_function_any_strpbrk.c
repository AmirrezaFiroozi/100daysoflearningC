#include <stdio.h>

/* Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs
 * or -1 if s1 contains no chars from s2
 */

int any(const char s1[], const char s2[]);
int main()
{

    printf("%d\n", any("Is this just a test? Or is there more to it?", "a?"));
    return 0;
}

int any(const char s1[], const char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i)
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
