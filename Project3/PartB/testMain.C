#include <stdio.h>
#include <functions.h>
#include <image.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_filename> <output_filename>", argv[0]);
    }

    Image img, img2, img3, img4;
    ReadImage(argv[1],img);
    ReadImage(argv[1],img3);
    HalfSize(img, img2);
    TopBottomCombine(img, img3, img4);
    WriteImage(argv[2], img4);

}
