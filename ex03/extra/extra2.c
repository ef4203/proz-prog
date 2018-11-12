#include <stdio.h>

int main()
{
    int n = 42;
    int result = 1;

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }

    printf("%d\n", result);

    return 0;
}
