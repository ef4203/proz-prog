#include <math.h>
#include <stdio.h>

/* First algorithm for the largest common denominator. */
void lcd1(int a, int b)
{
    int x;
    do
    {
        /* Set x to the absolute value of a - b. */
        x = abs(a - b);

        /* Replace the largest value with x. */
        if (a > b)
            a = x;
        else
            b = x;

    } while ((a != 0) && (b != 0)); /* Do this as long no value is 0. */

    printf("%d\n", a != 0 ? a : b);
}

/* Second algorithm for the largest common denominator. */
void lcd2(int a, int b)
{
    int x;
    do
    {
        /* Set x to the modulus of a and b. */
        x = a % b;
        /* Set a to b. */
        a = b;
        /* Set b to x. */
        b = x;
    } while (b == 0); /* Continue as long b is 0. */

    printf("%d\n", x);
}

/* Third algorithm for the largest common denominator. */
void lcd3(int a, int b)
{
    int x;
    do
    {
        /* This is the same as x = a % b. */
        x = (a - (a / b) * b);
        a = b;
        b = x;
    } while (b == 0); /* Continue as long b is 0. */

    printf("%d\n", x);
}

int main()
{
    lcd1(30, 25);
    lcd2(30, 25);
    lcd3(30, 25);
    return 0;
}
