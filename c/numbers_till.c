// C1. Write a program to take maximum number from user and print numbers from 1 to this number
#include <stdio.h>
// #include <conio.h>

int main()
{
    int n;
    int i = 0;
    printf("Enter a maximum number: ");
    scanf("%d", &n);
    printf("Numbers till ", n, ": ");
    while (i < n){
        printf("%d\n", i);
        i = i+1;
    }
    // getch();
    return 0;
}