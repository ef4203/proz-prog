#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

double my_sin(double x)
{
    double result, result_tmp, k = 0;

    while (1)
    {
        result += pow(-1, k) * (pow(x, 2 * k + 1) / factorial(2 * k + 1));

        k++;

        if (result == result_tmp)
            break;
        else
            result_tmp = result;
    }
    return result;
}

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

double my_log(double x)
{
    double result, result_tmp, k = 1;

    while (1)
    {
        /* There's something broken here */
        result += pow(-1, k + 1) * (pow(x - 1, k) / k);

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
    printf("sin(2)\t\t= %.10f\n\n", sin(2));

    printf("my_arctan(0.5)\t= %.10f\n", my_arctan(0.5));
    printf("atan(0.5)\t= %.10f\n\n", atan(0.5));

    printf("my_log(1.4)\t= %.10f\n", my_log(1.4));
    printf("log(1.4)\t= %.10f\n", log(1.4));

    return 0;
}
