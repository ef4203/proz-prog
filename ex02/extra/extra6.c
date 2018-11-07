#include <stdio.h>
int main()
{
    int n = 23193;

    for (int i = 32767 - n; i > 0; i--)
    {
        printf("%d ", i);
    }
    return 0;
}
