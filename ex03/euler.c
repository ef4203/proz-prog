#include <stdio.h>

/* Helper function for calculating n factorial. */
double factorial(unsigned int n)
{
    return n <= 1 ? (double)1 : (double)n * factorial(n - 1);
}

int main()
{
    double e = 0.0, e_tmp = 0.0;
    int i = 1;

    printf("i\t| e\n----------------------------\n");

    do
    {
        e_tmp = e;
        /* Add 1 / i! to e. To approach e. */
        e += 1 / factorial(i++);
        printf("%d\t| %.16f\n", i, e);
    } while (e != e_tmp); /* Do this until there's no more change in e. */

    return 0;
}
