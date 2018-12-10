#ifndef __libBMP_h__
#define __libBMP_h__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define COLOR_BLACK 0x00000000
#define COLOR_RED 0x00FF0000
#define COLOR_GREEN 0x0000FF00
#define COLOR_BLUE 0x000000FF
#define COLOR_WHITE 0x00FFFFFF

/**
 * Writes N bytes to a file.
 *
 * bmp  - Pointer to the image
 * byte - Byte-Muster
 * N    - Number of bytes
 */
void bmp_write_N_byte(FILE *bmp, uint64_t byte, int N)
{
    for (int i = 0; ((i < N) && (i < 8)); i++)
    {
        fputc(byte % 256, bmp);
        byte /= 256;
    }
}

/**
 * Create bmp header.
 *
 * bmp    - Pointer to the image
 * width  - Width  (in Pixel)
 * height - Height (in Pixel)
 */
void bmp_file_header(FILE *bmp, int width, int height)
{
    fputc('B', bmp);
    fputc('M', bmp);
    bmp_write_N_byte(bmp, 14 + 40 + width * height * 32, 4);
    bmp_write_N_byte(bmp, 0, 4);
    bmp_write_N_byte(bmp, 54, 4);
}

/**
 * Creates a bmp info header
 *
 * bmp    - Pointer to the image
 * width  - Width  (in Pixel)
 * height - Height (in Pixel)
 */
void bmp_info_header(FILE *bmp, int width, int height)
{
    bmp_write_N_byte(bmp, 40, 4);
    bmp_write_N_byte(bmp, width, 4);
    bmp_write_N_byte(bmp, -height, 4);
    bmp_write_N_byte(bmp, 1, 2);
    bmp_write_N_byte(bmp, 32, 2);
    bmp_write_N_byte(bmp, 0, 4);
    bmp_write_N_byte(bmp, width * height * 32, 4);
    bmp_write_N_byte(bmp, 0, 4);
    bmp_write_N_byte(bmp, 0, 4);
    bmp_write_N_byte(bmp, 0, 4);
    bmp_write_N_byte(bmp, 0, 4);
}

/**
 * Creates a bmp image
 *
 * bmp_name - Name of the image
 * data     - BMP data Array
 * width    - Width  (in Pixel)
 * height   - Height (in Pixel)
 */
void bmp_create(char *bmp_name, uint32_t *data, int width, int height)
{
    FILE *bmp = fopen(bmp_name, "wb");
    if (bmp == NULL)
    {
        fprintf(stderr, "\nbmp image couldn't be opened!\n");
        exit(EXIT_FAILURE);
    }
    bmp_file_header(bmp, width, height);
    bmp_info_header(bmp, width, height);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            bmp_write_N_byte(bmp, data[y * width + x], 4);
        }
    }
    fclose(bmp);
}

#endif
