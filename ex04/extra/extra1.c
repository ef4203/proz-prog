#include <stdio.h>

int main()
{
    double d1, d2;
    float f1, f2;
    f2 = d1 = 0.1;
    d2 = f1 = 0.1;

    if (f1 == f2)
        printf("a is true\n");
    else
        printf("a is false\n");

    if (f1 != f2)
        printf("b is true\n");
    else
        printf("b is false\n");

    if (d1 == d2)
        printf("c is true\n");
    else
        printf("c is false\n");

    if (d1 != d2)
        printf("d is true\n");
    else
        printf("d is false\n");

    return 0;
}
