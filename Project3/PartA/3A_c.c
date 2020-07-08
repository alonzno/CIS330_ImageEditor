#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ERROR_CODES
{
    MALLOC_ERROR = -1,
    STREAM_ERROR = -2,
    BAD_INPUT = -3
};

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct
{
    char magic_num[128];
    int w;
    int h;
    int max_val;
    Pixel *img;
} Image;

Image *
malloc_image(int w, int h)
{
    Image *ret_img = malloc(sizeof(Image));
    ret_img->img = malloc(sizeof(Pixel) * w * h);
    ret_img->w = w;
    ret_img->h = h;

    if (ret_img == NULL || (ret_img->img) == NULL)
    {
        fprintf(stderr, "Memory Allocation Error");
        exit(MALLOC_ERROR);
    }
    
    return ret_img;
}

void free_image(Image **free_img)
{
    free((*free_img)->img);
    free(*free_img);
}

Image *
ReadImage(char *filename)
{
    int width, height, maxval, i, j;
    char magicNum[128];
    FILE *f_in = fopen(filename, "rb");
    Image *ret_img;
    
    if (f_in == NULL)
    {
        fprintf(stderr, "Error opening input PNM");
        exit(STREAM_ERROR);
    }

    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
    ret_img = malloc_image(width, height);
    strcpy(ret_img->magic_num, magicNum);
    ret_img->max_val = maxval;
    
    unsigned char buffer[3 * width];

    for (i = 0; i < height; i++)
    {
        fread(buffer, 1, 3* width, f_in);
        for (j = 0; j < width; j++)
        {
            ret_img->img[i*width + j].r = buffer[3*j];
            ret_img->img[i*width + j].g = buffer[3*j+1];
            ret_img->img[i*width + j].b = buffer[3*j+2];
        }
    }

    fclose(f_in);
    return ret_img;
}


void WriteImage(Image *img, char *filename)
{
    int i, j;
    unsigned char buffer[4];
    FILE *f_out = fopen(filename, "wb");
    
    if (f_out == NULL)
    {
        fprintf(stderr, "Error opening output PNM");
        exit(STREAM_ERROR);
    }
    
    fprintf(f_out, "%s\n%d %d\n%d\n", img->magic_num, img->w, img->h, img->max_val);
    
    for (i = 0; i < img->h; i++)
    {
        for (j = 0; j < img->w; j++)
        {  
            buffer[0] = img->img[i * img->w + j].r;
            buffer[1] = img->img[i * img->w + j].g;
            buffer[2] = img->img[i * img->w + j].b;
            fwrite(buffer, 1, 3, f_out);
        }  
    }
    fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{
    int i, j;
    Image *ret_img = malloc_image(input->w, input->h);
    ret_img->max_val = input->max_val;
    strcpy(ret_img->magic_num, input->magic_num);
    for (i = 0; i < input->h; i++)
    {
        for(j = 0; j < input->w; j++)
        {   
            if (i != j)
            {
                ret_img->img[i * input->w + j].r = input->img[i * input->w + j].r;
                ret_img->img[i * input->w + j].g = input->img[i * input->w + j].g;
                ret_img->img[i * input->w + j].b = input->img[i * input->w + j].b;
            }
            else
            {
                ret_img->img[i * input->w + j].r = (unsigned char)255;
                ret_img->img[i * input->w + j].g = (unsigned char)255;
                ret_img->img[i * input->w + j].b = 0;
            }
        }
    }
    return ret_img;
}

int main(int argc, char *argv[])
{
    if ( argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_filename> <output_filename>", argv[0]);
        exit(BAD_INPUT);
    }
   /* Read an image, apply yellow diagonal to it, then write */
    Image *real_img, *yellow_img;
    real_img = ReadImage(argv[1]);
    yellow_img = YellowDiagonal(real_img);
    WriteImage(yellow_img, argv[2]);
    free_image(&real_img);
    free_image(&yellow_img);
    
}
