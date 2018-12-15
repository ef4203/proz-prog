#include <stdio.h>
#include "sort.h"

void set_array_size()
{
    printf("SET ARRAY SIZE\n");
}

void input_number()
{
    printf("INPUT NUMBER\n");
}

void generate_random_number()
{
    printf("GENERATE RANDOM NUM\n");
}

void bubble_sort_array()
{
    printf("BUBBLE SORT\n");
}

void merge_sort_array()
{
    printf("MERGE SORT\n");
}

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
