#include <stdio.h>
#include <math.h>
#include "common.c"

double my_sin(double x)
{
    double result, result_tmp, k = 0;

    while (1)
    {
        result += power(-1, k) * (power(x, 2 * k + 1) / factorial(2 * k + 1));

        k++;

        if (result == result_tmp)
            break;
        else
            result_tmp = result;
    }
    return result;
}

int main()
{
    printf("my_sin(2)\t= %.10f\n", my_sin(2));
    printf("sin(2)\t\t= %.10f\n", sin(2));

    return 0;
}
