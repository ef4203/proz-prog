#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/* The array on which should be operated on */
int *array;

int arraySize;

void print_array()
{
    printf("PRINTING ARRAY\n");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n END OF ARRAY\n");
}

void generate_random_number()
{
    // TODO: generate a random array
    printf("GENERATE RANDOM NUM\n");
}

void bubble_sort_array()
{
    // TODO: sort the array with bubble sort, and call print_array()
    printf("BUBBLE SORT\n");
}

void merge_sort_array()
{
    // TODO: merge sort the array, and call print_array()
    printf("MERGE SORT\n");
}

// TODO: print_array()

// TODO: array_from_string()

int main()
{
    int exit_flag = 0;

    while (!exit_flag)
    {
        //system("clear");
        printf("1) Set array size\t\t\t4) Bubble sort\n");
        printf("2) Input a number\t\t\t5) Merge sort\n");
        printf("3) Generate random number\t\t6) Exit\n\n");
        printf("> ");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {

        case 1:
            printf("Enter a array size: ");
            scanf("%d", &arraySize);
            break;

        case 2:
            array = malloc(sizeof(int) * arraySize);
            int c;

            for (int i = 0; i < arraySize; i++)
            {
                printf("Enter number for pos. %d ", i + 1);
                scanf("%d", &c);
                array[i] = c;
            }

            print_array();
            break;

        case 3:
            generate_random_number();
            break;

        case 4:
            bubble_sort_array();
            break;

        case 5:
            merge_sort_array();
            break;

        case 6:
            exit_flag = 1;
            break;

        default:
            break;
        }
    }
    return 0;
}
