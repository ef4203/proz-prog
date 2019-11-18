#include <stdio.h>

int main()
{
    for (int n = 1; n <= 100; n++)
    {
        if (n % 3 == 0)
            printf("%d\n", n);
    }
    return 0;
}
