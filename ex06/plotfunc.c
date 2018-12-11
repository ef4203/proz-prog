#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "libBMP.h"

#define IMAGE_DIMENSION 300
#define IMAGE_HALF 150
#define TOTAl_SIZE 90000

struct t_dto
{
    uint32_t grid[IMAGE_DIMENSION][IMAGE_DIMENSION];
};

int f(double x)
{
    return 20 * sin(x / 20);
}

struct t_dto make_plain_white(struct t_dto data)
{
    for (int i = 0; i < IMAGE_DIMENSION; i++)
    {
        for (int j = 0; j < IMAGE_DIMENSION; j++)
        {
            data.grid[i][j] = COLOR_WHITE;
        }
    }

    return data;
}

struct t_dto plot_function(struct t_dto data)
{
    for (int i = 0; i < IMAGE_HALF; i++)
    {
        int value = f(i);
        if (value < IMAGE_HALF)
            data.grid[IMAGE_HALF - value][IMAGE_HALF + i] = COLOR_RED;
    }

    for (int i = -IMAGE_HALF; i < 0; i++)
    {
        int value = f(i);
        if (value < IMAGE_HALF)
            data.grid[IMAGE_HALF - value][IMAGE_HALF + i] = COLOR_RED;
    }

    return data;
}

struct t_dto draw_grid(struct t_dto data)
{
    for (int i = 0; i < IMAGE_DIMENSION; i++)
    {
        data.grid[i][IMAGE_HALF] = COLOR_BLACK;
        data.grid[IMAGE_HALF][i] = COLOR_BLACK;
    }

    return data;
}

int main()
{
    struct t_dto dataAsArray;
    uint32_t rawData[TOTAl_SIZE];

    dataAsArray = make_plain_white(dataAsArray);
    dataAsArray = draw_grid(dataAsArray);
    dataAsArray = plot_function(dataAsArray);

    memcpy(rawData, dataAsArray.grid, sizeof(rawData));

    bmp_create("test.bmp", rawData, IMAGE_DIMENSION, IMAGE_DIMENSION);

    return 0;
}

void toMath(uint32_t bmp_x, uint32_t bmp_y, float *x, float *y)
{
    *x = (-IMAGE_HALF) + ((bmp_x * IMAGE_DIMENSION) / IMAGE_DIMENSION);
    *y = (-IMAGE_HALF) + ((bmp_y * IMAGE_DIMENSION) / IMAGE_DIMENSION);
}

/* implementation;

    float x, y;

    toMath(0, 0, &x, &y);
*/

void toBMP(float x, float y, uint32_t *bmp_x, uint32_t *bmp_y)
{
    *bmp_x = x - IMAGE_HALF;
    *bmp_y = y + IMAGE_HALF;
}

/* implementation;

    uint32_t x, y;

    toBMP(0, 0, &x, &y);
*/
