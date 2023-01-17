#include <stdio.h>
#include <malloc.h>

#define MEM_SIZE 10


int main()
{
    int k = 0;
    char ch = 0;
    char *pBuff = NULL;

    printf("k=%d ch=%d\n", k, ch);

   pBuff = (char *) malloc(MEM_SIZE);
//   memset(pBuff, 0, sizeof(pBuff));
//    void *vPtr = calloc(MEM_SIZE, sizeof(char));
//    pBuff = (char *) vPtr;
//    pBuff = (char *) calloc(MEM_SIZE, sizeof(char));
    if(pBuff == NULL)
    {
        printf("Failed to allocate memory %d bytes", MEM_SIZE);
        return 0;
    }

    char *tBuff = pBuff;

    for(int i = 0; i < MEM_SIZE; i++)
    {
        printf("%c\n", *tBuff);
        *tBuff = 'a';
        tBuff++;
    }

    pBuff = (char *) realloc(pBuff, MEM_SIZE + 10);

    for(int i = 0; i < MEM_SIZE + 10; i++)
    {
        printf("%c\n", *pBuff);
        pBuff++;
    }

    free(pBuff);

//  printf("%c\n", *pBuff);  dangling pointer... pointing to something which is already freed or doesn't have permission to access

    return 0;
}
