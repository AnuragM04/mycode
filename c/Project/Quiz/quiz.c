/*
                        QUIZ PROGRAM
                SREYAS ENGINEERING COLLEGE

                        DEVELOPED
                            
                            BY

                        M ANURAG 
                        B AKSHITHA
                        A SIDDHARTHA
                        M JAHNAVI
                        K ARYAN
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

extern void start_quiz();
extern void high_scores();

void show_banner()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\033[1;33m"); 
    printf("\t\t\t\t\t\t\t\t  #####     #     #    ###    #######\n");
    printf("\t\t\t\t\t\t\t\t #     #    #     #     #          #\n");
    printf("\t\t\t\t\t\t\t\t #     #    #     #     #         #\n");   
    printf("\t\t\t\t\t\t\t\t #     #    #     #     #        #\n");    
    printf("\t\t\t\t\t\t\t\t #   # #    #     #     #       #\n");     
    printf("\t\t\t\t\t\t\t\t #    #     #     #     #      #\n");      
    printf("\t\t\t\t\t\t\t\t  #### #     #####     ###    #######\n"); 
    printf("\033[0m");
    printf("\n\n\n\n");
    printf("\033[1;32m");
    printf("\t\t\t\t\t\t\t\t\t           BY\n"); 
    printf("\n\n\n\n");
    printf("\033[1;31m"); 
    printf("\t\t\t\t\t\t\t\t\t\t%-30s\n\n", "M ANURAG"); 
    printf("\t\t\t\t\t\t\t\t%-30s%-30s\n\n", "B AKSHITHA", "M JAHNAVI"); 
    printf("\t\t\t\t\t\t\t\t%-30s%-30s\n\n", "A SIDDHARTHA", "K ARYAN"); 
    printf("\033[0m");
    Sleep(3000);                          
}

void thankyou_banner()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\033[1;32m");
    printf("\t\t\t\t\t\t\t #######                                #     # ####### #     # \n");
    printf("\t\t\t\t\t\t\t    #    #    #   ##   #    # #    #     #   #  #     # #     # \n");
    printf("\t\t\t\t\t\t\t    #    #    #  #  #  ##   # #   #       # #   #     # #     # \n");
    printf("\t\t\t\t\t\t\t    #    ###### #    # # #  # ####         #    #     # #     # \n");
    printf("\t\t\t\t\t\t\t    #    #    # ###### #  # # #  #         #    #     # #     # \n");
    printf("\t\t\t\t\t\t\t    #    #    # #    # #   ## #   #        #    #     # #     # \n");
    printf("\t\t\t\t\t\t\t    #    #    # #    # #    # #    #       #    #######  #####  \n");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t                ######  #     # #######                         \n");
    printf("\t\t\t\t\t\t\t                #     #  #   #  #                               \n");
    printf("\t\t\t\t\t\t\t                #     #   # #   #                               \n");
    printf("\t\t\t\t\t\t\t                ######     #    #####                           \n");
    printf("\t\t\t\t\t\t\t                #     #    #    #                               \n");
    printf("\t\t\t\t\t\t\t                #     #    #    #                               \n");
    printf("\t\t\t\t\t\t\t                ######     #    #######                         \n");
    printf("\033[0m");
    Sleep(1000);                          
}


int main()
{

    show_banner();

    int choice = 0;

    do
    {
        system("cls");
        fflush(stdin);
        printf("\033[1;33m"); 
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWELCOME TO QUIZ GAME\n");
        printf("\t\t\t\t\t\t\t\t____________________________________\n\n");
        printf("\033[0m");
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
            thankyou_banner();
            return 0;
        default:
            printf("\n\n\t\t\t\t\t\t\t\tInvalid Choice");
            getch();
            break;
        }

        choice = 0;

    }while(choice <= 3);

    return 0;
}