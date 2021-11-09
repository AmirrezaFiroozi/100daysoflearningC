#include <stdio.h>
#include <stdbool.h>

/* remove extra spaces */
int main(){

int c;
bool wasBlank = false;
while ((c = getchar()) != EOF){
    if (c == ' '){
        wasBlank = true;
        continue;
    }
    else if (wasBlank == true) {
        wasBlank = false;
        putchar(' ');
    } 
    putchar(c);
}

return 0;
}
