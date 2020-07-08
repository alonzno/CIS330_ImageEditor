#include <stdio.h>
#include <stdlib.h>
#include <PNMwriter.h>

const void PNMwriter::Write(const std::string &filename)
{
    FILE *f_out = fopen(filename.c_str(), "wb");

    if (f_out == NULL)
    {
        fprintf(stderr, "Error opening output PNM");
        exit(STREAM_ERROR);
    }

    fprintf(f_out, "%s\n%d %d\n%d\n", img1->getMagicNum(), img1->getWidth(), img1->getHeight(), img1->getMaxVal());
    fwrite(img1->getAllPixel(), sizeof(Pixel), img1->getWidth() * img1->getHeight(), f_out);
    fclose(f_out);
}

const void CheckSum::OutputCheckSum(const std::string &filename)
{
    
    FILE *f_out = fopen(filename.c_str(), "wb");

    if (f_out == NULL)
    {
        fprintf(stderr, "Error opening output PNM");
        exit(STREAM_ERROR);
    }

    if (img1 == NULL)
    {
        //Log ERROR
    }
    
    int i, area, r, g, b;
    Pixel p;
    area = img1->getWidth() * img1->getHeight();
    r = g = b = 0;
    for (i = 0; i < area; i++)
    {
        p = img1->getPixel(i);
        r += p.r;
        g += p.g;
        b += p.b;
    }

    r %= 256;
    g %= 256;
    b %= 256;

    fprintf(f_out, "CHECKSUM: %d, %d, %d\n", r, g, b);
    
    fclose(f_out);
}
