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
insertion_sort (int *arr, size_t len)
{
    /* Ascending order */
    int i, j;

    for (i = 1; i < len; i++) {
        int val = arr[i];
        for (j = i; arr[j-1] > val && j >= 1; j--) {
            /* Right-shifting */
            arr[j] = arr[j-1];
        }
        if (j != i)
            arr[j] = val;
    }
}

int
main (int argc, char *argv[])
{
    int unordered_array[] = { 5, 10, 4, 2, 8, 3, 100, 53, 1 };
    size_t len = sizeof(unordered_array)/sizeof(unordered_array[0]);

    print_array (unordered_array, len);
    insertion_sort (unordered_array, len);
    print_array (unordered_array, len);

    return 0;
}
