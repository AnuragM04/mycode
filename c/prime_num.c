// C.(college) Write a program to check whether the given number is prime or not.
#include <stdio.h>

//void main()
int main()
{
    int n,i,m=0,flag=0;
    //clrscr();
    printf("Enter the number to check whether the number is prime or not\n");
    scanf("%d",&n);
    m = n/2;
    for(i=2; i<=m; i++) {
        if(n%i==0){
            printf("Number is not a prime");
            flag = 1;
            break;
        }
    }
    if (flag==0){
        printf("number is a prime number");
    }
    return 0;
    //getch();
}