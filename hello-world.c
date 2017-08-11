#include <stdio.h>

int main(int argn, char **argv)
{
    int i;
    for (i = 1; i < argn ; i++)
    {
        printf("Hello World %s \n",argv[i]);
    }

    return 0;
}