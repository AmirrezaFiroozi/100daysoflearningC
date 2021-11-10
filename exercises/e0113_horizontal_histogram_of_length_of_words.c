#include <stdio.h>
#include <stdbool.h>

#define MAXLENGTH 20
#define MAXARRAYINDEX (MAXLENGTH + 1)
#define HISTOGRAM_CHAR '#'
/* print a histogram of the length of words (up to MAXLENGTH characters) in the input */
int main(){

/*
 * frequency[0] --> frequency of spaces
 * frequency[1] --> frequency of one-char words
 * frequency[2] --> frequency of two-char words
 * ...
 * */
int frequency[MAXLENGTH+1];
int currentWordLength = 0;
int c, i, j;

for (i = 0; i < MAXARRAYINDEX; ++i)
    frequency[i] = 0;

// If current char is not (' ' or '\n' or '\t') increment length counter
// If current char is one of the above, increment frequency[currentWordLength], and reset word length counter

while ((c=getchar()) != EOF){
    if (!(c == ' ' || c == '\n' || c == '\t')){
        ++currentWordLength;
    }else{
        ++frequency[0];
        if (currentWordLength <= MAXARRAYINDEX)
            ++frequency[currentWordLength];
        currentWordLength = 0;
    }
}

/* frequency[0] is spaces/newlines/tabs frequency so I skip it */
for (i = 1; i < MAXARRAYINDEX; ++i){
    printf("l:%d f:%d ", i, frequency[i]);
    for (j = 0; j < frequency[i]; ++j)
        putchar(HISTOGRAM_CHAR);
    if(frequency[i] != 0)
        putchar('\n');
}

return 0;
}
