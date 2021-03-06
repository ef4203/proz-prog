#include "libBMP.h"
#include <math.h>
#include <stdio.h>
/*
#define X_MIN (-0.37465401)
#define Y_MIN (0.659227668)
#define X_MAX -0.37332411
#define Y_MAX 0.66020767
 */
#define X_MIN -2.0
#define Y_MIN -1.0
#define X_MAX 1.0
#define Y_MAX 1.0
#define WIDTH 1000
#define HEIGHT 1000
#define N_MAX 2000

/* Converts a BMP coordinate into a math coordinate. */
void to_math(int xin, int yin, double *x, double *y)
{
    *x = X_MIN + (xin * (X_MAX - X_MIN)) / (WIDTH);
    *y = (Y_MIN + (yin * (Y_MAX - Y_MIN)) / (HEIGHT)) * (-1);
}

/* Converts a math coordinate into a BMP coordinate. */
void to_BMP(double xin, double yin, int *x, int *y)
{
    *x = ((xin - X_MIN) * WIDTH) / (X_MAX - X_MIN);
    *y = ((-yin - Y_MIN) * HEIGHT) / (Y_MAX - Y_MIN);
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

    /* Calculate each coordinate. */
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
            data[y * WIDTH + x] = (value[y * WIDTH + x] * N_MAX) % 0xFFFFFF;
        }
    }

    bmp_create("mandel.bmp", data, WIDTH, HEIGHT);
    free(data);
    free(value);

    return 0;
}
