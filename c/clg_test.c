#include <stdio.h>
#include<conio.h>
//#include <math.h>

/*
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
*/

void main()
{
    int n;    
    printf("enter values of n: ");
    scanf("%d", &n);
    int t[n];
    for(int i =0; i<n; i++)
    {
        t[i] = t[i-1]+ t[i-2];
        t[0] = 0;
        t[1] = 1;
        printf("%d\n",t[i]);
    }
}