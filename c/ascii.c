// C6. Write a program to print all ascii code and ascii characters.
#include<stdio.h>

void main()
{
    for(int i=0; i<256; i++) {
        printf("%d %c \n", i, i);
    }
    getch();
}