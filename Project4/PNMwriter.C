#include <stdio.h>
#include <stdlib.h>
#include <PNMwriter.h>

void PNMwriter::Write(char * filename)
{
    FILE *f_out = fopen(filename, "wb");

    if (f_out == NULL)
    {
        fprintf(stderr, "Error opening output PNM");
        exit(STREAM_ERROR);
    }

    fprintf(f_out, "%s\n%d %d\n%d\n", img1->getMagicNum(), img1->getWidth(), img1->getHeight(), img1->getMaxVal());
    fwrite(img1->getAllPixel(), sizeof(Pixel), img1->getWidth() * img1->getHeight(), f_out);
    fclose(f_out);
}
