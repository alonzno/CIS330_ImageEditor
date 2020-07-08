#include <string.h>
#ifndef IMAGE330
#define IMAGE330
class Source;
enum ERROR_CODES
{
    MALLOC_ERROR = -1,
    STREAM_ERROR = -2,
    BAD_INPUT = -3
};

struct Pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Image
{   
    private:
    char magic_num[128];
    int w;
    int h;
    int max_val;
    Source *source;
    Pixel *img;

    public:
    Image(void);
    Image(char *filename);
    Image(Image &i);
    virtual ~Image();
    void ResetSize(int width, int height);
    
    int getWidth() const { return w; };
    int getMaxVal() const { return max_val; };
    int getHeight() const { return h; };
    char * getMagicNum() const { return (char *) magic_num; };
    Pixel * getAllPixel() const { return img; };
    Pixel getPixel(int p) const { return img[p]; };

    void setWidth(int width) { w = width; };
    void setHeight(int height) { h = height; };
    void setMaxVal(int m_val) { max_val = m_val; };
    void setMagicNum(char * m_num) { strcpy(magic_num, m_num); };
    void setPixel(int r, int g, int b, int p);
    void setPixel(int p, Pixel pix);
    void setCallback(Source *s) { source = s; };

    void Update (void) const;
};

#endif

