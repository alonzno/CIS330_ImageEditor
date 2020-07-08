#include <stdio.h>
#include <stdlib.h>

enum EXIT_CODES
{
    FILE_NOT_FOUND = 1,
    MEMORY_ALLOCATION = 2
};

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stdout, "Usage: %s <input_name> <output_name>", argv[0]);
    }

    FILE *f_in = fopen(argv[1],"r");

    if (f_in == NULL)
    {
        fprintf(stderr, "No such file found named \"%s\"\n", argv[1]);
        exit(FILE_NOT_FOUND);
    }
    
    FILE *f_out = fopen(argv[2],"w");

    if (f_out == NULL)
    {
        fprintf(stderr, "No such file found named \"%s\"\n", argv[2]);
        exit(FILE_NOT_FOUND);
    }

    int *corner5 = malloc(5 * 5 * sizeof(int));

    if (corner5 == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(MEMORY_ALLOCATION);
    }

    int i;
    int j;
    for ( i = 0; i < 5; i++)
    {
        fread((void *)(corner5 + (5*i)), sizeof(int), 5, f_in);
        fseek(f_in, (long) 5*sizeof(int), SEEK_CUR);
    }

    for (int i = 0; i < 25; i++)
    {
        fprintf(f_out, "%d\n", corner5[i]);
    }

    fclose(f_in);
    fclose(f_out);
    free(corner5);
    
    return 0;
}
