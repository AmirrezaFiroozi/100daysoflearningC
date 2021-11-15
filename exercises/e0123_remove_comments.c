#include <stdio.h>
#include <stdbool.h>

// Works. cannot work with multiple comments in the same line like below
/* this is a comment */ /* this is another comment */ // this is the last comment
/* What is working:
 * Removes the first comment it encounters! but not the subsequent ones in the same line 
 *
 */

#define MAXLEN  1000
/* Remove all comments from a C program
 * Handle quoted strings and character constants properly
 * C comments do NOT nest
 */

int getlinee(char str[], int limit);
void printStrExcludingRange(char str[], int ex_start, int ex_end, int limit);
void printStr(char str[]);
int findCommentStart(char str[], int start, int limit);
int findCommentEnd(char str[], int start, int limit, int type);
int detectCommentType(char str[], int pos);
int howmanyCommentStarts(char str[]);

int main()
{
    // read line
    // find comment start
    // find comment end
    // print line excluding comment_start to comment_end
    /*
     * If it looks like this code is unnecessarily verbose,
     * I had to write it this way to debug easily :|
     * A quick refactoring would probably solve it and make it concise
     * but I'm not in the mood now
     */
    printf("Testing comments /* inside a quoted string */ this portion should not be deleted\n");
    int len;
    char line[MAXLEN];
    int comStart = -1;
    int comEnd = -1;
    int comType = -1;
    bool dealtWithPreviousComment = true;
    while ((len=getlinee(line, MAXLEN)) > 0){ // testing in line comment
        comStart = findCommentStart(line, 0, len);
        if (comStart != -1){
            // this line has comment beginning sequence
            comType = detectCommentType(line, comStart);
            comEnd = findCommentEnd(line, comStart, len, comType);
            printStrExcludingRange(line, comStart, comEnd, len);
            if (comType == 1){
                // this type of comment is 1 single line comment
                dealtWithPreviousComment = true;
            }else if (comType == 2) {
                /* this type of comment is 2. could be multiline or singleline */
                if (comEnd == -1)
                    dealtWithPreviousComment = false;
                else{
                    // To fill!
                    // comment end in this line. maybe other comment starts here?
                    // search for comStart start from after the end of the previous comment
                }
            }
        }else{
            // this line doesn't have comment beginning sequnece
            if (! dealtWithPreviousComment){
                // deal with previous comment
                // comType always 2?
                comEnd = findCommentEnd(line, 0, len, comType);
                printStrExcludingRange(line, 0, comEnd, len);
                if (comEnd != -1)
                    dealtWithPreviousComment = true;
            }else{
                // Normal line. not part of any comment
                printStr(line);
            }

        }

    }

    return 0;
}

int getlinee(char str[], int limit)
{
    int bh;
    char c;
    for (bh = 0; bh < limit-1 && (c=getchar())!=EOF && c!='\n'; ++bh)
        str[bh] = c;
    if (c == '\n'){
        str[bh] = c;
        ++bh;
    }
    str[bh] = '\0';
    return bh;
}

/*
 * print NUL terminated str
 */
void printStr(char str[])
{
    int bh;
    for (bh = 0; str[bh]!='\0'; ++bh)
        putchar(str[bh]);
}
/* Print str from str[0] to str[limit] exclude str[ex_start] to str[ex_end]
 * ex_start <= ex_end <= limit
 *
 * ex_end == -1 --> ( delete from ex_start to limit; print the rest)
 * ex_start == -1 --> (delete from 0 to ex_end; print the rest)
 * 
 */
void printStrExcludingRange(char str[], int ex_start, int ex_end, int limit)
{
    int bh;
    char c;
    if (ex_end == -1)
        ex_end = limit;
    for (bh = 0; bh < limit && (c=str[bh])!='\0'; ++bh){
        if (bh >= ex_start && bh <= ex_end)
            continue;
        putchar(c);
    }
}

/*
 * Searches from str[start] to str[limit]
 * Returns pos where str[pos] is the beginning of a comment
 * max(pos) --> limit-1
 * -1 : No Comment found
 */
int findCommentStart(char str[], int start, int limit)
{
    int bh = start;
    char c;
    int dquotecount = 0;
    for (bh = start; bh < limit-1 && (c=str[bh])!='\0' ; ++bh){
        if (c == '\"')
            ++dquotecount;
        else if (c == '/'){
            if ((dquotecount % 2) == 0 && (str[bh+1] == '/' || str[bh+1] == '*'))
                break;
        }
    }
    if (str[bh] != '/')
        bh = -1;

    return bh;
}

/*
 * Searches from str[start] to str[limit]
 * Returns pos where str[pos] is the end of a comment
 * PRESUMES THERE IS A COMMENT! 
 */
int findCommentEnd(char str[], int start, int limit, int type)
{
    int bh = start;
    char c;
    for (bh = start; bh < limit && (c=str[bh])!='\0'; ++bh)
        if (type == 1){
            if (c == '\n')
                return bh-1;
        }else if (type == 2){
            if (c == '/' && str[bh-1] == '*')
                return bh;
        }
    return -1;
}

/*
 * detects comment type
 * 1      "//" style comment
 * 2      * / style comment
 * -1     No comment
 */
int detectCommentType(char str[], int pos)
{
    int type = -1;
    if (str[pos] == '/'){
        if (str[pos+1] == '/')
            type = 1;
        else if (str[pos+1] == '*')
            type = 2;
    }

    return type;
}

