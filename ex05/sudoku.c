#include <stdio.h>
#include <stdlib.h>

void clrscr()
{
    system("@cls||clear");
}

void printboard()
{
    printf("    1 2 3   4 5 6   7 8 9\n");
    printf("  -------------------------\n");
    for (int i = 1; i <= 9; i++)
    {
        printf("%d | x x x | x x x | x x x |\n", i);
        if (i == 3 || i == 6)
        {
            printf("  -------------------------\n");
        }
    }
    printf("  -------------------------\n");
}
int main()
{
    printboard();
    return 0;
}
