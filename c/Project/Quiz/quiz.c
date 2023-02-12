/*
                        QUIZ PROGRAM
                SREYAS ENGINEERING COLLEGE

                        DEVELOPED
                            
                            BY

                        M ANURAG 
                        B AKSHITHA
                        A SIDDHARTHA
                        B JAHNAVI
                        K ARYAN
                        B NIKETH
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

extern void start_quiz();
extern void high_scores();


int main()
{
    int choice = 0;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWELCOME TO QUIZ GAME\n");
        printf("\t\t\t\t\t\t\t\t____________________________________\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t1. Start\n");
        printf("\n\n\t\t\t\t\t\t\t\t2. High Scores\n");        
        printf("\n\n\t\t\t\t\t\t\t\t3. Quit\n");
        printf("\n\n\t\t\t\t\t\t\t\tEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start_quiz();
            break;
        case 2:
            high_scores();
            break;
        case 3:
            printf("\n\n\t\t\t\t\t\t\t\t!!! THANK YOU !!!\n\n\t\t\t\t\t\t\t\t!!! BYE !!!");
            return 0;
        default:
            printf("\n\n\t\t\t\t\t\t\t\tInvalid Choice");
            break;
        }
    }while(choice <= 3);
    return 0;
}