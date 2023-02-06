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
#include <string.h>
#include "quiz.h"

void get_user_profile(user_profile *pinfo)
{
    char name[USER_NAME_MAX];
    system("cls");
    printf("Enter your details:\n");
    printf("Name: ");
    scanf("%s", &name);
    strupr(name);

    FILE *fp = fopen(USER_PROFILE_FILE, "rb");
    if(fp == NULL)
    {
        printf("Profile database doesn't exist...create a new one");
        fp = fopen(USER_PROFILE_FILE, "wb+");
        if(fp == NULL)
        {
            printf("Failed to create Profile databse");
            getch();
            return;
        }
    }

    if(pinfo == NULL)
    {
        printf("Invalid profile");
        return;
    }

    user_profile up;
    size_t sz = 0;
    do
    {
        sz = fread(&up, sizeof(user_profile), 1, fp);
        if(sz != 0)
        {
            if(strcmp(name, up.name) == 0)
            {
                memcpy(pinfo, &up, sizeof(user_profile));
                return; 
            }   
        }                    
    } while (sz != 0);
    strcpy_s(pinfo->name, USER_NAME_MAX, name);
    pinfo->score = 0;
    pinfo->level = 1;
    fclose(fp);
}

void save_user_profile(user_profile *pinfo)
{
    FILE *fp = fopen(USER_PROFILE_FILE, "rb+");
    if(fp == NULL)
    {
        printf("Failed to open profile");
        return;
    }

    if(pinfo == NULL)
    {
        printf("Invalid profile");
        return;
    }

    user_profile up;
    size_t sz = 0;
    do
    {
        sz = fread(&up, sizeof(user_profile), 1, fp);
        if(sz != 0)
        {
            if(strcmp(pinfo->name, up.name) == 0)
            {
                fwrite(pinfo, sizeof(user_profile), 1, fp);
                break; 
            }   
        }                    
    } while (sz != 0);
    fclose(fp);
}