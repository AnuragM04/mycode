#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
    int ch = 0;
    if(argc != 3)
    {
        printf("Invalid command\n");
        printf("Usage: fcopy filename");
        exit(0);
    }
    FILE *sfp = fopen(argv[1], "r");
    FILE *dfp = fopen(argv[2], "w");
    if(sfp == NULL)
    {
        printf("Failed to open the source file: %s\n", argv[1]);
        exit(0);
    }
    if(dfp == NULL)
    {
        printf("Failed to open the destination file: %s\n", argv[2]);
        exit(0);
    }
    while(ch != EOF)
    {
        ch = fgetc(sfp);
        fputc(ch, dfp);
    }
    fclose(sfp);
    fclose(dfp);
    printf("Succesfully copied");
}