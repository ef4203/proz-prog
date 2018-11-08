#include <stdio.h>

float factorial_float(int n)
{
    float result = 1;

    for (int c = 1; c <= n; c++)
    {
        result = result * c;
    }

    return result;
}

double factorial_double(int n)
{
    double result = 1;

    for (int c = 1; c <= n; c++)
    {
        result = result * c;
    }

    return result;
}
int main()
{
    float e_float = 1;

    for (int i = 1; i < 100; i++)
    {
        e_float += 1.0 / factorial_float(i);
    }

    printf("e is approx. = %.20f\n", e_float);

    double e_double = 1;

    for (int i = 1; i < 100; i++)
    {
        e_double += 1.0 / factorial_double(i);
    }

    printf("e is approx. = %.20f\n", e_double);
    return 0;
}
