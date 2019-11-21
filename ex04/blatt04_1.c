#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double __pow(double a, int b)
{
    if (b == 0)
        return 1;

    return b < 0 ? 1 / (a * __pow(a, abs(b) - 1)) : a * __pow(a, abs(b) - 1);
}

double factorial(unsigned int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

double __sin(double x)
{
    double s = 0, s_tmp, k = 0;
    do
    {
        s_tmp = s;
        s += __pow(-1, k) * (__pow(x, 2 * k + 1) / factorial(2 * k + 1));
        k++;
    } while (s != s_tmp);

    return s;
}

double __log(double x)
{
    double s = 0, s_tmp, k = 1;
    do
    {
        s_tmp = s;
        s += __pow(-1, k + 1) * (__pow(x - 1, k) / k);
        k++;
    } while (s != s_tmp);

    return s;
}

double __atan(double x)
{
    if (x > 1 || x < -1)
        return 0;

    double s = 0, s_tmp, k = 0;
    do
    {
        s_tmp = s;
        s += __pow(-1, k) * (__pow(x, 2 * k + 1) / (2 * k + 1));
        k++;

    } while (s != s_tmp);

    return s;
}

int main()
{
    printf("__sin(2)\t%.16f\n", __sin(2));
    printf("sin(2)\t\t%.16f\n", sin(2));
    printf("__atan(0.5)\t%.16f\n", __atan(0.5));
    printf("atan(0.5)\t%.16f\n", atan(0.5));
    printf("__log(1.4)\t%.16f\n", __log(1.4));
    printf("log(1.4)\t%.16f\n", log(1.4));
    return 0;
}

