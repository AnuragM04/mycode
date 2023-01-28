#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int LI, RI, len=0;
    char word[20];
    printf("Enter any word: ");
    gets(word);
    while(word[len] != '\0')
    {
        len++;
    }
    LI = 0;
    RI = len-1;
    while(LI < RI)
    {
        if(word[LI] != word[RI])
        {
            printf("Not a Palindrome");
            exit(0);
        }
        LI++;
        RI--;
    }
    printf("It's a Palindrome");
}