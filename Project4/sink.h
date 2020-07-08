#include <image.h>

#ifndef SINK330
#define SINK330

class Sink
{
    protected:
    Image * img1;
    Image * img2;

    public:
    void SetInput(Image * i);
    void SetInput2(Image * i);
};

#endif
