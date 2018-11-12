#include <stdio.h>

int main()
{
    for (int num = 1; num < 101; num++)
    {
        if (num % 3 == 0)
        {
            printf("%d ", num);
        }
    }
    return 0;
}