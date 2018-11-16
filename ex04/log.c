#include <stdio.h>
#include <math.h>

double my_log(double x)
{
    double result, result_tmp, k = 1;

    while (1)
    {
        result += pow(-1, k + 1) * (pow(x - 1, k) / k);

        k++;

        if (result == result_tmp)
            break;
        else
            result_tmp = result;
    }
    return result;
}

int main()
{
    printf("my_log(1.4)\t= %.10f\n", my_log(1.4));
    printf("log(1.4)\t= %.10f\n", log(1.4));

    return 0;
}
