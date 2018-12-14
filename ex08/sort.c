#include "sort.h"

/* Sorts an array with the bubble sort algorithm. */
int *bubble_sort(int *source)
{
    int arrayLength = sizeof(source) / sizeof(int);

    for (int c = 0; c < arrayLength - 1; c++)
    {
        for (int d = 0; d < arrayLength - c - 1; d++)
        {
            if (source[d] > source[d + 1])
            {
                source[d] = source[d + 1];
                source[d + 1] = source[d];
            }
        }
    }

    return source;
}

/* Sorts an array with the merge sort algorithm. */
int *merge_sort(int *source)
{
    return source;
}

/* Merges two lists. */
int *merge(int *a, int *b)
{
    return a;
}
