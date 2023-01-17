#include <stdio.h>
//#include <file.h>


int main()
{
    FILE *fp = fopen("hello.txt", "r");

    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return 0;
    }

    printf("Reading File:\n");

    char ch;

    while(42)
    {
        ch = fgetc(fp);
        if(ch == EOF)
        {
            printf("\nFinished\n");
            break;
        } 
        printf("%c", ch);
    }

    fclose(fp);
}