#include <stdio.h>

/* convert tabs to \t backspaces to \b and \ to \\ */
int main(){

int c;
while ((c=getchar()) != EOF){
    if (c == '\t') printf("\\t");
    else if (c == '\b') printf("\\b");
    else if (c == '\\') printf("\\");
    else putchar(c);

}


return 0;
}
