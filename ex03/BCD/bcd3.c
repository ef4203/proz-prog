#include <stdio.h>

int main()
{
    // Declares variables used in this program
    int a = 30, b = 25, x;
    do
    {
        // This is the same as x = a % b
        x = (a - (a / b) * b);
        // Set a to b
        a = b;
        // Set b to x
        b = x;
    } while (b == 0); // Continue as long b is 0

    // Print the result
    printf("%d\n", x);

    return 0;
}
