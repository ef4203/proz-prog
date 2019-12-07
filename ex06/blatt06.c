#include "libBMP.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_DIMENSION 300
#define IMAGE_HALF 150
#define TOTAl_SIZE 90000

uint32_t *grid;
void draw_white();
void draw_grid();
void plotfunc(int (*func)(double x), int color);
int xytoptr(int x, int y);

int g(double x)
{
    return 10 * pow(x / 20, 2);
}

int h(double x)
{
    return 20 * cos(x / 20);
}

int f(double x)
{
    return 20 * sin(x / 20);
}

int main()
{
    grid = malloc(TOTAl_SIZE * sizeof(int));

    draw_white();
    draw_grid();
    plotfunc(&f, COLOR_RED);
    plotfunc(&g, COLOR_BLUE);
    plotfunc(&h, COLOR_GREEN);

    bmp_create("test.bmp", grid, IMAGE_DIMENSION, IMAGE_DIMENSION);

    return 0;
}

void draw_white()
{
    memset(grid, COLOR_WHITE, TOTAl_SIZE * sizeof(int));
}

void draw_grid()
{
    for (int i = 0; i < IMAGE_DIMENSION; i++)
    {
        *(grid + xytoptr(i, IMAGE_HALF)) = COLOR_BLACK;
        *(grid + xytoptr(IMAGE_HALF, i)) = COLOR_BLACK;
    }
}

void plotfunc(int (*func)(double x), int color)
{
    for (int i = 0; i < IMAGE_HALF; i++)
    {
        int value = func(i);
        if (value < IMAGE_HALF)
            *(grid + xytoptr(IMAGE_HALF - value, IMAGE_HALF + i)) = color;
    }

    for (int i = -IMAGE_HALF; i < 0; i++)
    {
        int value = func(i);
        if (value < IMAGE_HALF)
            *(grid + xytoptr(IMAGE_HALF - value, IMAGE_HALF + i)) = color;
    }
}

int xytoptr(int x, int y)
{
    return (x * IMAGE_DIMENSION) + y;
}

/*
void toMath(uint32_t bmp_x, uint32_t bmp_y, float *x, float *y)
{
    *x = (-IMAGE_HALF) + ((bmp_x * IMAGE_DIMENSION) / IMAGE_DIMENSION);
    *y = (-IMAGE_HALF) + ((bmp_y * IMAGE_DIMENSION) / IMAGE_DIMENSION);
}
void toBMP(float x, float y, uint32_t *bmp_x, uint32_t *bmp_y)
{
    *bmp_x = x - IMAGE_HALF;
    *bmp_y = y + IMAGE_HALF;
}
*/
