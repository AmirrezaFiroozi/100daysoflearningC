#include <stdio.h>
#include <stdbool.h>

/* write function squeeze(s1, s2) that deletes each character in s1 that matches any char in s2 */

char* squeeze(char s1[], char s2[]);
int main()
{
    char str[] = "This is just a test";
    printf("%s\n", squeeze(str, "it"));
    return 0;
}

/*
 * delete from s1 every instance of each char present in s2
 */
char* squeeze(char s1[], char s2[])
{
    bool copy;
    int bh; /* buffer head */
    int ch; /* copy head */
    int i; /* s2 buffer head */
    for (bh = ch = 0; s1[bh] != '\0'; ++bh){
        copy = true;
        for (i = 0; s2[i] != '\0'; ++i)
            if (s1[bh] == s2[i])
                copy = false;
        if (copy){
            s1[ch++] = s1[bh];
        }
    }
    s1[ch] = '\0';
    return s1;
}
