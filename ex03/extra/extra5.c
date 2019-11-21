#include <stdio.h>
#include <stdlib.h>

int ctoi(char c)
{
    char str[2] = {0, 0};
    str[0] = c;
    return atoi(str);
}

int main()
{
    int x = 0, c;
    char str[9] = {0};
    for (char i = '1'; i <= '9'; i++)
    {
        str[x++] = i;
        c = atoi(str);
        printf("%d\n", c * 9 + (ctoi(i) + 1));
    }
    return 0;
}

