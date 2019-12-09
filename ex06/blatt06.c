#include "libBMP.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DIM 300
#define HALF (DIM / 2)
#define TOTAL (DIM * DIM)

uint32_t *grid;

int f(double x)
{
    return 20 * sin(x / 20);
}

void draw_white()
{
    memset(grid, COLOR_WHITE, TOTAL * sizeof(int));
}

void draw_grid()
{
    for (int i = 0; i < DIM; i++)
    {
        grid[i * DIM + HALF] = COLOR_BLACK;
        grid[HALF * DIM + i] = COLOR_BLACK;
    }
}

void plotfunc(int (*func)(double x), int color)
{
    for (int i = -HALF; i < HALF; i++)
    {
        int value = func(i);
        if (value < HALF)
            grid[(HALF - value) * DIM + HALF + i] = color;
    }
}

int main()
{
    grid = malloc(TOTAL * sizeof(int));

    draw_white();
    draw_grid();
    plotfunc(&f, COLOR_RED);
    bmp_create("test.bmp", grid, DIM, DIM);

    free(grid);
    return 0;
}

/*
void toMath(uint32_t bmp_x, uint32_t bmp_y, float *x, float *y)
{
    *x = (-HALF) + ((bmp_x * DIM) / DIM);
    *y = (-HALF) + ((bmp_y * DIM) / DIM);
}
void toBMP(float x, float y, uint32_t *bmp_x, uint32_t *bmp_y)
{
    *bmp_x = x - HALF;
    *bmp_y = y + HALF;
}
*/
