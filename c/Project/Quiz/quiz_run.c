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

void parse_info(char* pbuffer, quiz_info* pqi)
{
    int i = 0;
    char values[6][50] = {0};
    char *str = strtok(pbuffer, ","); 
    if(str != NULL)
    {
        strcpy_s(pqi->question, QUESTION_MAX, str);
        str = strtok(NULL, ",\n");
    }
    while(str != NULL)
    {
        strcpy_s(values[i], 50, str);
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

void show_quiz(quiz_info* qi)
{
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tQuestion");
    printf("\n\n\t\t\t%s", qi->question);
    printf("\n\n\t\t\tA. %s\t\tB. %s", qi->optionA, qi->optionB);
    printf("\n\n\t\t\tC. %s\t\tD. %s", qi->optionC, qi->optionD);
    printf("\n\n\t\t\tEnter your choice: ");
    getch();
}

void easy_quiz()
{
    char buffer[760];
    FILE *fp = fopen(QUIZ_SPORTS_FILE, "r");
    if(fp == NULL)
    {
        printf("Failed to open file");
        exit(0);
    }
    quiz_info qi;
    while(fgets(buffer,760,fp) != NULL)
    {
        parse_info(buffer, &qi);
        show_quiz(&qi);
    }
    fclose(fp);
}