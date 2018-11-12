#include <stdio.h>

int main()
{
    for (int num = 1; num <= 100; num++)
    {
        if (num % 3 == 0)
        {
            printf("%d ", num);
        }
    }
    return 0;
}
