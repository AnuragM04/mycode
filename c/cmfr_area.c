// C.(College) Write a program to calculate circumference and area of circle.
#include <stdio.h>

int main()
{
    float rad, cmfr, area, PI;
    printf("Enter the radius of circle: ");
    scanf("%f", &rad);
    PI = 3.142;
    cmfr = 2*PI*rad;
    area = PI*rad*rad;
    printf("Circumference of Circle: %f\n""Area of Circle: %f", cmfr, area);
    return 0;
}