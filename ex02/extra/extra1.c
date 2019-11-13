#include <stdio.h>

int main()
{
    for (int i = 0; i <= 550; i += 5)
        printf("%d K | %d C\n", i, -273 + i);

    return 0;
}
