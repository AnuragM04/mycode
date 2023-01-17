#include<stdio.h>
#include<string.h>

/* this string func shows that the character location is always numbered in order 
from left to right after counting even with strrchr() func */ 
void main()
{
    char s[20];
    char *p;
    printf("Enter string 1: ");
    gets(s);
    p='\0';
    p=strrchr(s,'N');
    if (*p==0)
        printf("\nChar R doesn't exist");
    else
        printf("\n'N' found in %d position",p-s+1);
}