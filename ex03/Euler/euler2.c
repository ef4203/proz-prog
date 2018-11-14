#include <stdio.h>
#include "../common.c"

int main()
{
    // Declares variables used in this program.
    double e, e_tmp;
    int i = 1;

    // Prints the head of the table.
    printf("i  | e\n");
    printf("-----------\n");

    // Starts an infinite loop.
    while (1)
    {
        // Calculates a step of e.
        e += 1 / factorial(i);
        // Prints the result.
        printf("%d  | %.16f\n", i, e);

        // Increases the counter for the e calculation.
        i++;

        // Check if e hasn't changed since last calculation.
        if (e == e_tmp)
            // No changes? break loop.
            break;
        else
            // Changes, continue and set e_tmp for next iteration.
            e_tmp = e;
    }

    return 0;
}
