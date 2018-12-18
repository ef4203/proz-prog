#ifndef __sort_h__
#define __sort_h__

/* Sorts an array with the merge sort algorithm.
 * arr - the array to sort.
 * i   - the start value to sort from.
 * j   - the array length. */
int *merge_sort(int *arr, int i, int j);

/* Sorts an array with the bubble sort algorithm.
 * arr - the array to sort.
 * n   - the array length. */
int *bubble_sort(int *arr, int n);

#endif
