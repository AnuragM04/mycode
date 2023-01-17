#include <stdio.h>

int main()
{
    int p = 0;
    int k = 10;

    p++;   // p = p + 1;
    printf("p = %d\n", p);
    
    ++p;               // p = p + 1
    printf("p = %d\n", p);

    // It prints p and after that statement it increments p
    printf("p = %d\n", p++);
    printf("p = %d\n", p);

    // It increments p first and then it prints
    printf("p = %d\n", ++p);
    printf("p = %d\n", p);

    k--;   // k = k - 1;
    printf("k = %d\n", k);
    
    --k;               // k = k - 1
    printf("p = %d\n");

    // It prints p and after that statement it increments p
    printf("p = %d\n", p++);
    printf("p = %d\n", p);

    // It increments p first and then it prints
    printf("p = %d\n", ++p);
    printf("p = %d\n", p);

}