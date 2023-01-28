#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char word[50], *lp, *rp;
    printf("Enter any word: ");
    gets(word);
    lp = &word[0];
    rp = lp + strlen(word) - 1; 
    if(strlen(word) <= 0)
    {
        printf("Invalid word");
        exit(0);
    }
    while(lp != rp)
    {
        if(*lp != *rp)
        {
            printf("%s is not a Palindrome", word);
            exit(0);
        }
        lp++;
        rp--;
    }
    printf("%s is a Palindrome", word);
}