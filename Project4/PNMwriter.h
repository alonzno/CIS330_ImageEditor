#include <sink.h>

#ifndef PNMWRITER330
#define PNMWRITER330

class PNMwriter : public Sink
{
    public:
    void Write(char * filename);
};

#endif
