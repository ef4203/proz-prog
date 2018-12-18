#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

/* The array on which should be operated on */
int *array;

/* Global array size. */
int arraySize;

/* Prints the current state of the array. */
void print_array()
{
    printf("Your current array is: [");

    for (int i = 0; i < arraySize; i++)
    {
        printf(" %d,", array[i]);
    }

    printf("] \n");
}

int main()
{
    int exit_flag = 0;

    srand(time(NULL));

    while (!exit_flag)
    {
        printf("1) Set array size\t\t\t4) Bubble sort\n");
        printf("2) Input an array\t\t\t5) Merge sort\n");
        printf("3) Generate random array\t\t6) Exit\n\n");
        printf("> ");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {

        case 1:
            /* Set the array size. */
            printf("Enter a array size: ");
            scanf("%d", &arraySize);
            break;

        case 2:
            /* Input an array. */
            array = malloc(sizeof(int) * arraySize);
            int c;

            for (int i = 0; i < arraySize; i++)
            {
                printf("Enter number for pos. %d: ", i + 1);
                scanf("%d", &c);
                array[i] = c;
            }

            print_array();
            break;

        case 3:
            /* Generate a random array. */
            array = malloc(sizeof(int) * arraySize);

            for (int i = 0; i < arraySize; i++)
            {
                array[i] = rand() % 20;
            }

            print_array();
            break;

        case 4:
            /* Bubble sort the current array. */
            array = bubble_sort(array, arraySize);
            print_array();
            break;

        case 5:
            /* Merge sort the current array. */
            array = merge_sort(array, 0, arraySize - 1);
            print_array();
            break;

        case 6:
            /* Exit the program. */
            exit_flag = 1;
            break;

        default:
            /* Default case. */
            break;
        }
    }
    return 0;
}
