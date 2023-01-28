#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int rtn = 0;
    char text[500], file_name[256];
    system("cls");
    printf("Enter a file name to wrtie in: ");
    gets(file_name);
    FILE *fp = fopen(file_name, "w");
    if(fp == NULL)
    {
        printf("Failed to open file for writing\n");
        return 0;
    }
    printf("Enter text:\n");
    do
    {
        gets(text);
        if(strlen(text) <= 0)
        {
            break;
        }
        strcat(text, "\n");
        rtn = fputs(text, fp);
        if(rtn < 0)
        {
            printf("Error in saving to file\n");
            break;
        }
    }while(rtn >= 0);
    fclose(fp);
    printf("Finished");
    return 0;
}