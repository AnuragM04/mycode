#define STUDENT_DETAILS_FILENAME "student_details.dbs"
#define STUDENT_MARKS_FILENAME "student_marks.dbs"
#define TOTAL 400
#define STUDENT_ROLL_NO 11
#define STUDENT_NAME_MAX 50
#define STUDENT_CLAS_MAX 10
#define STUDENT_SEC_MAX 10
#define STUDENT_MOB_MAX 11
#define STUDENT_BLOOD_GRP_MAX 5
#define STUDENT_EMAIL_MAX 50
#define STUDENT_DOB_MAX 11

typedef struct 
{
    char roll_no[STUDENT_ROLL_NO]; // 22VE1A6668 
    char name[STUDENT_NAME_MAX];
    char clas[STUDENT_CLAS_MAX];
    char section[STUDENT_SEC_MAX];
    char mob_no[STUDENT_MOB_MAX];
    char blood_grp[STUDENT_BLOOD_GRP_MAX];
    char email_id[STUDENT_EMAIL_MAX];
    char dob[STUDENT_DOB_MAX];
}student_details;

typedef struct
{
    short maths;
    short physics;
    short programming;
    short english;
    int id;
    int total;
    float percentage;
}student_marks;