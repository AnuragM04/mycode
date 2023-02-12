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
#include <time.h>
#include "quiz.h"

//  Get User Profile from Profile database.
//  It also creates Profile database if it doesn't exist.
void get_user_profile(user_profile *pinfo)
{
    char name[USER_NAME_MAX];
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    QUIZ\n");
    printf("\t\t\t\t\t\t\t\t\t\t_____________");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your details:\n\n");
    printf("\t\t\t\t\t\t\t\t\tName: ");
    scanf("%s", &name);
    strupr(name);

//  Fill User Profile with Default values incase Profile doesn't exist.
    strcpy_s(pinfo->name, USER_NAME_MAX, name);
    pinfo->score = 0;
    pinfo->level = 1;

//  Open Profile database to get User Profile.
    FILE *fp = fopen(USER_PROFILE_FILE, "rb");
    if(fp == NULL)
    {
        printf("Profile database doesn't exist...create a new one");
        //  Create new User Profile database as it doesn't exist.
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
                //  Copy User Profile from Profile database to requested struct object.
                memcpy(pinfo, &up, sizeof(user_profile));
                fclose(fp);
                return; 
            }   
        }                    
    } while (sz != 0);

    fclose(fp);
}

//  Saves User Profile to Profile database.
void save_user_profile(user_profile *pinfo)
{
    FILE *fp = fopen(USER_PROFILE_FILE, "rb+");
    if(fp == NULL)
    {
        printf("Failed to open profile");
        getch();
        return;
    }

    if(pinfo == NULL)
    {
        printf("Invalid profile");
        getch();
        return;
    }

    user_profile up;
    size_t sz = 0;
    size_t upsize = sizeof(user_profile);
    do
    {
        sz = fread(&up, upsize, 1, fp);
        if(sz != 0)
        {
            //  Compare User name to User Profile read from database.
            if(strcmp(pinfo->name, up.name) == 0)
            {   
                //  We found a Match of Profile Name, but the File pointer has moved ahead.
                //  The File pointer has to move back by one block to update Match User Profile.
                fseek(fp, -upsize, SEEK_CUR);
                fwrite(pinfo, upsize, 1, fp);
                fclose(fp);
                return;
            }   
        }                    
    } while (sz != 0);

    //  User Profile is wrtten at the end of the File if its not present.
    fwrite(pinfo, upsize, 1, fp);

    fclose(fp);
}

// void generate_user_profile()
// {
//     FILE *fp = fopen(USER_PROFILE_FILE, "w+");
//     if(fp == NULL)
//     {
//         printf("Failed to open profile");
//         return;
//     }
//     time_t t = time(NULL);
//     struct tm tm;
// 	   tm = *localtime(&t);
//     user_profile up;
//     for(int i=0; i<100; i++)
//     {
//         up.level = rand()%5+1;
//         up.score = rand()%500;
//         sprintf(up.date, "%.2d/%.2d/%.4d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
//         sprintf(up.name, "Sreyas%d", i+1);
//         fwrite(&up, sizeof(user_profile), 1, fp);   
//     }
    
//     fclose(fp);
// }