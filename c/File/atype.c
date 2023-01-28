#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
   
    if(argc < 2)
    {
        printf("Invalid command\n");
        printf("Usage: ftype filename");
        exit(0);
    }
    for(int i=1; i < argc; i++)
    {
        int ch = 0;
        printf("\n%s:\n", argv[i]);
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL)
        {
            printf("Failed to open the file: %s\n", argv[i]);
            exit(0);
        }
        while(ch != EOF)
        {
            ch = fgetc(fp);
            printf("%c", ch);
        }
        fclose(fp);        
    }
}