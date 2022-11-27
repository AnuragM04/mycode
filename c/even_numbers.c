// C3. Write a program to print even numbers from 1 to 100
#include <stdio.h>

int main()
{
    int n;
    int i = 0;
    printf("Enter a maximum number: ");
    scanf("%d", &n);
    printf("Numbers till %d: ", n);
    while (i <= n){
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
        i++;
    }
    // getch();
    return 0;
}