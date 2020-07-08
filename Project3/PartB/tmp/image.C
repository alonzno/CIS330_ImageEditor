#include <image.h>
#include <functions.h>
#include <string.h>
#include <stdlib.h>

Image::Image(void)
{
    magic_num[0] = 'P';
    magic_num[1] = '6';
    magic_num[2] = char(0);
    w = 0;
    h = 0;
    max_val = 255;
    img = NULL;
}
/*
Image::Image(char[128] m_num, int width, int height, int m_val, Pixel *i)
{
    magic_num = m_num;
    w = width;
    h = height;
    max_val = m_val;
    img = i;
}
*/
Image::Image(char *filename)
{   
    ReadImage(filename, *this);
}

Image::Image(Image &i)
{
    int j;
    w = i.w;
    h = i.h;
    max_val = i.max_val;
    strcpy(magic_num, i.magic_num);
    img = (Pixel *)malloc(h*w*sizeof(Pixel));
    
    for( j = 0; j < (w*h); j++)
    {
        img[j].r = i.img[j].r;
        img[j].g = i.img[j].g;
        img[j].b = i.img[j].b;
    } 
}

void Image::ResetSize(int width, int height)
{
    w = width;
    h = height;
    free(img);
    img = (Pixel *)malloc(height*width*sizeof(Pixel));
}
