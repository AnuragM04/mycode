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
#include <windows.h>
#include <time.h>
#include "quiz.h"

extern void get_user_profile(user_profile *pinfo);
extern void save_user_profile(user_profile *pinfo);

void get_difficulty_text(int level, char* difficulty)
{
    switch (level)
    {
    case 1:
    case 2:
        strcpy_s(difficulty, DIFFICULTY_MAX, "EASY"); 
        break;
    case 3:
    case 4:
        strcpy_s(difficulty, DIFFICULTY_MAX, "MEDIUM"); 
        break;
    case 5:
    case 6:
        strcpy_s(difficulty, DIFFICULTY_MAX, "HARD"); 
        break;
    default:
        strcpy_s(difficulty, DIFFICULTY_MAX, "EASY"); 
        break;
    }
}

void parse_info(char* pbuffer, quiz_info* pqi)
{
    int i = 0;
    char values[6][OPTION_MAX] = {0};
    char *str = strtok(pbuffer, ","); 
    if(str != NULL)
    {
        strcpy_s(pqi->question, QUESTION_MAX, str);
        str = strtok(NULL, ",\n");
    }
    while(str != NULL)
    {
        strcpy_s(values[i], OPTION_MAX, str);
        i++;
        str = strtok(NULL, ",\n");
    }
    strcpy_s(pqi->difficulty, DIFFICULTY_MAX, values[0]);
    strcpy_s(pqi->optionA, OPTION_MAX, values[1]);
    strcpy_s(pqi->optionB, OPTION_MAX, values[2]);
    strcpy_s(pqi->optionC, OPTION_MAX, values[3]);
    strcpy_s(pqi->optionD, OPTION_MAX, values[4]);
    strcpy_s(pqi->answer, OPTION_MAX, values[5]);
}

//  This function returns 10 random question based on the current User Level.
void get_questions(int level, quiz_info* pqi)
{
    //  Get Difficulty text for this level.
    char difficulty[DIFFICULTY_MAX];
    get_difficulty_text(level, difficulty);

    int question = 0;
    char buffer[760];
    FILE *fp = fopen(QUIZ_SPORTS_FILE, "r");
    if(fp == NULL)
    {
        printf("Failed to open file");
        getch();
        return;
    }
    quiz_info qi;
    //  
    while(fgets(buffer,760,fp) != NULL)
    {
        //  Parses each line of string and gets question, difficulty, options and answer.
        parse_info(buffer, &qi);
        //  Check if this question matches difficulty level required.
        if(strcmp(qi.difficulty, difficulty) == 0)
        {
            //  Copy the question to the required 10 questions.
            memcpy(pqi+question, &qi, sizeof(quiz_info));
            question++;
        }
        //  Checks if we have reached the Max questions required(10).
        if(question >= MAX_QUESTIONS_LEVEL)
        {
            break;
        }
    }

    fclose(fp);
}

int show_quiz(int question, quiz_info* qi, user_profile* pup, int correct)
{
    system("cls");
    char difficulty[DIFFICULTY_MAX];
    get_difficulty_text(pup->level, difficulty);

    printf("\n\n\t\t\t\t\t\t\t\t\t\t    QUIZ\n");
    printf("\t\t\t\t\t\t\t\t\t\t_____________");
    printf("\nUSER       : %s", pup->name);
    printf("\nLEVEL      : %d", pup->level);
    printf("\nHIGH-SCORE : %d", pup->score);
    printf("\nSCORE      : %d", correct*pup->level);
    printf("\nDIFFICULTY : %s", difficulty);
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tQuestion - %d\n\n\n\n", question);
    printf("\n\n\t\t\t\t%s\n\n", qi->question);
    printf("\n\n\t\t\t\t\t\tA. %s\t\t\t\t\t\tB. %s\n\n", qi->optionA, qi->optionB);
    printf("\n\n\t\t\t\t\t\tC. %s\t\t\t\t\t\tD. %s\n\n", qi->optionC, qi->optionD);
    printf("\n\n\t\t\t\t\t\tEnter your choice: ");
    int timer = QUIZ_TIMER;
    
    do
    {
        printf("\b\r\t\t\t\t\t\t\t\t\t\t\b\b%2ds\r\t\t\t\t\t\t\t\t\t", timer);
        Sleep(1000);
        if(kbhit())
        {
            int key = getche();
            char choice;
            char option[OPTION_MAX];
            switch (key)
            {
            case 27: // esc key.
                printf("\nDo you want to quit game?");
                scanf("%s", &choice);
                if(choice == 'y' || choice == 'Y')
                {
                    return -1;
                }
                break;
            case 65: // 'A'
            case 97: // 'a'
                strcpy_s(option, OPTION_MAX, qi->optionA);
                break;
            case 66: // 'B'
            case 98: // 'b'
                strcpy_s(option, OPTION_MAX, qi->optionB);
                break;
            case 67: // 'C'
            case 99: // 'c'
                strcpy_s(option, OPTION_MAX, qi->optionC);
                break;
            case 68: // 'D'
            case 100: // 'd'
                strcpy_s(option, OPTION_MAX, qi->optionD);
                break;
            default:
                // User has entered wrong answer.
                return 0;
                break;
            }
            if(strcmp(option, qi->answer) == 0)
            {
                //  User has entered correct answer.
                return 1;
            }
            else
            {  
                //  User has entered wrong answer.
                return 0;
            }
        }
        timer--;
    }while (timer > 0);
    //  Wrong answer
    return 0;
}

void start_quiz()
{   
    int correct = 0;
    user_profile up;
    get_user_profile(&up);

    //  Allocate Dynamic Memory for 10 questions.
    quiz_info *pqi = (quiz_info *) calloc(MAX_QUESTIONS_LEVEL, sizeof(quiz_info));
    if(pqi == NULL)
    {
        printf("Failed to allocate memory\n");
        return;
    }
    get_questions(up.level, pqi);
    for(int q=0; q<MAX_QUESTIONS_LEVEL; q++)
    {
        int ret = show_quiz(q+1, &pqi[q], &up, correct);
        if(ret < 0)
        {
            //  User wants to quit
            break;
        }
        else if(ret == 1)
        {
            //  User has entered correct answer.   
            correct++;
        }
    }    
    free(pqi);

    int actual_score = correct*up.level;

    if(actual_score > up.score)
    {
        if(correct != MAX_QUESTIONS_LEVEL)
        {
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t!!! CONGRATULATIONS !!!\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t!!! YOU HAVE IMPROVED YOUR HIGH SCORE !!!");
            fflush(stdin);
            getch();
        }
        up.score = actual_score;
        time_t t = time(NULL);
        struct tm tm;
        tm = *localtime(&t);
        sprintf(up.date, "%.2d/%.2d/%.4d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);        
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOU SCORED : %d\n\n\n", actual_score);
        printf("\t\t\t\t\t\t\t\t\t%d CORRECT ANSWERS", correct);
        fflush(stdin);
        getch();
    }

    if(correct == MAX_QUESTIONS_LEVEL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t!!! CONGRATULATIONS !!!\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t!!! YOU SUCCESSFULLY COMPLETED THIS LEVEL !!!");
        fflush(stdin);
        getch();
        up.level++;
    }

   save_user_profile(&up);
}