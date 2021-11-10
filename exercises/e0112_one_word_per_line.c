#include <stdio.h>
#include <stdbool.h>

/* print input to output one word per line */
// Ignore multiple spaces; Convert space to newline;
int main(){

int c;
bool wasBlank = false;
while ((c=getchar()) != EOF){
    if (c == '\n') continue;
    if (c == ' ' || c == '\t'){
        wasBlank = true;
        continue;
    }else if(wasBlank == true){
        wasBlank = false;
        putchar('\n');
    }
    putchar(c);
}
putchar('\n');

return 0;
}
