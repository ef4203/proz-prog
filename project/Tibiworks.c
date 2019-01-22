#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char magic[2];
	int size;
	int res;
	int offset;
} bmp_header_t;

typedef struct {
	int size;
	int width;
	int height;
	char planes[2];
	char bpp[2];
} dib_header_t;

typedef struct {
	char B;
	char G;
	char R;
	char reserved;
} rgbquad_t;

void writepixel(char *inpixel, rgbquad_t *palette, int offset, char *buf,char bpp) {
	switch(bpp) {
		case 8:
			buf[offset] = inpixel[0];
			break;
		case 24:
			buf[offset] = inpixel[0];
			buf[offset + 1] = inpixel[1];
			buf[offset + 2] = inpixel[2];
			break;
	}
}

bmp_header_t readbmpheader (FILE *in) {
	bmp_header_t out;
	memset(&out, 0, sizeof(bmp_header_t));

	fread(&out.magic, sizeof(out.magic), 1, in);
	fread(&out.size, sizeof(out.size), 1, in);
	fread(&out.res, sizeof(out.res), 1, in);
	fread(&out.offset, sizeof(out.offset), 1, in);

	return out;
}

dib_header_t readdibheader (FILE *in) {
	dib_header_t out;
	memset(&out, 0, sizeof(bmp_header_t));

	fread(&out.size, sizeof(out.size), 1, in);
	fread(&out.width, sizeof(out.width), 1, in);
	fread(&out.height, sizeof(out.height), 1, in);
	fread(&out.planes, sizeof(out.planes), 1, in);
	fread(&out.bpp, sizeof(out.bpp), 1, in);

	return out;
}

rgbquad_t *readpalette(char *palbuf) {
	rgbquad_t *out;

	if((out = (rgbquad_t*)malloc(256 * sizeof(rgbquad_t))) == NULL)
		return NULL;

	return out;
}

int main(int argc, char **argv) {
	FILE *in;//, *out;
	bmp_header_t bmp_header;
	dib_header_t dib_header;
	rgbquad_t *palette;

	int i, j, k, add, bufsize, offset;
	char buf[3], palbuf[1024];
	char *outbuf;

	if(argc < 2) {
		fprintf(stderr, "USAGE: %s <INPUT>\n", argv[0]);
		return -1;
	}

	printf("Opening input file... ");
	if((in = fopen(argv[1], "rb")) == NULL) {
		printf("ERROR: Could not open input file for reading.\n");
		return -1;
	}

	printf("OK\n");

	bmp_header = readbmpheader(in);
	dib_header = readdibheader(in);

	printf("Checking magic number... ");
	if(strncmp(bmp_header.magic, "BM", 2)) {
		printf("ERROR: Not a bitmap file.\n");
		fclose(in);
		return -1;
	}
	printf("OK\n");

	printf("Checking header size... ");
	printf("%d. ", dib_header.size);
	if(dib_header.size != 40) {
		printf("ERROR: Not Windows V3\n");
		fclose(in);
		return -1;
	}
	printf("OK\n");

	printf("Checking dimensions... ");
	printf("%dx%dx%dbbp. ", dib_header.width, dib_header.height, dib_header.bpp[0]);
	printf("OK\n\n");

    if(dib_header.bpp[0] == 8) {
		printf("Reading palette... ");
		fseek(in, sizeof(bmp_header_t) + dib_header.size, SEEK_SET);
		fread(palbuf, 1024, 1, in);
		palette = readpalette(palbuf);
		printf("OK\n");
	} else
		palette = NULL;

	fseek(in, bmp_header.offset, SEEK_SET);
	printf("Filling output buffer... ");
	bufsize = dib_header.height * dib_header.width * (dib_header.bpp[0] / 8);
	add = (dib_header.bpp[0] == 8)?1024:0;

	if((outbuf = (char*)malloc(bufsize + add)) == NULL) {
		fprintf(stderr, "ERROR: malloc(%d) failed.\n", bufsize);
		fclose(in);
		return -1;
	}

	for(i = 0; i < add; i++)
		outbuf[i] = palbuf[i];

	for(i = 0; i < dib_header.height; i++) {
		offset = (dib_header.bpp[0] / 8) * dib_header.width * (dib_header.height - 1 - i) + add;
		for(j = 0; j < dib_header.width; j++) {
			fread(buf, (dib_header.bpp[0] / 8), 1, in);
			writepixel(buf, palette, offset + (j * dib_header.bpp[0] / 8), outbuf,dib_header.bpp[0]);
		}
		for(k = 0; k < ((dib_header.width * dib_header.bpp[0] / 8) % 4); k++)
			fgetc(in);
	}
    printf("OK\n");

    unsigned  int ** data= malloc(dib_header.height * sizeof(unsigned int*));
    for(i = 0; i < dib_header.height; i++) {
      data[i] = malloc(dib_header.width * sizeof(unsigned int));
   }
    for(int i=0;i<dib_header.height;i++){
        for(int j=0;j<dib_header.width;j++){
            if(outbuf[i*dib_header.width*3+j*3]==-1&&outbuf[i*dib_header.width*3+j*3+1]==-1&&outbuf[i*dib_header.width*3+j*3+2]==-1){
                data[i][j]=0;
            }else if(outbuf[i*dib_header.width*3+j*3]==0&&outbuf[i*dib_header.width*3+j*3+1]==0&&outbuf[i*dib_header.width*3+j*3+2]==0){
                data[i][j]=1;
            }else{
                printf("unexpected color read! \n");
                return 1;
            }
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }


	if(palette)
		free(palette);
	free(outbuf);
	fclose(in);

	return 0;
}
