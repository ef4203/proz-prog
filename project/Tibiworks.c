#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{ // BMP File header
    char magic[2];
    int size;
    int res;
    int offset;
} bmp_header_t;

typedef struct
{ // BMP Info header
    int size;
    int width;
    int height;
    char planes[2];
    char bpp[2];
} dib_header_t;

void writepixel(char *inpixel, int offset, char *buf)
{ // write one pixel into an array at an offset
    buf[offset] = inpixel[0];
    buf[offset + 1] = inpixel[1];
    buf[offset + 2] = inpixel[2];
}

bmp_header_t readbmpheader(FILE *in)
{ // BMP File header einlesen
    bmp_header_t out;
    memset(&out, 0, sizeof(bmp_header_t));

    fread(&out.magic, sizeof(out.magic), 1, in);
    fread(&out.size, sizeof(out.size), 1, in);
    fread(&out.res, sizeof(out.res), 1, in);
    fread(&out.offset, sizeof(out.offset), 1, in);

    return out;
}

dib_header_t readdibheader(FILE *in)
{ // BMP info Header einlesen
    dib_header_t out;
    memset(&out, 0, sizeof(bmp_header_t));

    fread(&out.size, sizeof(out.size), 1, in);
    fread(&out.width, sizeof(out.width), 1, in);
    fread(&out.height, sizeof(out.height), 1, in);
    fread(&out.planes, sizeof(out.planes), 1, in);
    fread(&out.bpp, sizeof(out.bpp), 1, in);

    return out;
}

int end_x;
int solve(unsigned int **data, int **wasHere, int **correctPath, int x, int y,
          int height, int width)
{
    if (x == end_x && y == (height - 1))
        return 1;
    if (data[x][y] == 1 || wasHere[x][y])
        return 0;

    wasHere[x][y] = 1;

    if (x != 0)
    {
        if (solve(data, wasHere, correctPath, x - 1, y, height, width))
        {
            printf("found path\n");
            correctPath[x][y] = 1;

            return 1;
        }
    }
    if (x != (width - 1))
    {
        if (solve(data, wasHere, correctPath, x + 1, y, height, width))
        {
            printf("found path\n");
            correctPath[x][y] = 1;
            return 1;
        }
    }
    if (y != 0)
    {
        if (solve(data, wasHere, correctPath, x, y - 1, height, width))
        {
            printf("found path\n");
            correctPath[x][y] = 1;
            return 1;
        }
    }
    if (y != (height - 1))
    {
        if (solve(data, wasHere, correctPath, x, y + 1, height, width))
        {
            printf("found path\n");
            correctPath[x][y] = 1;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    FILE *in;
    bmp_header_t bmp_header;
    dib_header_t dib_header;

    char buf[3];
    char *outbuf;

    if (argc < 2)
    { // Input test
        fprintf(stderr, "USAGE: %s <INPUT>\n", argv[0]);
        return -1;
    }

    printf("Opening input file... ");
    if ((in = fopen(argv[1], "rb")) == NULL)
    { // File Opening
        printf("ERROR: Could not open input file for reading.\n");
        return -1;
    }

    printf("OK\n");

    bmp_header = readbmpheader(in);
    dib_header = readdibheader(in); // read them headers

    printf("Checking magic number... ");
    if (strncmp(bmp_header.magic, "BM", 2))
    { // checking for BM in first 2 chars
        printf("ERROR: Not a bitmap file.\n");
        fclose(in);
        return -1;
    }
    printf("OK\n");

    printf("Checking header size... ");
    printf("%d. ", dib_header.size); // checking BMP version
    if (dib_header.size != 40)
    {
        printf("ERROR: Not Windows V3\n");
        fclose(in);
        return -1;
    }
    printf("OK\n");

    printf("Checking dimensions... "); // checking if pic is okay and if BPP are
                                       // as requested
    printf("%dx%dx%dbbp. ", dib_header.width, dib_header.height,
           dib_header.bpp[0]);
    if (dib_header.bpp[0] != 24)
    {
        printf("Error in BPP of BMP");
        return 1;
    }
    printf("OK\n\n");

    fseek(in, bmp_header.offset, SEEK_SET); // skipping header in FILE
    printf("Filling output buffer... ");
    int bufsize = dib_header.height * dib_header.width *
                  (dib_header.bpp[0] / 8); // size of imagedata in image

    if ((outbuf = (char *)malloc(bufsize)) == NULL)
    { // allocate for imagedata
        fprintf(stderr, "ERROR: malloc(%d) failed.\n", bufsize);
        fclose(in);
        return -1;
    }

    for (int i = 0; i < dib_header.height; i++)
    { // für jede zeile
        int offset =
            (dib_header.bpp[0] / 8) * dib_header.width *
            (dib_header.height - 1 - i); // offset, weil pixel data falschrum
        for (int j = 0; j < dib_header.width; j++)
        {
            fread(buf, (dib_header.bpp[0] / 8), 1,
                  in); // read 3bytes(BGR)(one pixel)
            writepixel(buf, offset + (j * dib_header.bpp[0] / 8),
                       outbuf); // write that pixel to outbuf
        }
        for (int k = 0; k < ((dib_header.width * dib_header.bpp[0] / 8) % 4);
             k++) // delet the read pixels from input
            fgetc(in);
    }
    printf("OK\n");

    unsigned int **data = malloc(
        dib_header.height *
        sizeof(unsigned int *)); // cool 2D Array for ez showing allocated
    for (int i = 0; i < dib_header.height; i++)
    {
        data[i] = malloc(dib_header.width * sizeof(unsigned int));
    }
    for (int i = 0; i < dib_header.height; i++)
    {
        for (int j = 0; j < dib_header.width; j++)
        { // and filled
            if (outbuf[i * dib_header.width * 3 + j * 3] == -1 &&
                outbuf[i * dib_header.width * 3 + j * 3 + 1] == -1 &&
                outbuf[i * dib_header.width * 3 + j * 3 + 2] == -1)
            {
                data[i][j] = 0;
            }
            else if (outbuf[i * dib_header.width * 3 + j * 3] == 0 &&
                     outbuf[i * dib_header.width * 3 + j * 3 + 1] == 0 &&
                     outbuf[i * dib_header.width * 3 + j * 3 + 2] == 0)
            {
                data[i][j] = 1;
            }
            else
            {
                printf("unexpected color read! \n");
                return 1;
            }
            switch (data[i][j])
            {
            case (0):
                printf("  ");
                break;
            case (1):
                printf("# ");
                break;
            }
            // printf("%d ", data[i][j]); // print that maze in CMD
        }
        printf("\n");
    }

    printf("\n\n");
    for (int i = 1; i < dib_header.height - 1; i++)
    {
        for (int j = 1; j < dib_header.width - 1; j++)
        {
            if (data[i][j] == 0)
            {
                int ancient_nodes = 0;

                if (data[i - 1][j] == 0)
                    ancient_nodes += 1;
                if (data[i][j - 1] == 0)
                    ancient_nodes += 1;
                if (data[i + 1][j] == 0)
                    ancient_nodes += 1;
                if (data[i][j + 1] == 0)
                    ancient_nodes += 1;

                if (ancient_nodes > 2)
                    data[i][j] = 2;
            }
            switch (data[i][j])
            {
            case (0):
                printf("  ");
                break;
            case (1):
                printf("# ");
                break;
            case (2):
                printf("o ");
                break;
            }
        }
        printf("\n");
    }

    // find start
    int start_x;
    for (int i = 0; i < dib_header.width; i++)
    {
        if (data[0][i] == 0)
        {
            start_x = i;
            printf("Start point: [0][%d]\n", i);
        }
    }

    for (int i = 0; i < dib_header.width; i++)
    {
        if (data[(dib_header.width - 1)][i] == 0)
        {
            end_x = i;
            printf("End point: [%d][%d]\n", (dib_header.width - 1), i);
        }
    }

    for (int i = 0; i < dib_header.width; i++)
    {
        for (int j = 0; j < dib_header.height; j++)
        {
            switch (data[i][j])
            {
            case (0):
                printf("  ");
                break;
            case (1):
                printf("# ");
                break;
            case (2):
                printf("o ");
                break;
            }
        }
        printf("\n");
    }
    int **wasHere =
        malloc(dib_header.height *
               sizeof(int *)); // cool 2D Array for ez showing allocated
    for (int i = 0; i < dib_header.height; i++)
    {
        wasHere[i] = malloc(dib_header.width * sizeof(int));
    }

    int **correctPath =
        malloc(dib_header.height *
               sizeof(int *)); // cool 2D Array for ez showing allocated
    for (int i = 0; i < dib_header.height; i++)
    {
        correctPath[i] = malloc(dib_header.width * sizeof(int));
    }

    int a = solve(data, wasHere, correctPath, start_x, 0, dib_header.height,
                  dib_header.width);
    for (int i = 0; i < dib_header.height; i++)
    {
        for (int j = 0; j < dib_header.width; j++)
        {
            printf("%d ", correctPath[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < dib_header.height; i++) // free nicht vergessen!!
        free(data[i]);
    free(data);
    free(outbuf);
    fclose(in);

    return 0;
}
