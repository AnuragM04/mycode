#include <stdio.h>

int main()
{
    int a = 5;
    int b = 7;
    int ar[] = { 5, 10, 25, 40, 45, 70, 90, 100, 540, 453 };
    char name[] = { 'a', 'n', 'u', 'r', 'a', 'g', 'm'};

    char *p;
    int *k = &a; 
    printf("a=%d\n", a);
    printf("*k=%d\n", *k);

    *k = 101;

    printf("*k=%d\n", *k);
    printf("a=%d\n", a);

    k = &b; 
    printf("*k=%d\n", *k);
    
    *k = 36;
    printf("*k=%d\n", *k);
    printf("b=%d\n", b);
    printf("a=%d\n", a);

    int num = sizeof(ar) / sizeof(int) ;

    k = &ar[0];

    for(int j = 0; j < num; j++)
    {
        printf("%ld - %d \n", k, *k);
        k++;
    }


    num = sizeof(name) / sizeof(char) ;

    p = &name[0];
    for(int j = 0; j < num; j++)
    {
        printf("%ld - %c \n", p, *p);
        p++;
    }

// A - 65
// a - 97
// Convert lower case to upper
// a - 97  z = 0 *p = 65 + 0  ~ A
// n - 110 z = 13 *p = 65 + 13 ~ N

    p = &name[0];
    for(int j = 0; j < num; j++)
    {
        int z = *p - 97;
        *p = 65 + z; 
        printf("%ld - %c \n", p, *p);
        p++;
    }

    for(int j = 0; j < num; j++)
    {
        printf("%c \n", name[j]);
    }
    return 0;
}
