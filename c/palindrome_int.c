#include <stdio.h>

int main()
{
    int num=0, num1=0, remainder=0, reverse=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    num1 = num;

    while(num>0)
    {
        remainder = num%10;
        reverse = (reverse*10)+remainder;
        num = num/10;
    }
    printf("Reverse number: %.2d\n", reverse);
    if(reverse == num1)
    {
        printf("Number's a Palindrome!");
    }
    else
    {
        printf("Number's not a Palindrome");
    }

    return 0;
}