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
#include "quiz.h"

void high_score_header()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    QUIZ\n");
    printf("\t\t\t\t\t\t\t\t\t\t_____________");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tHIGH SCORES\n\n\n\n");
    printf("\t\t\t%-5s %-40s %-25s %-20s %-20s\n\n", "RANK", "NAME", "DATE", "LEVEL", "SCORE");
}

void high_scores()
{
    high_score_header();

    // read profile.dbs file and find top 10 scorers and list rank, name, date, level, score.
    FILE *fp = fopen(USER_PROFILE_FILE, "rb");

    if(fp == NULL)
    {
        printf("Failed to open profile");
        return;
    }

    user_profile up;
    size_t sz = 0;
    int rank = 1;
    do
    {
        
        if((sz = fread(&up, sizeof(user_profile), 1, fp)) != 0)
        {
            printf("\t\t\t%-5d %-40s %-25s %-20d %-20d\n", rank++, up.name, up.date, up.level, up.score);
        }
        
    } while (sz != 0);

    fclose(fp);
}


