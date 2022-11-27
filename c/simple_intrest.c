// C.(college) Write a program to calculate simple intrest.
#include <stdio.h>

int main()
{
    int p, t, r;
    float si;
    printf("ENter the values of P, T, R: \n");
    scanf("%d %d %d", &p, &t, &r);
    si = (p*t*r)/100;
    printf("Simple intrest: %f",si);
    return 0;
}