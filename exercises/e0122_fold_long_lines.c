#include <stdio.h>

#define MAXLEN  1000

#define WRAPCOLUMN  80

int getlinee(char buf[], int limit);
int printStrPortion(char buf[], int start, int end);
int searchForLastOccurence(char str[], char c,int start, int limit);

/* fold long lines into shorter lines (exercise 1-22) */
int main()
{
    int len;
    char line[MAXLEN];
    int startpos = 0;
    int endpos;
    int bPos = -1; /* last blank(tab/space) position, default: -1 */
    int prch = 0; // printed chars
    int total_prch = 0;

    while ((len=getlinee(line, MAXLEN)) > 0 ){
        startpos = 0;
        if (len < WRAPCOLUMN){
            printStrPortion(line, 0, 0);
            continue;
        }
        for (total_prch = 0; total_prch < len ;){
            if (startpos > len)
                break;
            if ((len - total_prch) <= WRAPCOLUMN){
                printStrPortion(line, startpos, 0);
                break;
            }
            endpos = (bPos = searchForLastOccurence(line, ' ', startpos, startpos + WRAPCOLUMN)) > 0 ? bPos : (startpos + WRAPCOLUMN);
            prch = printStrPortion(line, startpos, endpos);
            total_prch+=prch;
            if (line[startpos+prch] != '\n')
                putchar('\n');
            startpos += prch;
        }
    }

    return 0;
}

int getlinee(char buf[], int limit)
{
    int bh = 0, c;
    for (bh = 0; bh < limit-1 && (c=getchar()) != EOF && c != '\n'; ++bh)
        buf[bh] = c;
    if (c == '\n'){
        buf[bh] = c;
        ++bh;
    }
    buf[bh] = '\0';
    return bh;
}
/* prints string portion from buf[start] to buf[end], terminates as soon as buf[end] or '\0' is encountered
 * ASSUMES @buf[@start] is indeed part of @buf[]
 * if end == 0 --> prints chars from start till the string finishes with '\0' (could hang indefinitely! if string is not NUL terminated)
 * returns number of printer chars
 */
int printStrPortion(char buf[], int start, int end)
{
    int i;
    if (end == 0){
        for (i = start; buf[i] != '\0'; ++i)
            putchar(buf[i]);
    }else
        for (i = start; i < end+1 && buf[i] != '\0'; ++i)
            putchar(buf[i]);
    if (buf[i] == '\0')
        putchar('\0');
    return i-start;
}
/* returns last occurence of char c in string str
 * -1: c not found
 */
int searchForLastOccurence(char str[], char c,int start, int limit)
{
    int bh;
    char tmp;
    int cptr = -1;
    // if str[bh] is '\0' then tmp=0 and the for terminates
    for (bh = start; bh < limit+1 && (tmp=str[bh])!='\0' ; ++bh)
        if (tmp == c)
            cptr = bh;
    return cptr;
}
