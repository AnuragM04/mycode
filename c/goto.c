#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, guess = 0;
    char ch = 'y';

    printf("Enter any number between 0 to 5:");

    guess = rand() % 5;

    for(int j = 0; j < 5; j++)
    {
        scanf("%d", &num);
        if(num == guess)
            goto success;
    }

    printf("Do you want to try again?\n");
    scanf("%c", &ch);

    if(ch == 'y')
    {
        for(int j = 0; j < 100; j++)
        {
            scanf("%d", &num);
            if(num == guess)
                goto success;

        }
    }
    else
    {
        goto failure;
    }

success:
    printf("I successfully guessed your number: %d\n", num);
    printf("Bye\n");
    return 0;


failure:
    printf("Sorry I couldn't guess your number\n");
    printf("Bye\n");
    return 0;
}