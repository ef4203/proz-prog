#include <math.h>
#include <stdio.h>

int main()
{
    double e;
    int i = 1;

    do
    {
        /* Set e to 1 / 2^i. */
        e = 1.0 / pow(2, i);
        /* Print the result. */
        printf("%d\t%.20f\n", i++, e);
    } while (1 + (e / 2) > 1);

    /* Print the final accurary of the data type. */
    printf("1 + ((1 / 2 ^ %d ) / 2) == 1\n", i);
    return 0;
}
