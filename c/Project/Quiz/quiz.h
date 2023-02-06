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
#define QUIZ_SPORTS_FILE "data/sports.csv"
#define QUIZ_GEO_FILE "data/geography.csv"
#define QUIZ_GENK_FILE "data/general_knowledge.csv"
#define QUIZ_HISTORY_FILE "data/history.csv"
#define QUIZ_MOVIES_FILE "data/movies.csv"
#define QUIZ_CAFFARIS_FILE "data/current_affairs.csv"
#define QUESTION_MAX 500
#define DIFFICULTY_MAX 10
#define OPTION_MAX 50

#define USER_NAME_MAX 50
#define USER_PIN_MAX 4

#define MAX_EASY_QUESTIONS 10
#define MAX_MEDIUM_QUESTIONS 10
#define MAX_HARD_QUESTIONS 10

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
    char pin[USER_PIN_MAX];
    int score;
    int level;
}user_profile;