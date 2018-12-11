#include <stdio.h>
#include "libBMP.h"
#include <math.h>

#define SCHRITTX (((XMAX) - (XMIN)) / BREITE)
#define SCHRITTY (((YMAX) - (YMIN)) / HOEHE)
#define XMIN -2.0 //(-0.37465401)//-2.0
#define YMIN -1.0 //(0.659227668)//-1.0
#define XMAX 1.0  //-0.37332411//1.0
#define YMAX 1.0  //0.66020767//1.0
#define BREITE 1000
#define HOEHE 1000
#define N_MAX 2000

int toMath(int xin, int yin, double *x, double *y)
{
    *x = XMIN + (xin * (XMAX - XMIN)) / (BREITE);
    *y = (YMIN + (yin * (YMAX - YMIN)) / (HOEHE)) * (-1);
    return 0;
}
int toBMP(double xin, double yin, int *x, int *y)
{
    *x = ((xin - XMIN) * BREITE) / (XMAX - XMIN); //BREITE/2+(xin);
    *y = ((-yin - YMIN) * HOEHE) / (YMAX - YMIN); //HOEHE/2-(yin);
    return 0;
}
double b, a;
unsigned int blah(double x, double y, int i)
{
    if (i > N_MAX)
    {
        return N_MAX;
    }
    if (x * x + y * y >= 4)
    {
        return i;
    }
    double temp = x * x - y * y + a;
    y = 2 * x * y + b;
    x = temp;

    return blah(x, y, ++i);
}
int main()
{
    uint32_t *data = (uint32_t *)malloc(BREITE * HOEHE * sizeof(uint32_t));
    int *wert = (int *)malloc(BREITE * HOEHE * sizeof(int));
    int smin = N_MAX;
    int smax = 0;
    for (int x = 0; x < BREITE; x++)
    {
        for (int y = 0; y < HOEHE; y++)
        {
            double xm;
            double ym;
            toMath(x, y, &xm, &ym);
            b = ym;
            a = xm;
            int d = blah(xm, ym, 1);
            if (d > smax && d - 200 < smax)
            {
                smax = d;
            }
            if (d < smin)
            {
                smin = d;
            }
            wert[y * BREITE + x] = d;
        }
    }
    //printf("%d - %d",smin,smax);
    for (int x = 0; x < BREITE; x++)
    {
        for (int y = 0; y < HOEHE; y++)
        {
            int c = wert[y * BREITE + x];
            c = ((1.0 * c - smin) / (smax - smin)) * 255;
            //printf("%d\n",c);
            if (c >= N_MAX)
            {
                data[y * BREITE + x] = COLOR_BLACK;
            }
            else
            {
                if (c % 768 <= 255)
                {

                    data[y * BREITE + x] = 0x00000000 + c * 0x00010000;
                }
                else if (c % 768 <= 511)
                {

                    data[y * BREITE + x] = 0x00000000 + (c % 256) * 0x00000100;
                    //data[y*BREITE+x]=COLOR_WHITE;
                }
                else if (c % 768 <= 767)
                {

                    data[y * BREITE + x] = 0x00000000 + (c % 256) * 0x00000001;
                    //data[y*BREITE+x]=COLOR_WHITE;
                }
            }
        }
    }
    bmp_create("tollesBild.bmp", data, BREITE, HOEHE);
    free(data);

    return 0;
}
