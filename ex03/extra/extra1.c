// Standard library einbeziehen
#include <stdio.h>
// Hier fängt das Programm an
int main() {
// 1 - 100 welche Zahlen sind durch 3 teilbar
    for (int num = 1; num < 101; num++)
    {
        if(num%3==0)
        {
            printf("%d ", num);
        }
    }
    return 0;
}