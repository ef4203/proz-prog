#include <stdio.h>

double factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    float e, x;
    int i = 1;

    do
    {
        x = 1 / factorial(i);
        e += x;
        i++;
    } while (x > 0);

    printf("e is approx.: %.16f\n", e);

    return 0;
}
