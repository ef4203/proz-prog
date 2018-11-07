#include <stdio.h>

int main()
{
    int n = 420;

    for (int i = n; i > 1; i--)
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}