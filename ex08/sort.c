#include "sort.h"

/* Swaps two values. */
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Sorts an array with the bubble sort algorithm. */
int *bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) /* Last i elements are already in place. */
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    return arr;
}

/* Merges two lists. */
void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[50]; // array used for merging
    int i = i1;   // beginning of the first list
    int j = i2;   // beginning of the second list
    int k = 0;

    while (i <= j1 && j <= j2) // while elements in both lists
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= j1) // copy remaining elements of the first list
        temp[k++] = a[i++];

    while (j <= j2) // copy remaining elements of the second list
        temp[k++] = a[j++];

    /* Transfer elements from temp[] back to a[] */
    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}

/* Sorts an array with the merge sort algorithm. */
int *merge_sort(int arr[], int i, int j)
{
    if (i < j)
    {
        int mid = (i + j) / 2;
        merge_sort(arr, i, mid);        // left recursion
        merge_sort(arr, mid + 1, j);    // right recursion
        merge(arr, i, mid, mid + 1, j); // merging of two sorted sub-arrays
    }

    return arr;
}
