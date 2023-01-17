#include <stdio.h>

int a = 10;

void test1()
{
    int a = 1;
    printf("a=%d\n", a);
}

void test2()
{
    printf("a=%d\n", a);
}

int main()
{
    int a = 5;

    {
        int a = 11;
        printf("a=%d\n", a);
    }

    printf("a=%d\n", a);

    test1();
    test2();

    return 0;
}