// C1.program to print "hello" and a small experiment on return function.
#include <stdio.h>
#include <conio.h>

int main()
{
    int a = 10;
    char name[] = "hello";
    float f = 3.3;
    printf("a = %d, name = %s, f = %f \n", a, name, f);
    a = a-1;
    if(a == 9)
        return 0;
    else if (a == 10)
    {
        return 1;
    }
    getch();
    return 0;
}