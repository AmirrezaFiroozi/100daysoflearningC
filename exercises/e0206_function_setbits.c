#include <stdio.h>
#include "print_binary.h"

/* Write function setbits(x, p, n, y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y
 * leaving other bits unchanged 
 */

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);
void printBinary(unsigned num);

int main()
{
    printBinary(setbits(0b1100100011, 6, 4, 0b1001));
    return 0;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned mask = ~(~0 << n); // rightmost n bits mask
    x &= ~(mask << (p+1-n)); // clear n bits of x starting from position p 
    x |= (y & mask) << (p+1-n); // get rightmost n bits of y, shift to position p, set those bits in x
    return x;
}
