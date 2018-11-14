#include <stdio.h>
#include <math.h>

int main()
{
    int a = 30, b = 25, x;

    do
    {
        x = abs(a - b);

        if (a > b)
            a = x;
        else
            b = x;

    } while ((a != 0) && (b != 0));

    printf("%d\n", a != 0 ? a : b);

    return 0;
}
