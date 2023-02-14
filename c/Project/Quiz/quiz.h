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

#define USER_PROFILE_FILE "scores/profile.dbs" 

#define QUIZ_MAX_FILES 4
#define QUIZ_SPORTS_FILE "data/sports.csv"
#define QUIZ_GEO_FILE "data/geography.csv"
#define QUIZ_GENK_FILE "data/gk.csv"
#define QUIZ_HISTORY_FILE "data/history.csv"

#define QUESTION_MAX 300
#define DIFFICULTY_MAX 10
#define OPTION_MAX 50
#define QUIZ_TIMER 30

#define USER_NAME_MAX 50
#define USER_PIN_MAX 4
#define USER_DATE_MAX 11

#define MAX_QUESTIONS_LEVEL 10
#define QUIZ_MAX_LEVEL 6
typedef struct 
{
    char question[QUESTION_MAX];
    char difficulty[DIFFICULTY_MAX];
    char optionA[OPTION_MAX];
    char optionB[OPTION_MAX];
    char optionC[OPTION_MAX];
    char optionD[OPTION_MAX];
    char answer[OPTION_MAX];
}quiz_info;

typedef struct 
{
    char name[USER_NAME_MAX];
    char date[USER_DATE_MAX];
    int score;
    int level;
}user_profile;