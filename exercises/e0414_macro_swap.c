#include <stdio.h>

/* define a macro swap(t, x, y) that interchanges two arguments of type t. */
#define swap(t, x, y) { t tmp = x; \
                         x = y; \
                        y = tmp; }

int main(void)
{
    char *s = "str1";
    char *t = "str2";
    printf("s: %s, t: %s\n", s, t);
    swap(char *, s, t);
    printf("s: %s, t: %s\n", s, t);

    int n1 = 10;
    int n2 = 23;
    printf("n1: %i, n2: %i\n", n1, n2);
    swap(int, n1, n2);
    printf("n1: %i, n2: %i\n", n1, n2);

    return 0;
}
