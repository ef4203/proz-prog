#include <math.h>
#include <stdio.h>

double fac(unsigned int n)
{
    return n <= 1 ? 1 : n * fac(n - 1);
}

double mf(unsigned int n, unsigned int k)
{
    if (!n)
        return 0;

    if (n <= k)
        return n;

    return n * pow(fac(n - k), k);
}

int main()
{
    return 0;
}
