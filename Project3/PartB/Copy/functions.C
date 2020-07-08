#include <functions.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ReadImage(char *filename, Image &output)
{
    int width, height, maxval, i, j;
    char magicNum[128];
    FILE *f_in = fopen(filename, "rb");
    
    if (f_in == NULL)
    {
        fprintf(stderr, "Error opening input PNM");
        exit(STREAM_ERROR);
    }
    
    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
    output.ResetSize(width, height);
    strcpy(output.magic_num, magicNum);
    output.max_val = maxval;
    
    unsigned char buffer[3 * width];

    for (i = 0; i < height; i++)
    {
        fread(buffer, 1, 3* width, f_in);
        for (j = 0; j < width; j++)
        {
            output.img[i*width + j].r = buffer[3*j];
            output.img[i*width + j].g = buffer[3*j+1];
            output.img[i*width + j].b = buffer[3*j+2];
        }
    }

    fclose(f_in);
}


void WriteImage(char *filename, Image &img)
{
    int i, j;
    unsigned char buffer[4];
    FILE *f_out = fopen(filename, "wb");
    
    if (f_out == NULL)
    {
        fprintf(stderr, "Error opening output PNM");
        exit(STREAM_ERROR);
    }
    
    fprintf(f_out, "%s\n%d %d\n%d\n", img.magic_num, img.w, img.h, img.max_val);
    
    for (i = 0; i < img.h; i++)
    {
        for (j = 0; j < img.w; j++)
        {  
            buffer[0] = img.img[i * img.w + j].r;
            buffer[1] = img.img[i * img.w + j].g;
            buffer[2] = img.img[i * img.w + j].b;
            fwrite(buffer, 1, 3, f_out);
        }  
    }
    fclose(f_out);
}
