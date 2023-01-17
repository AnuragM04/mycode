#include <stdio.h>

int main()
{
    int age = 9;
    char kid = 'n';

    if(age < 10)
    {
        kid = 'y'; 
    }
    else
    {
        kid = 'n';
    }

    // Ternary operator
    kid = ( age < 10 ? 'y' : 'n');

    // nested
   kid = ( age < 10 ? ( age < 5 ? 'y' : 'a') : 'n');
}