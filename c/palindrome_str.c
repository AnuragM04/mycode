#include <stdio.h>
#include <string.h>

void main()
{
    char words[50];
    int word_size=0;
    word_size = strlen(words);
    printf("Enter size of list: \n");
    scanf("%d", &word_size);
    if (word_size<=0)
    {
        printf("Invalid size");
        return 0;
    }
    for (int i=0; i<word_size; i++)
    {
        printf("Element %2d:", i+1);
        scanf("%c", &words[i]);
    }

    for (int i=0; i<word_size; i++)
    {
        
    }
   
}