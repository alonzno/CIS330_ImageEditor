#include <PNMreader.h>
#include <logging.h>

PNMreader::PNMreader(const std::string &filename)
{
    f_name = (char *)malloc(strlen(filename.c_str()) + 1);
    strcpy(f_name, filename.c_str());
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
        char msg[1024];
        sprintf(msg, "%s: NoFileToWriteTo: %s", this->SourceName(), f_name);
        DataFlowException e(this->SourceName(), msg); 
        throw e;
    }

    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    img.ResetSize(width, height);
    img.setMagicNum(magicNum);
    img.setMaxVal(maxval);

    fread((void *)img.getAllPixel(), sizeof(Pixel), width * height, f_in);

    fclose(f_in);
}

void PNMreader::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to execute", PNMreader::SourceName()); 
    Logger::LogEvent(msg);
    PNMreader::Execute();
    sprintf(msg, "%s: done executing", PNMreader::SourceName());
    Logger::LogEvent(msg);
}

Color::Color(int w, int h, int r, int g, int b)
{
    width = w;
    height = h;
    red = r;
    green = g;
    blue = b;
}

void Color::Execute(void)
{
    int i, d;
    img.ResetSize(width, height);
    img.setMagicNum((char *)"P6");
    img.setMaxVal(255);
    
    d = width * height;
    for (i = 0; i < d; i++)
    {
        img.setPixel(red, green, blue, i);
    }

}

void Color::Update(void)
{
    char msg[128];
    sprintf(msg, "%s: about to execute", Color::SourceName()); 
    Logger::LogEvent(msg);
    Color::Execute();
    sprintf(msg, "%s: done executing", Color::SourceName());
    Logger::LogEvent(msg);
}
