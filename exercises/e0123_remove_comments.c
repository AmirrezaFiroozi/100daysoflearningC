#include <stdio.h>

// INCOMPLETE -- ONLY OUTLINED FOR NOW

/* Remove all comments from a C program
 * Handle quoted strings and character constants properly
 * C comments do NOT nest
 */

int main()
{
    // read line
    // find comment start
    // find comment end
    // print line excluding comment_start to comment_end


    return 0;
}

/* Print str from str[0] to str[limit] exclude str[ex_start] to str[ex_end]
 * ex_start <= ex_end <= limit
 * 
 */
void printStrExcludingRange(char str[], int ex_start, int ex_end, int limit)
{
    int bh;
    char c;
    for (bh = 0; bh < limit+1 && (c=str[bh])!='\0'; ++bh){
        if (bh >= ex_start && bh <= ex_end)
            continue;
        putchar(c);
    }
}

/*
 * Searches from str[start] to str[limit]
 * Returns pos where str[pos] is the beginning of a comment
 * -1 : No Comment found
 */
int findCommentStart(char str[], int start, int limit)
{
    int bh = -1;
    char c;

    return bh;
}

/*
 * Searches from str[start] to str[limit]
 * Returns pos where str[pos] is the end of a comment
 * -1 : No Comment found
 */
int findCommentEnd(char str[], int start, int limit)
{
    int bh = -1;
    char c;

    return bh;
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

    return type;
}
