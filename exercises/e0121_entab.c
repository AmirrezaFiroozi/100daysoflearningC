#include <stdio.h>

#define TS   8
#define TAB_WEIGHT (TS - (pos%TS)) /* takes this many character to get to the next tabstop */
/* replace strings of blanks by the minimum number of tabs and blanks to achieve the same spacing */
/*
 * It removes spaces and uses tabs and spaces to get the output to look like the input
 * It doesn't calculate tabs --> spaces though and can be buggy when spaces and tabs are used together to form blanks
 */
int main()
{
    int c, pos;
    int space_count = 0;

    pos = 0;
    while((c=getchar())!=EOF){
        if (c == '\n'){
            pos = 0;
            continue;
        }
        if (c == '\t'){
            pos += (TAB_WEIGHT);
            putchar(c);
        }
        else if (c == ' ')
            ++space_count;
        else{
            // read non blank char
            while (space_count > 0){
                if(space_count >= TAB_WEIGHT && space_count != 1){
                    putchar('\t');
                    space_count -= TAB_WEIGHT;
                    pos += TAB_WEIGHT;
                }else{
                    for (; space_count > 0; --space_count){
                        putchar(' ');
                        ++pos;
                    }
                }
            }

            ++pos;
            putchar(c);
        }
    }
    putchar('\n');


    return 0;
}
