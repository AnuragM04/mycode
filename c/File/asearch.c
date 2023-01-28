#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/*
    asearch -s "text" file_name 
    search and replace: asearch -s "text" -r "new text" file_name
*/
void main(int argc, char* argv[])
{
    char text[100];
    if(argc != 4)
    {
        printf("Invalid command\n");
        printf("Usage: fcopy filename");
        exit(0);
    }
    FILE *sfp = fopen(argv[3], "r");
    if(sfp == NULL)
    {
        printf("Failed to open the source file: %s\n", argv[3]);
        exit(0);
    }

    while(fgets(text,100,sfp) != NULL)
    {
        
        if(strstr(text, argv[2]) != NULL)
        {
            printf("%s\n", text);
        }
    }
    fclose(sfp);
}