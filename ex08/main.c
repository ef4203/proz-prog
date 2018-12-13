#include <stdio.h>

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

void bubble_sort()
{
    printf("BUBBLE SORT\n");
}

void merge_sort()
{
    printf("MERGE SORT\n");
}

int main()
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
        bubble_sort();
        break;

    case 5:
        merge_sort();
        break;

    case 6:
        return 0;
        break;

    default:
        break;
    }

    return 0;
}
