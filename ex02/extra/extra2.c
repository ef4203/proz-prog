#include <stdio.h>

float f(float x)
{
    return x * x;
}

int main()
{
    for (float x = -5; x <= 5; x += 0.125)
        printf("x = %f, f(x) = %f \n", x, f(x));

    return 0;
}
