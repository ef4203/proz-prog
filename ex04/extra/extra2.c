#include <math.h>
#include <stdio.h>

double fac(unsigned int n)
{
    return n <= 1 ? 1 : n * fac(n - 1);
}

double e_x(unsigned int x)
{
    double r = 0, r_tmp, k = 0;
    do
    {
        r_tmp = r;
        r += pow(x, k) / fac(k);
        k++;
    } while (r != r_tmp);

    return r;
}

int main()
{
    printf("%.16f\n", e_x(2));
    return 0;
}
