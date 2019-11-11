#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Entry point of the program. */
int main(int argc, char *argv[])
{
    /* Exit if there's no argument. */
    if (argc < 2)
        return 0;

    /* Save the number to convert into a temporary variable.*/
    uint16_t x = atoi(argv[1]);

    /* Initialize a string for the result. */
    char result[] = "0000000000000000\0";

    /* Loop through each bit of a binary number. */
    for (int i = 15; i >= 0; i--)
    {
        /* Set the current bit to 2^i. */
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
    printf("%s\n", result);
    return 0;
}
