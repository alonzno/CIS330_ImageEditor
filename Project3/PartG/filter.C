#include <filter.h>
#include <stdio.h>
#include <stdlib.h>
#include <logging.h>

void Filter::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        //char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to update input2", this->FilterName());
    Logger::LogEvent(msg);
     
    if ( img2 == NULL )
    {
        //char msg[1024];
        sprintf(msg, "%s: no input2!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img2->Update();
    
    sprintf(msg, "%s: done updating input2", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
}

void Mirror::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
}

void Rotate::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
}

void Grayscale::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
}

void Blur::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
}

void Shrinker::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to update input1", this->FilterName());
    Logger::LogEvent(msg);
    
    if ( img1 == NULL )
    {
        char msg[1024];
        sprintf(msg, "%s: no input1!", this->FilterName());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    img1->Update();
    
    sprintf(msg, "%s: done updating input1", this->FilterName());
    Logger::LogEvent(msg);
    
    sprintf(msg, "%s: about to execute", this->FilterName());
    Logger::LogEvent(msg);
    
    this->Execute();
    
    sprintf(msg, "%s: done executing", this->FilterName());
    Logger::LogEvent(msg);
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
        char msg[1024];
        sprintf(msg, "%s: heights must match: %d, %d", this->FilterName(), img1->getHeight(), img2->getHeight());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
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
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d", this->FilterName(), img1->getWidth(), img2->getWidth());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
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

void Mirror::Execute(void)
{
    //Make a new update method for this thing
    int i, j;
    int width = img1->getWidth();
    int height = img1->getHeight();
    img.ResetSize(width, height);

    for (i=0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            img.setPixel( i*width + (width-j-1), img1->getPixel(i * width + j));
        }
    }

}

void Rotate::Execute(void)
{
    int i, j;
    int width = img1->getWidth();
    int height = img1->getHeight();
    img.ResetSize(height, width);

    for (i = 0; i < height; i++)
    {    
        for (j=0; j < width; j++)
        {
            img.setPixel( (height - i - 1) + (j * height), img1->getPixel(i * width + j));
        }
    }
}

void Subtract::Execute(void)
{
    if (img1->getWidth() != img2->getWidth() || img1->getHeight() != img2->getHeight())
    {
        char msg[1024];
        sprintf(msg, "%s: dimensions must match: Width %d, %d Height %d, %d", this->FilterName(), img1->getWidth(), img2->getWidth(), img1->getHeight(), img2->getHeight());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }
    
    int i, j, r, g, b;
    int width = img1->getWidth();
    int height = img1->getHeight();
    Pixel p1, p2;
    img.ResetSize(width, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            p1 = img1->getPixel(i * width + j);
            p2 = img2->getPixel(i * width + j);
            r = (p1.r > p2.r) ? p1.r - p2.r : 0;
            g = (p1.g > p2.g) ? p1.g - p2.g : 0;
            b = (p1.b > p2.b) ? p1.b - p2.b : 0;
            img.setPixel(r, g, b, i * width + j);
        }
    }

}

void Grayscale::Execute(void)
{
    int i, j, gray;
    int width = img1->getWidth();
    int height = img1->getHeight();
    Pixel p1; 
    img.ResetSize(width, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            p1 = img1->getPixel(i * width + j);
            gray = p1.r / 5 + p1.g / 2 + p1.b / 4;
            img.setPixel(gray, gray, gray, i * width + j);
        }
    }

}

void Blur::Execute(void)
{
    int i, j, x, y, r, g, b;
    int width = img1->getWidth();
    int height = img1->getHeight();
    Pixel p;
    img.ResetSize(width, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if ( i == 0 || j == 0 || i == height-1 || j == width-1)
            {
                img.setPixel(i * width + j, img1->getPixel(i * width + j));
            }
            else
            {
                r = g = b = 0;
                for ( x = -1; x < 2; x++ )
                {
                    for ( y = -1; y < 2; y++ )
                    {
                        if (!(x == 0 && y == 0))
                        {
                           p = img1->getPixel( (i+x) * width + (j + y) ); 
                           r += p.r / 8;
                           g += p.g / 8;
                           b += p.b / 8;
                        }
                    }
                }
                img.setPixel(r, g, b, i * width + j);
            }
        }   
    }
}

void Blender::Execute(void)
{

    if (img1->getWidth() != img2->getWidth() || img1->getHeight() != img2->getHeight())
    {
        char msg[1024];
        sprintf(msg, "%s: dimensions must match: Width %d, %d Height %d, %d", this->FilterName(), img1->getWidth(), img2->getWidth(), img1->getHeight(), img2->getHeight());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
    }

    if ( getFactor() > 1 || getFactor() < 0 )
    {
        char msg[1024];
        sprintf(msg, "Invalid factor for %s: %f", this->FilterName(), getFactor());
        DataFlowException e(this->FilterName(), msg); 
        throw e;
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
