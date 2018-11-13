#include <stdio.h>
#include "../common.c"

int main()
{
    // Declares variables used in the program.
    float e, x;
    int i = 1;

    // Start a loop.
    do
    {
        // Calculate the step.
        x = 1 / factorial(i); // This function comes from common.c
        // Add step to e.
        e += x;
        // Increase step counter.
        i++;
    } while (x > 0); // Until x is 0.

    // Print the result.
    printf("e is approx.: %.16f\n", e);

    return 0;
}
