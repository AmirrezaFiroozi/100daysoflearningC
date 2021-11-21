#include <stdio.h>

/* In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to 
 * write a faster version of bitcount
 */
/* Explain why:
 * x - 1 has the rightmost 1-bit of x cleared and all bits to its right set
 * x & (x - 1) ands the rightmost 1 bit of x with a 0 and clears it
 * and all bits to its right are already 0 so AND ing has no effect on them
 * E.G. x = 0b01101000,
 * x - 1  = 0b01100111,
 * AND -->  0b01100000
 */

unsigned int bitcount(unsigned x);
int main()
{
    printf("%u\n", bitcount(0b011010110001) );

    return 0;
}

/* Counts 1 bits of x */
unsigned int bitcount(unsigned x)
{
    int b = 0;
    for (b = 0; x != 0; x &= (x-1), ++b);
    return b;
}
