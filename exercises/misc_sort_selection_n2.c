#include <stdio.h>

#define ARRSIZE  8
/* selection sort */
/* I watched a human sort numbers (CS50 - lecture03) and nailed this on the first attempt! */
int main(void)
{
    int arr[ARRSIZE] = {6, 3, 8, 5, 2, 7, 4, 1};

    int minp, i, j;
    int tmp;

    for (i = 0; i < ARRSIZE; i++){
        for (j = i, minp = j; j < ARRSIZE; j++){
            if (arr[j] < arr[minp])
                minp = j; /* remember the position of the smallest number */
        }
        /* swapping */
        tmp = arr[i];
        arr[i] = arr[minp];
        arr[minp] = tmp;
    }

    /* print out the array */
    for (i = 0; i < ARRSIZE; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}
