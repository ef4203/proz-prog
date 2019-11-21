#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, c;
    char str[9] = {0};
    for (char i = '1'; i <= '9'; i++)
    {
        str[x++] = i;
        c = atoi(str);
        printf("%d\n", (c * 8) + 9);
    }
    return 0;
}
