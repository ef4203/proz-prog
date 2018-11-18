#include <stdio.h>
#include <math.h>
#include "common.c"

double my_arctan(double x)
{
    double result, result_tmp;
    int k = 0;

    if (x > 1 || x < -1)
        return 0;

    while (1)
    {
        result += power(-1, k) * (power(x, 2 * k + 1) / (2 * k + 1));

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
    printf("my_arctan(0.5)\t= %.10f\n", my_arctan(0.5));
    printf("atan(0.5)\t= %.10f\n", atan(0.5));

    return 0;
}
