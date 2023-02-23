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
    }

    do
    {
        str = strtok(NULL, ",\n");
        if(str != NULL)
        {
            strcpy_s(values[i], OPTION_MAX, str);
            i++;
        }

    } while (str != NULL);
    
    strcpy_s(pqi->difficulty, DIFFICULTY_MAX, values[0]);
    strcpy_s(pqi->optionA, OPTION_MAX, values[1]);
    strcpy_s(pqi->optionB, OPTION_MAX, values[2]);
    strcpy_s(pqi->optionC, OPTION_MAX, values[3]);
    strcpy_s(pqi->optionD, OPTION_MAX, values[4]);
    strcpy_s(pqi->answer, OPTION_MAX, values[5]);
}

//  This function returns 10 random question based on the current User Level.
void get_questions(int level, quiz_info* fqi)
{
    //  Get Difficulty text for this level.
    char difficulty[DIFFICULTY_MAX];
    get_difficulty_text(level, difficulty);

    char csvfiles[QUIZ_MAX_FILES][50] = { QUIZ_SPORTS_FILE, QUIZ_GEO_FILE, QUIZ_GENK_FILE, QUIZ_HISTORY_FILE };
    
    int totalquestions = MAX_QUESTIONS_LEVEL;
    int question = 0;
    char buffer[700];

    quiz_info* pqi = (quiz_info *) calloc(MAX_QUESTIONS_LEVEL, sizeof(quiz_info));

    if(pqi == NULL)
    {
        printf("Failed to allocate memory\n");
        getch();
        return;
    }

    quiz_info qi;

    // Get all quiz questions with difficulty for this level from all files into dynamic memory
    for(int fi = 0; fi < QUIZ_MAX_FILES; fi++)
    {
        FILE *fp = fopen(csvfiles[fi], "r");
        if(fp == NULL)
        {
            printf("Failed to open file: %s\n", csvfiles[fi]);
            getch();
            continue;
        }

        //  
        while(fgets(buffer,700,fp) != NULL)
        {
            //  Parses each line of string and gets question, difficulty, options and answer.
            parse_info(buffer, &qi);

            //  Check if this question matches difficulty level required.
            if(strcmp(qi.difficulty, difficulty) == 0)
            {
                //  Copy the question to the required 10 questions.
                memcpy(&pqi[question], &qi, sizeof(quiz_info));
                question++;
            }

            // dynamic memory allocated is not enough need to increase it using realloc
            if(question >= totalquestions)
            {
                totalquestions += MAX_QUESTIONS_LEVEL;
                pqi = (quiz_info *) realloc(pqi, totalquestions*sizeof(quiz_info));

                if(pqi == NULL)
                {
                    printf("Failed to allocate memory\n");
                    getch();
                    return;
                }

            }
        }
        fclose(fp);
    }

    // To initialize randomizer
    srand((unsigned int) time(NULL));

    int repeat[MAX_QUESTIONS_LEVEL] = {0};
    int r = 0;

    // Copy random 10 questions needed for quiz session
    for(int i = 0; i < MAX_QUESTIONS_LEVEL; )
    {
        int q = rand()%question;

        // check if random question has been already asked
        for(r = 0; r < i; r++)
        {
            if(repeat[r] == q)
            {
                // This question is already asked
                break;
            }
        }

        // This question is already asked get new question
        if(repeat[r] == q)
            continue;

        // Copy question to the final list of questions to be asked
        memcpy(&fqi[i], &pqi[q], sizeof(quiz_info));

        // save the question number so that we don't ask the same
        repeat[i] = q;

        ++i;
    }

    free(pqi);
    
}

int show_quiz(int question, quiz_info* qi, user_profile* pup, int correct)
{
    system("cls");
    fflush(stdin);

    char difficulty[DIFFICULTY_MAX];
    get_difficulty_text(pup->level, difficulty);

    printf("\033[1;33m"); 
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    QUIZ\n");
    printf("\t\t\t\t\t\t\t\t\t\t_____________");
    printf("\033[1;34m"); 
    printf("\nUSER       : %s", pup->name);
    printf("\nLEVEL      : %d", pup->level);
    printf("\nHIGH-SCORE : %d", pup->score);
    printf("\nSCORE      : %d", correct*pup->level);
    printf("\nDIFFICULTY : %s", difficulty);
    printf("\033[1;32m"); 
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tQuestion - %d\n", question);
    printf("\t\t\t\t\t\t\t\t\t       _______________\n\n\n", question);
    printf("\033[0m");
    printf("\n\n\t\t\t\t%s\n\n", qi->question);
    printf("\n\n\t\t\t\t\t\tA. %-50s\t\tB. %-50s\n\n", qi->optionA, qi->optionB);
    printf("\n\n\t\t\t\t\t\tC. %-50s\t\tD. %-50s\n\n", qi->optionC, qi->optionD);
    printf("\n\n\t\t\t\t\t\tEnter your choice: ");

    int timer = QUIZ_TIMER;
    
    do
    {
        printf("\r\t\t\t\t\t\t\t\t\t\t%2ds\r\t\t\t\t\t\t\t\t\t", timer);
        if(kbhit())
        {
            int key = getche();
            char choice;
            char option[OPTION_MAX];
            switch (key)
            {
            case 27: // esc key.
                printf("\r\n\n\t\t\t\t\t\t Do you want to quit game (Y/N)?");
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
                printf("\t\tInvalid option");
                continue;
                break;
            }
            if(strcmp(option, qi->answer) == 0)
            {
                //  User has entered correct answer.
                Sleep(500);
                return 1;
            }
            else
            {  
                //  User has entered wrong answer.
                Sleep(500);
                return 0;
            }
        }
        Sleep(1000);
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
        getch();
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

    if(actual_score >= up.score)
    {
        if(correct != MAX_QUESTIONS_LEVEL)
        {
            system("cls");
            printf("\033[1;36m"); 
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t!!! CONGRATULATIONS !!!\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t!!! YOU HAVE IMPROVED YOUR HIGH SCORE !!!");
            printf("\033[0m");
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
        printf("\033[1;36m"); 
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOU SCORED : %d\n\n\n", actual_score);
        printf("\t\t\t\t\t\t\t\t\t%d CORRECT ANSWERS", correct);
        printf("\033[0m");
        fflush(stdin);
        getch();
    }

    if(correct == MAX_QUESTIONS_LEVEL)
    {
        system("cls");
        printf("\033[1;31m"); 
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t!!! CONGRATULATIONS !!!\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t!!! YOU SUCCESSFULLY COMPLETED THIS LEVEL !!!");
        printf("\033[0m");
        fflush(stdin);
        getch();
        up.level++;
    }

   save_user_profile(&up);
}