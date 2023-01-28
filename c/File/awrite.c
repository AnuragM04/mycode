#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*  
    awrite.exe hello2.txt
    use ctrl+z to stop the input 
*/

void main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Invalid commandline arguments");
        exit(0);
    }
    int ch = 0;
    FILE *fp = fopen(argv[1],"w");
    if(fp == NULL)
    {
        printf("Failed to open the file: %s", argv[1]);
        exit(0);
    }
    printf("Enter text to write to file:\n");
    while(ch != EOF)
    {
        ch = getchar();
        fputc(ch, fp);
    }
    fclose(fp);
    // remove()
}