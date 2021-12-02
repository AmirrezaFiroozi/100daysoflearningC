#include <stdio.h>
#include <ctype.h>

/* Extend atof to handle scientific notation of the form 123.45e-6 */

double atof(char s[]);
double pw(double b, double e);
int main()
{
    printf("%g\n", atof("123.45E-10"));
    return 0;
}

double atof(char s[])
{
    int i, sign, esign;
    double val, dp, exp; /* value, decimal point, exponent */

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1; /* record sign */
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (dp = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        dp *= 10.0;
    }
    if (s[i] == 'E' || s[i] == 'e')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (exp = 0.0; isdigit(s[i]); i++)
        exp = exp * 10.0 + (s[i] - '0');
    exp = pw(10, exp * esign);
    /* could use <math.h> and link -lm
     * exp = pow(10, exp * esign);
     * and probably should!
     * I just wanted to write a quick and dirty pw function as well
    */
    return sign * val * exp / dp;
}
/* raise b to the e th power
 * e must belong to Z (..., -2, -1, 0, 1, 2, ...)
 */
double pw(double b, double e)
{
    if (b == 0)
        return 0;
    double d = 1.0;
    if (e < 0){ /* deal with negative exponent */
        b = (1/b);
        e = -e;
    }
    for (; e > 0; --e)
        d *= b;

    return d;
}
