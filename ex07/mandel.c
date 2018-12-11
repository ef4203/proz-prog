#include <stdio.h>
#include "libBMP.h"
#include <math.h>
#include <time.h>

#define X_MIN -2.0 //(-0.37465401)//-2.0
#define Y_MIN -1.0 //(0.659227668)//-1.0
#define X_MAX 1.0  //-0.37332411//1.0
#define Y_MAX 1.0  //0.66020767//1.0
#define WIDTH 1000
#define HEIGHT 1000
#define N_MAX 2000

/* Converts a BMP coordinate into a math coordinate. */
int to_math(int xin, int yin, double *x, double *y)
{
    *x = X_MIN + (xin * (X_MAX - X_MIN)) / (WIDTH);
    *y = (Y_MIN + (yin * (Y_MAX - Y_MIN)) / (HEIGHT)) * (-1);
    return 0;
}

/* Converts a math coordinate into a BMP coordinate. */
int to_BMP(double xin, double yin, int *x, int *y)
{
    *x = ((xin - X_MIN) * WIDTH) / (X_MAX - X_MIN);   //WIDTH/2+(xin);
    *y = ((-yin - Y_MIN) * HEIGHT) / (Y_MAX - Y_MIN); //HEIGHT/2-(yin);
    return 0;
}

double b, a;

/* Checks if a coordinate is convergent. */
unsigned int check_coordinate(double x, double y, int i)
{
    if (i > N_MAX)
        return N_MAX;

    if (x * x + y * y >= 4)
        return i;

    double temp = x * x - y * y + a;

    y = 2 * x * y + b;
    x = temp;

    return check_coordinate(x, y, ++i);
}

int main()
{
    uint32_t *data = (uint32_t *)malloc(WIDTH * HEIGHT * sizeof(uint32_t));
    int *value = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    int smin = N_MAX;
    int smax = 0;

    srand(time(NULL));

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double xm, ym;

            to_math(x, y, &xm, &ym);

            b = ym;
            a = xm;

            int d = check_coordinate(xm, ym, 1);

            if (d > smax && d - 200 < smax)
                smax = d;

            if (d < smin)
                smin = d;

            value[y * WIDTH + x] = d;
        }
    }

    /* Colorize the set. */
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            int c = value[y * WIDTH + x];
            data[y * WIDTH + x] = (c * N_MAX) % 0xFFFFFF;
        }
    }

    bmp_create("mandel.bmp", data, WIDTH, HEIGHT);
    free(data);

    return 0;
}
