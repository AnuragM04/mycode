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
#include <memory.h>
#include "quiz.h"

void high_score_header()
{
    system("cls");
    printf("\033[1;33m"); 
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    QUIZ\n");
    printf("\t\t\t\t\t\t\t\t\t\t_____________");
    printf("\033[1;31m"); 
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tHIGH SCORES\n");
    printf("\t\t\t\t\t\t\t\t\t       _____________\n\n\n\n");
    printf("\033[1;32m"); 
    printf("\t\t\t\t%-5s  %-40s %-22s %-20s %-20s\n", "RANK", "NAME", "DATE", "LEVEL", "SCORE");
    printf("\t\t\t\t_______________________________________________________________________________________________________\n\n");
    printf("\033[0m");
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

    // Get total users based on file size
    fseek(fp, 0, SEEK_END); // seek to end of file
    long filesize = ftell(fp); // get current file pointer
    fseek(fp, 0, SEEK_SET); // seek back to beginning of file

    size_t sz = 0;
    int total_users = filesize/sizeof(user_profile);

    if(total_users <= 0)
    {
        printf("Invalid users in profile database\n");
        getch();
        fclose(fp);
        return;
    }

    user_profile* pup = (user_profile*) calloc(total_users, sizeof(user_profile));

    if(pup == NULL)
    {
        printf("Failed to create memory\n");
        getch();
        fclose(fp);
        return;
    }

    int user = 0;
    user_profile tup;
    do
    {
        if((sz = fread(&pup[user], sizeof(user_profile), 1, fp)) != 0)
        {
            ++user;
        }
    } while (sz != 0);

    fclose(fp);

    // Sort the users based on score.
    for(int i= 0; i < (total_users - 1); ++i) {
        for(int j = 0; j < ( total_users - i - 1); ++j) {
            if(pup[j].score < pup[j+1].score) {
                memcpy(&tup, &pup[j], sizeof(user_profile));
                memcpy(&pup[j], &pup[j+1], sizeof(user_profile));
                memcpy(&pup[j+1], &tup, sizeof(user_profile));
            }
        }
    }

    for(int i= 0; i < total_users; ++i) {
        printf("\t\t\t\t%-5d %-40s %-25s %-20d %-20d\n", i+1, pup[i].name, pup[i].date, pup[i].level, pup[i].score);
    }

    free(pup);

    getch();
}


