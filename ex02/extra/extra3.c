#include <stdio.h>

int main()
{
    int a, b, c;
    int tmp;

    a = 3;
    b = 5;
    c = 10;

    printf("a=%d b=%d c=%d\n", a, b, c);

    while (!(a > b && b > c))
    {
        if (c > b)
        {
            tmp = c;
            c = b;
            b = tmp;
        }

        if (b > a)
        {
            tmp = b;
            b = a;
            a = tmp;
        }
    }

    printf("A=%d B=%d C=%d\n", a, b, c);

    return 0;
}