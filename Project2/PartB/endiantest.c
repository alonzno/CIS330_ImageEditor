#include <stdio.h>

int main()
{
    int testInt = 1;
    char *c = (char*) &testInt;
    if(*c)
    {
        printf("little endian\n");
    }
    else
    {
        
        printf("big endian\n");
    }
}
