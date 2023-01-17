/*
This is a calculator library header file
Developed by Anurag
*/

#include <stdio.h>

float add(float a, float b)
{
    float result = 0;
    result = a+b;
    return result;
}

float subtract(float a, float b)
{
    float result = 0;
    result = a-b;
    return result;
}

float multiply(float a, float b)
{
    float result = 0;
    result = a*b;
    return result;
}

float division(float a, float b)
{
    float result = 0;
    if (b==0) {
        printf("Invalid operation\n");
        return 0;
    }
    result = a/b;
    return result;
}