#include <stdio.h>
#include "print_binary.h"

/* Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions
 */

unsigned rightrot(unsigned x, unsigned n);
int main()
{

    printBinary(rightrot(0b100011001, 6));
    return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
    printBinary(x);
    unsigned rotbits = (x & ~(~0 << n));
    x = (x >> n) | (rotbits << (sizeof(unsigned)*8 - n));
    return x;
}
