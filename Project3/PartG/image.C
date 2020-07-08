#include <image.h>
#include <string.h>
#include <stdlib.h>
#include <source.h>

Image::Image(void)
{
    magic_num[0] = 'P';
    magic_num[1] = '6';
    magic_num[2] = char(0);
    w = 0;
    h = 0;
    max_val = 255;
    img = NULL;
    source = NULL;
}

Image::Image(Image &i)
{
    int j;
    w = i.w;
    h = i.h;
    max_val = i.max_val;
    strcpy(magic_num, i.magic_num);
    img = (Pixel *)malloc(h*w*sizeof(Pixel));
    memcpy(img, i.img, h*w*sizeof(Pixel));
    source = i.source;
}

Image::~Image()
{
    free(img);
}

void Image::setPixel(int r, int g, int b, int p)
{
    img[p].r = r;
    img[p].g = g;
    img[p].b = b;
}

void Image::setPixel(int p, Pixel pix)
{
    img[p].r = pix.r;
    img[p].g = pix.g;
    img[p].b = pix.b;
}

void Image::ResetSize(int width, int height)
{
    w = width;
    h = height;
    free(img);
    img = (Pixel *)malloc(height*width*sizeof(Pixel));
}

void Image::Update(void) const 
{   
    source->Update();
}
