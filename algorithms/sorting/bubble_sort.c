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
bubble_sort (int *arr, size_t len)
{
    /* Ascending order */
    size_t i, j;

    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int
main (int argc, char *argv[])
{
    int unordered_array[] = { 5, 10, 4, 2, 8, 3, 100, 53, 1 };
    size_t len = sizeof(unordered_array)/sizeof(unordered_array[0]);

    print_array (unordered_array, len);
    bubble_sort (unordered_array, len);
    print_array (unordered_array, len);

    return 0;
}