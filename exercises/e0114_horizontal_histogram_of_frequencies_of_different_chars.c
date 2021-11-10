#include <stdio.h>

#define ASCII_CHAR_COUNT 255
#define ARRAYMAXINDEX   (ASCII_CHAR_COUNT + 1)
#define HISTOGRAM_CHAR '#'

/* print a horizontal histogram of frequencies of different chars */
int main(){

int c, i, j;
int ascii_freq[ARRAYMAXINDEX];

for (i = 0; i < ARRAYMAXINDEX; ++i)
    ascii_freq[i] = 0;

while ((c=getchar()) != EOF)
    if (c < ASCII_CHAR_COUNT)
        ++ascii_freq[c];

for (i = 0; i < ARRAYMAXINDEX; ++i){
    if (ascii_freq[i] == 0) continue;
    switch (i){
        case '\t':
            printf("'\\t'");
            break;
        case '\n':
            printf("'\\n'");
            break;
        case ' ':
            printf("space");
            break;
        default:
            printf("'%c'", i);
    }
    printf(" f:%d ", ascii_freq[i]);
    for (j = 0; j < ascii_freq[i]; ++j)
        putchar(HISTOGRAM_CHAR);
    putchar('\n');
}


return 0;
}
