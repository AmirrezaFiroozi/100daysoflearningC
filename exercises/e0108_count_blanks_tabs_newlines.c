#include <stdio.h>

/* Count blanks, tabs, and lines */
int main(){

int c;
int blanks = 0, tabs = 0, lines = 0;
while ((c=getchar()) != EOF)
    if (c == ' ') ++blanks;
    else if (c == '\t') ++tabs;
    else if (c == '\n') ++lines;

printf("\nBlanks:%d, Tabs:%d, Lines:%d\n", blanks, tabs, lines);



return 0;
}
