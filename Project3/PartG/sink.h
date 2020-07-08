#include <image.h>

#ifndef SINK330
#define SINK330

class Sink
{
    protected:
    const Image * img1;
    const Image * img2;

    public:
    void SetInput(Image * i);
    void SetInput2(Image * i);
    virtual const char * SinkName() = 0;
};

#endif
