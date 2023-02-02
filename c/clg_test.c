#include <stdio.h>
#include<conio.h>

void main()
{
    int nums[5], sum = 0, i;
    int *p;
    p = &nums[0];   // or can assign as p = &nums; -- this will give a warning: assignment to 'int *' from incompatible pointer type 'int (*)[5]'
    printf("Enter 5 numbers:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&nums[i]);
    }
    for(i=0;i<5;i++)
    {
        sum = sum+*p;
        p++;
    }
    printf("Sum: %d\n", sum);
}