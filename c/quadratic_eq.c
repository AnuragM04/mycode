// C.(college) Write a program which calculates roots of a quadratic equation.
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, root1, root2, root_term, den;
    printf("Enter vales of a,b,c:\n");
    scanf("%f%f%f", &a, &b, &c);

    root_term = sqrt((b*b)-4*a*c);
    den = 2*a;

    root1 = (-b + root_term)/den;
    root2 = (-b - root_term)/den;

    printf("Root 1 = %f\nRoot 2 = %f",root1,root2);
    return 0;
}