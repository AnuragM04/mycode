#include<stdio.h>

int main()
{
    int a=1;
    float b=2;
    char c='Z';
    short d=33;
    double e=44;
    int my_nums[] = {25, 50, 75, 100};
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(e));
    printf("%d\n", sizeof(my_nums));

    return 0;
}