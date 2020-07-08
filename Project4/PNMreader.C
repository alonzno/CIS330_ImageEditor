#include <PNMreader.h>

PNMreader::PNMreader(char * filename)
{
    f_name = (char *)malloc(strlen(filename) + 1);
    strcpy(f_name, filename);
}

PNMreader::~PNMreader()
{
    free(f_name);
}

void PNMreader::Execute(void)
{
    int width, height, maxval, i, j;
    char magicNum[128];
    FILE *f_in = fopen(f_name, "rb");

    if ( f_in == NULL )
    {
        fprintf(stderr, "Error opening input PNM");
        exit(STREAM_ERROR);
    }

    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    img.ResetSize(width, height);
    img.setMagicNum(magicNum);
    img.setMaxVal(maxval);

    fread(img.getAllPixel(), sizeof(Pixel), width * height, f_in);

    fclose(f_in);
}

void PNMreader::Update(void)
{
    PNMreader::Execute();
}
