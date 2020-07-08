#include <image.h>

#ifndef SOURCE330
#define SOURCE330

class Source
{
    protected: 
    Image img;
    virtual void Execute(void) = 0;

    public:
    virtual void Update(void){};
    Image * GetOutput(void);
    Source() {img.setCallback(this); };    
    virtual const char * SourceName() = 0;
};

#endif
