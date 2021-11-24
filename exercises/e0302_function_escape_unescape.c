#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN  1000
/* Write a function escape(s, t) that converts characters
 * like newline and tab into visible escape sequences like
 * \n and \t as it copies the string t to s. Use a switch.
 *
 * Write a function for the other direction as well, converting
 * escape sequences into the real character
 */

char* escape(char s[], char t[]);
char* unescape(char s[], char t[]);
int getlinee(char line[], int limit);
int main()
{
    char line[MAXLEN + 1];
    char line_modified[2 * MAXLEN + 1];
    while (getlinee(line, MAXLEN + 1) > 0){
        unescape(line_modified, line);
        //printf("%s\n", escape(line_modified, line));
        printf("%s", line_modified);
    }
//    printf("%s", unescape(line_modified, "Something"));
    return 0;
}

int getlinee(char line[], int limit)
{
    int bh, c;
    for (bh = 0; bh < limit-1 && (c=getchar()) != '\n' && c != EOF; ++bh)
        line[bh] = c;
    if (c == '\n')
        line[bh++] = c;
    line[bh] = '\0';
    return bh;
}
/*
 * Copy t to s, add escape sequences (make escape sequences visible), assume s is big enough
 */
char* escape(char s[], char t[])
{
    int cp, bh; /* copy head, buffer head */
    int c;
    for (bh = 0, cp = 0; (c = t[bh]) != '\0'; ++bh){
        switch (c){
            case '\n':
                s[cp++] = '\\';
                s[cp++] = 'n';
                break;
            case '\t':
                s[cp++] = '\\';
                s[cp++] = 't';
                break;
            default:
                s[cp++] = c;
                break;
        }
    }
    s[cp] = '\0';
    return s;
}
/*
 * Copy t to s, convert literal "\t" and "\n" to actual '\n' and '\t', assume s is big enough
 */
char* unescape(char s[], char t[])
{
    int cp, bh, c;
    bool expectingEscape = false; 
    for (bh = 0, cp = 0; (c = t[bh]) != '\0' ; ++bh){
        if (c == '\\'){
            // read backslash
            if (expectingEscape){
                // previous was backslash so... do nothing... copy "\\"
                s[cp++] = '\\';
                s[cp++] = '\\';
                expectingEscape = false;
            }else
                expectingEscape = true;
        }else{
            // read char other than backslash
            if (expectingEscape){
                switch (c){
                    case 't':
                        s[cp++] = '\t';
                        break;
                    case 'n':
                        s[cp++] = '\n';
                        break;
                    default:
                        //Unknown escape sequence print as was
                        s[cp++] = '\\';
                        s[cp++] = c;
                        break;
                }
            }else
                s[cp++] = c;
            expectingEscape = false;
        }
    }
    s[cp] = '\0';
    return s;
}
