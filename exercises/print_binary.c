#include "print_binary.h"

void printBinary(unsigned num)
{
    int bh;
    char buf[sizeof(int)*8 + 1];
    putchar('0');
    putchar('b');
    for (bh = 0; num != 0; num>>=1, ++bh)
        buf[bh] = (num & (01)) ? '1' : '0';
    for (bh = bh - 1; bh >= 0 ; --bh)
        putchar(buf[bh]);
    putchar('\n');
}
