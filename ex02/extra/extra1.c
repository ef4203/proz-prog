#include <stdio.h>

int main()
{
    int absoluteZero = -273;

    for (int i = 0; i <= 550; i += 5)
    {
        printf("%d K | %d C\n", i, absoluteZero + i);
    }

    return 0;
}