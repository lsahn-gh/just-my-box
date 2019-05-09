#include <stdio.h>
#include <stdlib.h>

void
print_array (int *arr, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void
swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int
partition (int *arr, int low, int high)
{
    int pivot;

    /* least points to the index of the last elem which is less than pivot */
    int least;
    /* j goes through whole elements until high-1 */
    int j;

    pivot = arr[high];
    least = low-1;

    for (j = low; j <= high-1; j++) {

        if (arr[j] <= pivot) {
            least++;
            if (least != j)
                swap (arr+least, arr+j);
        }
    }
    swap (arr+least+1, arr+high);

    return least+1;
}

void
quick_sort (int *arr, int low, int high)
{
    /* Ascending order */
    /* https://www.geeksforgeeks.org/quick-sort/ */
    
    int pi;

    if (low >= high)
        return;
    
    /* The element of the array in pi index is now at the correct position */
    pi = partition (arr, low, high);
    quick_sort (arr, low, pi-1);
    quick_sort (arr, pi+1, high);
}

int
main (int argc, char *argv[])
{
    int unordered_array[] = { 5, 10, 10, 4, 2, 8, 3, 100, 53, 1, 40 };
    int len = sizeof(unordered_array)/sizeof(unordered_array[0]);

    print_array (unordered_array, len);
    quick_sort (unordered_array, 0, len-1);
    print_array (unordered_array, len);

    return 0;
}
