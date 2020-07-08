#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_filename> <output_filename>" argv[0]);
    }

    Image img;
    ReadImage(argv[1],img);
    WriteImage(argv[2], img);

}
