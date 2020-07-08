#include <source.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#ifndef PNMREADER330
#define PNMREADER330

class PNMreader : public Source
{
    public:
    char * f_name;

    public:
    PNMreader(const std::string &filename);
    ~PNMreader();
    virtual void Execute(void);
    virtual void Update(void);
    const char * SourceName() { return "PNMreader"; };
};

class Color : public Source
{
    private:
    int width;
    int height;
    int red; 
    int green;
    int blue;

    public:
    Color(int w, int h, int r, int g, int b);
    virtual void Execute(void);
    virtual void Update(void);
    const char * SourceName() { return "Color"; };
};
#endif
