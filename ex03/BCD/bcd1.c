#include <stdio.h>
#include <math.h>

int main()
{
    // Declares variables used in this program
    int a = 30, b = 25, x;

    do
    {
        // Set x to the absolute value of a - b
        x = abs(a - b);

        // Replace the largest value with x
        if (a > b)
            a = x;
        else
            b = x;

    } while ((a != 0) && (b != 0)); // Do this as long no value is 0

    // Print the result
    printf("%d\n", a != 0 ? a : b);

    return 0;
}
