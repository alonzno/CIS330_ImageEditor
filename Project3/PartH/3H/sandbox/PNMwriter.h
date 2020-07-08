#include <sink.h>
#include <string>

#ifndef PNMWRITER330
#define PNMWRITER330

class PNMwriter : public Sink
{
    public:
    const void Write(const std::string &filename);
    const char * SinkName() { return "PNMwriter"; };
};

class CheckSum : public Sink
{
    public:
    const void OutputCheckSum(const std::string &filename);
    const char * SinkName() { return "CheckSum"; };
};

#endif
