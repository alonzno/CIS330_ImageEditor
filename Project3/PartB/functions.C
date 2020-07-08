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

    fread(output.img, sizeof(Pixel), width * height, f_in);

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
    
    fwrite(img.img, sizeof(Pixel), img.w * img.h, f_out);
    fclose(f_out);
}

void HalfSize(Image &input, Image &output)
{
    int new_w = input.w / 2;
    int new_h = input.h / 2;
    int i, j;
    
    output.ResetSize(new_w, new_h);
    
    for (i = 0; i < new_h; i++)
    {
        for (j = 0; j < new_w; j++)
        {  
            output.img[i * new_w + j].r = input.img[4 * i * new_w + j * 2].r;
            output.img[i * new_w + j].g = input.img[4 * i * new_w + j * 2].g;
            output.img[i * new_w + j].b = input.img[4 * i * new_w + j * 2].b;
        }  
    }
}

void LeftRightCombine(Image &leftInput, Image &rightinput, Image &output)
{   
    if (leftInput.h != rightinput.h)
    {
        fprintf(stderr, "You cannot left and right combine images of different heights");
        exit(BAD_INPUT);
    }
    
    int new_w = leftInput.w + rightinput.w;
    int height = leftInput.h;
    int l_width = leftInput.w;
    int r_width = rightinput.w;
    int i,j;

    output.ResetSize(new_w, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < new_w; j++)
        {
            if (j < l_width)
            {
                output.img[i * new_w + j].r = leftInput.img[i * l_width + j].r;
                output.img[i * new_w + j].g = leftInput.img[i * l_width + j].g;
                output.img[i * new_w + j].b = leftInput.img[i * l_width + j].b;
            }
            else
            { 
                output.img[i * new_w + j].r = rightinput.img[i * r_width + (j - l_width)].r;
                output.img[i * new_w + j].g = rightinput.img[i * r_width + (j - l_width)].g;
                output.img[i * new_w + j].b = rightinput.img[i * r_width + (j - l_width)].b;
            }
        }
    }
}

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output)
{

    if (topInput.w != bottomInput.w)
    {
        fprintf(stderr, "You cannot top and bottom combine images of different widths");
        exit(BAD_INPUT);
    }
    
    int new_h = topInput.h + bottomInput.h;
    int width = topInput.w;
    int l_height = topInput.h;
    int r_height = bottomInput.h;
    int i,j;

    output.ResetSize(width, new_h);

    for (i = 0; i < new_h; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i < l_height)
            {
                output.img[i * width + j].r = topInput.img[i * width + j].r;
                output.img[i * width + j].g = topInput.img[i * width + j].g;
                output.img[i * width + j].b = topInput.img[i * width + j].b;
            }
            else
            { 
                output.img[i * width + j].r = bottomInput.img[(i - l_height) * width + j].r;
                output.img[i * width + j].g = bottomInput.img[(i - l_height) * width + j].g;
                output.img[i * width + j].b = bottomInput.img[(i - l_height) * width + j].b;
            }
        }
    }
}

void Blend(Image &input1, Image &input2, double factor, Image &output)
{
    if (input1.w != input2.w || input1.h != input2.h)
    {
        fprintf(stderr, "You cannot blend images of different dimensions.");
        exit(BAD_INPUT);
    }

    int i,j;
    int width = input1.w;
    int height = input1.h;
    double factor2 = 1 - factor;
    output.ResetSize(width, height);


    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            output.img[i * width + j].r = input1.img[i * width + j].r * factor + input2.img[i * width + j].r * factor2;
            output.img[i * width + j].g = input1.img[i * width + j].g * factor + input2.img[i * width + j].g * factor2;
            output.img[i * width + j].b = input1.img[i * width + j].b * factor + input2.img[i * width + j].b * factor2;
        }
    }

}
