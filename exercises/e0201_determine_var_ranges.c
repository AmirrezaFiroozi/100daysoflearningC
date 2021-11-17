#include <stdio.h>
#include <limits.h>
#include <float.h>

/* determine the ranges of char, short, int, and long variables, both signed and unsigned
 * by printing appropriate values from standard headers
 * and by direct computation
 * determine the ranges of the various floating-types*/

int main()
{
    /* Reading from headers */
    printf("***Reading From Headers***\n");
    printf("char:\tbits: %d, Min: %d, Max: %d\n\tsigned--> Min: %d, Max: %d\n\tunsigned--> Max: %u\n",
            CHAR_BIT, CHAR_MIN, CHAR_MAX, SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
    printf("short:\t Min: %d, Max: %d\n\tunsigned--> Max: %u\n",
            SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("int:\t Min: %d, Max: %d\n\tunsigned--> Max: %u\n",
            INT_MIN, INT_MAX, UINT_MAX);
    printf("long:\t Min: %ld, Max: %ld\n\tunsigned--> Max: %lu\n",
            LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("float:\t Min: %f, Max: %f\n",
            FLT_MIN, FLT_MAX);
    printf("double:\t Min: %f, Max: %f\n",
            DBL_MIN, DBL_MAX);

    /* Computing */
    printf("\n\n***Computing***\n");
    unsigned char c = 0;
    // 0 - 1 in unsigned char will overflow(or underflow?) it and I can get the max unsigned value
    --c;
    printf("char: unsigned--> Max: %u\n\tsigned--> Min: %d, Max: %d\n",
            c, -((c-1)/2 + 1), ((c-1) / 2));
    /* Computing type 2 */
    printf("\n\n***Computing type 2***\n");
    unsigned char t = 0;
    unsigned short sh = 0;
    unsigned int  i = 0;
    unsigned long lo = 0;
    float flt;
    /* fills the variable bits with all 1's giving max value */
    t = (~0);
    sh = (~0);
    i = (~0);
    lo = (~0);
    printf("char: unsigned--> Max: %u\n\tsigned--> Min: %d, Max: %d\n",
            t, -((t-1)/2 + 1), ((t-1) / 2));
    printf("short: unsigned--> Max: %u\n\tsigned--> Min: %d, Max: %d\n",
            sh, -((sh-1)/2 + 1), ((sh-1) / 2));
    printf("int: unsigned--> Max: %u\n\tsigned--> Min: %d, Max: %d\n",
            i, -((i-1)/2 + 1), ((i-1) / 2));
    return 0;
}
