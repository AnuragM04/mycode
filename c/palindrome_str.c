#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int i, len=0;
    char word[50], *li, *ri;
    printf("Enter any word: ");
    scanf("%s", &word);
    li = &word[0];
    len = strlen(word);
    ri = &word[len-1];
    for(i=0; i<len; i++)
    {
        if(*li != *ri)
        {
            printf("\nGiven word isn't a Palindrome");
            exit(0);
        }
        li++;
        ri--;
    }
    printf("\nGiven word is a Palindrome");
}