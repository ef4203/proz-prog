#include <stdio.h>
#include <math.h>

double my_arctan(double x)
{
    double result, result_tmp, k = 0;

    if (x > 1 || x < -1)
        return 0;

    while (1)
    {
        result += pow(-1, k) * (pow(x, 2 * k + 1) / (2 * k + 1));

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
