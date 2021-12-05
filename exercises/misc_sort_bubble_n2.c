#include <stdio.h>
#include <stdbool.h>

#define ARRSIZE  8
/* bubble sort */
int main(void)
{
    int arr[ARRSIZE] = {6, 3, 8, 5, 2, 7, 4, 1};//{1, 2, 3, 4, 5, 6, 7, 8}; //{6, 3, 8, 5, 2, 7, 4, 1};

    int i, j;
    int tmp;
    bool swapped;

    for (i = ARRSIZE - 1; i >= 0; i--){
        swapped = false;
        for (j = 0; j < i; j++){
            /* search from arr[0] to arr[i] */
            if (arr[j] > arr[j + 1]){
                /* if the element with lower index is larger swap the two elements */
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) /* if did not swap anything then the array must be already sorted */
            break;
    }
    printf("It took %d iteration%c to sort the array\n", ARRSIZE - i, (ARRSIZE - i) > 1 ? 's' : '\0');

    /* print out the array */
    for (i = 0; i < ARRSIZE; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}
