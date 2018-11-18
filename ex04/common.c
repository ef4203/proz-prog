#include <stdio.h>

double power(double a, int b)
{
    double r = a;
    int negative_expnonent_flag = 0;

    if (b == 0)
        return 1;
    else if (b < 0)
    {
        negative_expnonent_flag = 1;
        b *= -1;
    }

    for (int i = 1; i < b; i++)
    {
        r *= a;
    }

    if (negative_expnonent_flag)
        return 1 / r;
    else
        return r;
}

double factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
