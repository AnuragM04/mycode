#include <stdio.h>
#include <conio.h>

// int swap(int *, int *);

void swap1(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

/* Below Two methods work only for c++.
void swap3(int &x, int &y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

void swap4(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}
*/
void main()
{
    int a = 10, b = 20;
    printf("Before swapping: a=%d b=%d", a, b);
    // swap1(&a,&b);
    // swap2(&a,&b);
    swap3(a,b);
    // swap4(a,b);
    printf("\nAfter swapping a=%d b=%d", a, b);
}