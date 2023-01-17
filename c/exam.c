#include<stdio.h>
/*int main()
{
    int x=0;
    if(x==1)
    if(x==0)
    printf("inside if\n");
    else
    printf("inside else if\n");
    else
    printf("inside else\n");
}*/

/*int main()
{
    int a;
    if(a=!printf("Goodluck ")){
        printf("Hello");
        printf("%d", a);
    }
    else
    {
        printf("Woeld");
        printf("%d", a);
    }
}*/

/*void main() 
{
   int year;
   printf("Enter a year: ");
   scanf("%d", &year);
   if (year % 400 == 0) {
      printf("%d is a leap year.", year);
   }
   else if (year % 100 == 0) {
      printf("%d is not a leap year.", year);
   }
   else if (year % 4 == 0) {
      printf("%d is a leap year.", year);
   }
   else {
      printf("%d is not a leap year.", year);
   }
}*/

void main()
{
    int purchases;
    printf("Enter number of purchases: ");
    scanf("%d", &purchases);
    if(purchases>0)
    {
        if(purchases==1)
        {
            printf("You're in SILVER category\n");
        }
        else if(purchases==2)
        {
            printf("You're in GOLD category\n");
        }
        else if(purchases>=3)
        {
            printf("You're in PLATINUM category\n");
        }
    }
    else
    {
        printf("Invalid amount of purchases");
    }
}