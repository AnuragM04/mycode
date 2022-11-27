/* C4. Write a program to print numbers from 100 to 1 in descending order 
C5. Write a program to print numbers from 100 to 1 in descending steps of 2 */
#include <stdio.h>
// #include <conio.h>

int main()
{
    int n;
    int i;
    printf("Enter a maximum number: ");
    scanf("%d", &n);
    printf("Numbers till %d: ", n);
    for (i = n; i >= 0; i-=2) {
        printf("%d\n", i);
    }
    // getch();
    return 0;
}