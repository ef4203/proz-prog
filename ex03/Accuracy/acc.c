#include <stdio.h>

int main()
{
    // Declares variables used in the program.
    double y = 0.0;

    for (double i = 1.0; i < 1000000000000; i *= 10)
    {
        y += 1.0 / i;
    }

    printf("y is approx.: %.20f\n", y);

    return 0;
}
