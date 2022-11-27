// C2. Write a program to print odd numbers from 1 to 100

#include <stdio.h>

int main()
{
    int n;
    int i = 1;
    printf("Enter a maximum number: ");
    scanf("%d", &n);
    printf("Numbers till", n, ": ");
    while (i < n){
        printf("%d\n", i);
        i = i+2;
    }
    // getch();
    return 0;
}