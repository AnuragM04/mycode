// C.(college) Write a program which calculates Compound intrest
#include <stdio.h>
#include <math.h>

int main()
{
    float prcp_amt, rate, time, CI;
    printf("Enter Principal amount: ");
    scanf("%f", &prcp_amt);
    printf("Enter Time: ");
    scanf("%f", &time);
    printf("Enter Rate: ");
    scanf("%f", &rate);
    CI = prcp_amt*(pow(1+(rate/100), time));
    printf("Compound intrest = %f", CI);

    return 0;
}