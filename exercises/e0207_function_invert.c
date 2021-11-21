#include <stdio.h>
#include "print_binary.h"

/* Write a function invert(x, p, n) that returns x with the n bits
 * that begin at position p inverted (1 --> 0, 0 --> 1) leaving
 * the others unchanged
 */

unsigned invert(unsigned x, unsigned p, unsigned n);
int main()
{
    printBinary(invert(0b100101010100, 8, 7));
    return 0;
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
//    printBinary(x);
    unsigned mask = ~(~0 << n) << (p+1-n);
    x ^= mask;
    return x;
}
