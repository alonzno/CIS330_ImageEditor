#include <filter.h>
#include <stdio.h>
#include <stdlib.h>

void Filter::Update(void)
{
    img1->Update();
    img2->Update();
    this->Execute();
}

void Shrinker::Update(void)
{
    img1->Update();
    this->Execute();
}

void Shrinker::Execute(void)
{
    
    int new_w = img1->getWidth() / 2;
    int new_h = img1->getHeight() / 2;
    int i, j, red, green, blue;
    
    img.ResetSize(new_w, new_h);
    
    for (i = 0; i < new_h; i++)
    {
        for (j = 0; j < new_w; j++)
        {  
            red = img1->getPixel(4  * i * new_w + j * 2).r; 
            green = img1->getPixel(4  * i * new_w + j * 2).g; 
            blue = img1->getPixel(4  * i * new_w + j * 2).b; 
            img.setPixel(red, green, blue, i * new_w + j);
        }  
    }
}


void LRCombine::Execute(void)
{
    if (img1->getHeight() != img2->getHeight())
    {
        fprintf(stderr, "You cannot left and right combine images of different heights");
        exit(BAD_INPUT);
    }
    
    int new_w = img1->getWidth() + img2->getWidth();
    int height = img1->getHeight();
    int l_width = img1->getWidth();
    int r_width = img2->getWidth();
    int i, j;

    img.ResetSize(new_w, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < new_w; j++)
        {
            if (j < l_width)
            {
                img.setPixel(i * new_w + j, img1->getPixel(i * l_width + j));
            }
            else
            { 
                img.setPixel(i * new_w + j, img2->getPixel(i * r_width + (j - l_width)));
            }
        }
    }

}

void TBCombine::Execute(void)
{
    if (img1->getWidth() != img2->getWidth())
    {
        fprintf(stderr, "You cannot top and bottom combine images of different widths");
        exit(BAD_INPUT);
    }
    
    int new_h = img1->getHeight() + img2->getHeight();
    int width = img1->getWidth();
    int l_height = img1->getHeight();
    int r_height = img2->getHeight();
    int i,j;

    img.ResetSize(width, new_h);

    for (i = 0; i < new_h; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i < l_height)
            {
                img.setPixel(i * width + j, img1->getPixel(i * width + j));
            }
            else
            { 
                img.setPixel(i * width + j, img2->getPixel((i - l_height) * width + j));
            }
        }
    }
}

void Blender::Execute(void)
{
    if (img1->getWidth() != img2->getWidth() || img1->getHeight() != img2->getHeight())
    {
        fprintf(stderr, "You cannot blend images of different dimensions.");
        exit(BAD_INPUT);
    }

    int i, j, red, green, blue;
    int width = img1->getWidth();
    int height = img1->getHeight();
    double factor1 = this->getFactor();
    double factor2 = 1 - factor1;
    Pixel p1, p2;
    img.ResetSize(width, height);


    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            p1 = img1->getPixel(i * width + j);
            p2 = img2->getPixel(i * width + j);

            red = p1.r * factor + p2.r * factor2;
            green = p1.g * factor + p2.g * factor2;
            blue = p1.b * factor + p2.b * factor2;

            img.setPixel(red, green, blue, i * width + j);
        }
    }
}
