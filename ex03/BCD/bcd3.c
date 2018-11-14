#include <stdio.h>

int main()
{
    int a = 30, b = 25, x;
    do
    {
        x = a % b;
        a = b;
        b = x;

    } while (b == 0);

    printf("%d\n", x);

    return 0;
}
