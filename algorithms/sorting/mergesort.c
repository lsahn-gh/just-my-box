/*
 * Time-complexity reference
 * https://stackoverflow.com/a/38795968
 */

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
merge (int *arr, int l, int m, int r)
{
    /* Use C99's VLA */
    int temp[r-l+1];
    int temp_cnt = 0;
    int i;
    int left = l, mid = m, right = r;
    int left_end = mid-1;

    while (left <= left_end && mid <= right) {
        if (arr[left] < arr[mid]) {
            temp[temp_cnt] = arr[left];
            left++;
        } else {
            temp[temp_cnt] = arr[mid];
            mid++;
        }
        temp_cnt++;
    }

    while (left <= left_end) {
        temp[temp_cnt] = arr[left];
        left++;
        temp_cnt++;
    }

    while (mid <= right) {
        temp[temp_cnt] = arr[mid];
        mid++;
        temp_cnt++;
    }

    left = l;
    right = r;

    for (i = 0; i < temp_cnt; left++, i++) {
        arr[left] = temp[i];
    }
}

void
merge_sort (int *arr, int l, int r)
{
    /* Ascending order */
    int mid;

    if (r <= l)
        return;
    
    mid = (int)((l+r)/2.0);
    merge_sort (arr, l, mid);
    merge_sort (arr, mid+1, r);
    merge (arr, l, mid+1, r);
}

int
main (int argc, char *argv[])
{
    int unordered_array[] = { 5, 10, 4, 2, 8, 3, 100, 53, 1 };
    int len = sizeof(unordered_array)/sizeof(unordered_array[0]);

    print_array (unordered_array, len);
    merge_sort (unordered_array, 0, len-1);
    print_array (unordered_array, len);

    return 0;
}
