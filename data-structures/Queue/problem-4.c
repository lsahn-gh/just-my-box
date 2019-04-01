/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Queue
 * Problem : No. 4
 * 
 * Maximum sum in sliding window: Given array A[] with sliding window of size 
 * w which is moving from the very left of the array to the very right. Assume that we can
 * only see the w numbers in the window. Each time the sliding window moves rightwards by
 * one position. For example: The array is [1 3 -1 -3 5 3 6 7], and w is 3.
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 9
#define W 3
#define BLEN LEN-W+1

int
main (void)
{
    int A[LEN] = {1, 3, -1, 10, -3, 5, 3, 6, 7};
    int B[BLEN];
    int i, j;

    for (i = 0; i < BLEN; i++) {
        int max = A[i];
        for (j = i+1; j < i+W; j++) {
            if (A[j] > max)
                max = A[j];
        }
        B[i] = max;
    }

    for (i = 0; i < BLEN; i++)
        printf ("%d ", B[i]);
    printf ("\n");

    return 0;
}