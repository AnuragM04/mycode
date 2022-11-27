// C25. Write a program to take input numbers from user and print the maximum and minimum numbers.
#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,c;
    printf("Enter the numbers: \n");
    scanf("%d %d %d", &a, &b, &c);
    if ((a>b) && (a>c))
    {
        printf("%d is the max number",a);
    }
    else if (b>c)
    {
        printf("%d is the max number",b);
    } 
    else
    {
        printf("%d is the max number",c);
    }
    getch();
}
