#ifndef IMAGE330
#define IMAGE330

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

struct Image
{
    char magic_num[128];
    int w;
    int h;
    int max_val;
    Pixel *img;

    Image(void);
    //Image(char[128] m_num, int width, int height, int m_val, Pixel *i);
    Image(char *filename);
    Image(Image &i);
    void ResetSize(int width, int height);
    /*
    void WriteImage(char *filename);
    Image YellowDiagonal(Image *input);
    */
};

#endif

