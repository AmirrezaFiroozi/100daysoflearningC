#include <stdio.h>
#include <string.h>

/*
 * Write the function strrindex(s, t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none
 */

int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);
int main(void)
{
    char buf[] = "People would fuck your life"; // if they could. You should not let them.";
    char pattern[] = "ould";
    int index = strindex(buf, pattern);
    int rindex = strrindex(buf, pattern);
    printf("%s\n%d, %c\n",buf, index, (index >= 0) ? buf[index] : ' ');
    printf("%s\n%d, %c\n",buf, rindex, (rindex >= 0) ? buf[rindex] : ' ');
    return 0;
}

/* strindex: returns position of the first (leftmost) occurrence of t in s */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strrindex: returns the position of the last (rightmost) occurrence of t in s */
int strrindex(char s[], char t[])
{
    int i, j, k; 
    for (i = strlen(s) - strlen(t); i >= 0; i--){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
