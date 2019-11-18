#include <stdio.h>

int main()
{
    long n = 10, f = 1;
    do
    {
        f *= n--;
    } while (n > 1);

    printf("%ld\n", f);
    return 0;
}
