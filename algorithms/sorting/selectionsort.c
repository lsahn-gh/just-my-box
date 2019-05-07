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
selection_sort (int *arr, size_t len)
{
    /* Ascending order */
    size_t i, j;

    for (i = 0; i < len-1; i++) {
        size_t least_index = i;
        for (j = i+1; j < len; j++) {
            if (arr[j] < arr[least_index])
                least_index = j;
        }
        if (least_index != i) {
            int tmp = arr[i];
            arr[i] = arr[least_index];
            arr[least_index] = tmp;
        }
    }
}

int
main (int argc, char *argv[])
{
    int unordered_array[] = { 5, 10, 4, 2, 8, 3, 100, 53, 1 };
    size_t len = sizeof(unordered_array)/sizeof(unordered_array[0]);

    print_array (unordered_array, len);
    selection_sort (unordered_array, len);
    print_array (unordered_array, len);

    return 0;
}
