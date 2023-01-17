#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char name[20];
    int age = 0;
    int height = 0;

    printf("Command has %d arguments\n", argc);

    for(int i = 0; i < argc; i++)
    {
        printf("Arguments %2d: %s\n", i+1, argv[i]);
    }

    strcpy(name, argv[1]);
    age = atoi(argv[2]);
    height = atoi(argv[3]);

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %d\n", height);
    
    return 0;
}