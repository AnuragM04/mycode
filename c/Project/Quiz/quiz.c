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

extern void easy_quiz();

int main()
{
    int choice = 0;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\tWELCOME TO QUIZ GAME\n");
        printf("\t\t\t\t\t\t____________________________________");
        printf("\n\n\t\t\t\t\t\t1. Easy");
        printf("\n\n\t\t\t\t\t\t2. Medium");
        printf("\n\n\t\t\t\t\t\t3. Hard");
        printf("\n\n\t\t\t\t\t\t4. High Scores");        
        printf("\n\n\t\t\t\t\t\t5. Quit Game");
        printf("\n\n\t\t\t\t\t\tEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            easy_quiz();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("\n\n\t\t\t\t\t\tBye");
            return 0;
        default:
            printf("\n\n\t\t\t\t\t\tInvalid Choice");
            getch();
            break;
        }
    }while(choice <= 3);
    return 0;
}