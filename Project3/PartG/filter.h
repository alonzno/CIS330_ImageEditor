#include <sink.h>
#include <source.h>

#ifndef FILTER330
#define FILTER330

class Filter : public Sink, public Source
{
    public:
    virtual void Execute(void) = 0;
    virtual void Update(void);
    virtual const char * FilterName() = 0;
    const char * SourceName() { return FilterName(); };
    const char * SinkName() { return FilterName(); };
};

class Shrinker : public Filter
{
    public:
    virtual void Execute(void);
    virtual void Update(void);
    const char * FilterName() { return "Shrinker"; };
};

class LRCombine : public Filter
{
    public:
    virtual void Execute(void);
    const char * FilterName() { return "LRConcat"; };
};

class TBCombine : public Filter
{
    public:
    virtual void Execute(void);
    const char * FilterName() { return "TBConcat"; };
};

class Mirror : public Filter
{
    public:
    virtual void Execute(void);
    virtual void Update(void);
    const char * FilterName() { return "Mirror"; };
};

class Rotate : public Filter
{
    public:
    virtual void Execute(void);
    virtual void Update(void);
    const char * FilterName() { return "Rotate"; };
};

class Subtract : public Filter
{
    public:
    virtual void Execute(void);
    const char * FilterName() { return "Subtract"; };
};

class Grayscale : public Filter
{
    public:
    virtual void Execute(void);
    virtual void Update(void);
    const char * FilterName() { return "Grayscale"; };
};

class Blur : public Filter
{
    public:
    virtual void Execute(void);
    virtual void Update(void);
    const char * FilterName() { return "Blur"; };
};

class Blender : public Filter
{
    private:
    double factor;

    public:
    virtual void Execute(void);
    void SetFactor(double fact) { factor = fact; };
    double getFactor() { return factor; };
    const char * FilterName() { return "Blender"; };
};


#endif
