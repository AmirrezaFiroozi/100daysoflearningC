#include <stdio.h>

/* Our binary search makes two tests inside the loop when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and masure the difference in run-time
 */
/* I am not satisfied with this. I don't think I've done anything here
 * I could not think of anything; I just moved the test inside while
 */
#define SEARCHFOR   7

int binsearch(int x, int v[], int n);
int main()
{
    int v[12] = { 3, 7, 12, 13, 20, 28, 30, 31, 32, 51, 53, 70};
    int x = SEARCHFOR;
    printf("v[%d] = %d\n",binsearch(x, v, 12), x);

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low = 0, mid, high = n - 1;
    while (low <= high && x != v[mid]){
        mid = (high + low) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ((x == v[mid]) ? mid : -1);

}
