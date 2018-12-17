#include <stdio.h>
#include "sort.h"

/* The array on which should be operated on */
int *array;

void set_array_size()
{
    // TODO: malloc/clear on array
    printf("SET ARRAY SIZE\n");
}

void input_number()
{
    // TODO: scanf for string, call array_from_string()
    printf("INPUT NUMBER\n");
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
        printf("1) Set array size\t\t\t4) Bubble sort\n");
        printf("2) Input a number\t\t\t5) Merge sort\n");
        printf("3) Generate random number\t\t6) Exit\n\n");
        printf("> ");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {

        case 1:
            set_array_size();
            break;

        case 2:
            input_number();
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
