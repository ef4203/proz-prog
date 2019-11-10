#define CONVERT 3019
#include <math.h>
#include <stdint.h>
#include <stdio.h>

/* Entry point of the programm. */
int main()
{
    /* Save the to int to convert into a temporary variable */
    uint16_t x = CONVERT;
    /* Initialize a string for the result. */
    char result[] = "0000000000000000\0";

    /* Loop through each bit of the binary number. */
    for (int i = 15; i >= 0; i--)
    {
        /* Se the current bit to 2^i. */
        int bit = pow(2, i);
        /* Check if the temporary number is greater
         * or equal to the current bit. */
        if (x >= bit)
        {
            /* Substract the value of the bit from the
             * temporary variable. */
            x -= bit;
            /* Set the bit in the binary number to 1. */
            result[15 - i] = '1';
        }
    }

    /* Print the result. */
    printf("%d in binary is %s\n", CONVERT, result);
    return 0;
}
