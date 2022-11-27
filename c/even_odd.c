// C2,3. Write a program to print even numbers and odd numbers from 1 to 100 (optimised)
#include<stdio.h>

void main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a % 2 == 0) {
        printf("%d is even", a);
    }
    else {
        printf("%d is odd", a);
    }
}