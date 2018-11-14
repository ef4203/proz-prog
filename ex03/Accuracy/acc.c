#include <stdio.h>

int main()
{
    // Declares variables used in the program.
    float y = 1;

    // Start a loop.
    do
    {
        y = 1 + (y / 2);
    } while (y > 1); // Until x is 0.

    // Print the result.
    printf("y is approx.: %.16f\n", y);

    return 0;
}
