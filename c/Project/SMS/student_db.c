#include<stdio.h>
#include <conio.h>
#include <stdlib.h>

#define STUDENT_DETAILS_FILENAME "student_details.dbs"
#define STUDENT_MARKS_FILENAME "student_marks.dbs"
#define TOTAL 400

// void add_marks(); // To call functions which are below another functon, declare like this.

typedef struct 
{
    char name[20];
    char class[10];
    char gender[10];
    int birth_date;
    int birth_month;
    int birth_year;
    int id;
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

void add_student()
{
    char option;
    system("cls");
    student_details sd;
    printf("Student Details:\n");
    printf("Name: ");
    scanf("%s", &sd.name);
    printf("Class: ");
    scanf("%s", &sd.class);
    printf("Gender: ");
    scanf("%s", &sd.gender);
    printf("Birth date: ");
    scanf("%d", &sd.birth_date);
    printf("Birth Month: ");
    scanf("%d", &sd.birth_month);
    printf("Birth Year: ");
    scanf("%d", &sd.birth_year);
    printf("ID: ");
    scanf("%d", &sd.id);

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "ab");

    if(fp == NULL)
    {
        printf("Failed to open file for writing\n");
        return;
    }
    // fseek(fp, 0, 0);
    fwrite(&sd, sizeof(student_details), 1, fp);
    fclose(fp);
    printf("Do you want to add anymore student details(Y/N)?");
    fflush(stdin);
    scanf("%c", &option);
    if(option == 'Y' || option == 'y')
    {
        add_student();
    }
}

void delete_student()
{

}

void update_student()
{
    int id1 = 0;
    printf("Enter Student ID: ");
    scanf("%d", &id1);
    system("cls");
    student_details sd, nsd;

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb+");
    if(fp == NULL)
    {
        printf("Failed to open file for updating\n");
        return;
    }
    size_t sz = 0;
    fflush(stdin);
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if(sz != 0)
        {
            if(id1 == sd.id)
            {
                // student_details nsd;
                printf("Student Details:\n");
                printf("Name: ");
                scanf("%s", &nsd.name);
                printf("Class: ");
                scanf("%s", &nsd.class);
                printf("Gender: ");
                scanf("%s", &nsd.gender);
                printf("Birth date: ");
                scanf("%d", &nsd.birth_date);
                printf("Birth Month: ");
                scanf("%d", &nsd.birth_month);
                printf("Birth Year: ");
                scanf("%d", &nsd.birth_year);
                printf("ID: ");
                scanf("%d", &nsd.id);
                fwrite(&nsd, sizeof(nsd), 1, fp);
                // fflush(fp);
                printf("Successfully Updated\n");
                break;
            }
        }
    }while(sz != 0);
    // fflush(fp);
    fclose(fp);
}

void show_student_details()
{
    int id1 = 0;
    printf("Enter Student ID: ");
    scanf("%d", &id1);
    system("cls");
    student_details sd;
    printf("\t\t\t\t\tStudent Details\n");
    printf("\t\t\t\t\t---------------\n\n");

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb");
    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "ID", "Name", "Class", "Gender", "Birthdate");
    printf("-------------------------------------------------------------------------\n\n");
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if(sz != 0)
        {
            if(id1 == sd.id)
            {
                printf("%-9d\t%-9s\t%-9s\t%-9s\t%d-%d-%d\n", sd.id, sd.name, sd.class, sd.gender, sd.birth_date, sd.birth_month, sd.birth_year);
            }
        }
    }while(sz != 0);
    fclose(fp);
}

void add_marks()
{
    char option; 
    system("cls");
    student_marks sm;
    printf("Student Marks:\n");
    printf("Maths: ");
    scanf("%d", &sm.maths);
    printf("Physics: ");
    scanf("%d", &sm.physics);
    printf("Programming: ");
    scanf("%d", &sm.programming);
    printf("English: ");
    scanf("%d", &sm.english);
    printf("ID: ");
    scanf("%d", &sm.id);
    sm.total = sm.maths + sm.physics + sm.programming + sm.english;
    sm.percentage = (float)(sm.total*100/TOTAL);
    FILE *fp = fopen(STUDENT_MARKS_FILENAME, "ab");

    if(fp == NULL)
    {
        printf("Failed to open file for writing\n");
        return;
    }
    // fseek(fp, 0, 0);
    fwrite(&sm, sizeof(student_marks), 1, fp);
    fclose(fp);
    printf("Do you want to add anymore student marks(Y/N)?");
    fflush(stdin);
    scanf("%c", &option);
    if(option == 'Y' || option == 'y')
    {
        add_marks();
    }
}

void list_student_details()
{
    system("cls");
    student_details sd;
    printf("\t\t\t\t\tStudent Details\n");
    printf("\t\t\t\t\t---------------\n\n");

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb");

    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "ID", "Name", "Class", "Gender", "Birthdate");
    printf("-------------------------------------------------------------------------\n\n");
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if(sz != 0)
        {
            printf("%-9d\t%-9s\t%-9s\t%-9s\t%d-%d-%d\n", sd.id, sd.name, sd.class, sd.gender, sd.birth_date, sd.birth_month, sd.birth_year);
        }
    }while(sz != 0);
    fclose(fp);
}

void list_student_marks()
{
    system("cls");
    student_marks sm;
    printf("\t\t\t\t\tStudent Marks\n");
    printf("\t\t\t\t\t-------------\n\n");

    FILE *fp = fopen(STUDENT_MARKS_FILENAME, "rb");

    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "ID", "Maths", "Physics", "Programming", "English", "Total", "Percentage");
    printf("----------------------------------------------------------------------------------------------------------\n\n");
    do
    {
        sz = fread(&sm, sizeof(student_marks), 1, fp);
        if(sz != 0)
        {
            printf("%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10.2f\n", sm.id, sm.maths, sm.physics, sm.programming, sm.english, sm.total, sm.percentage);
        }
    }while(sz != 0);
    fclose(fp);
}

void show_student_marks()
{
    int id1 = 0;
    printf("Enter Student ID: ");
    scanf("%d", &id1);
    system("cls");
    student_marks sm;
    printf("\t\t\t\t\tStudent Marks\n");
    printf("\t\t\t\t\t-------------\n\n");

    FILE *fp = fopen(STUDENT_MARKS_FILENAME, "rb");
    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "ID", "Maths", "Physics", "Programming", "English", "Total", "Percentage");
    printf("----------------------------------------------------------------------------------------------------------\n\n");
    do
    {
        sz = fread(&sm, sizeof(student_marks), 1, fp);
        if(sz != 0)
        {
            if(id1 == sm.id)
            {
                printf("%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t%-10.2f\n", sm.id, sm.maths, sm.physics, sm.programming, sm.english, sm.total, sm.percentage);
            }
        }
    }while(sz != 0);
    fclose(fp);
}

int main()
{
    int choice = 0;
    do
    {
        system("cls");
        printf("STUDENT DATABASE:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Show Student details\n");
        printf("5. List all Student details\n");
        printf("6. Add Marks\n");
        printf("7. List all Student marks\n");
        printf("8. Show Student marks\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            update_student();
            break;
        case 4:
            show_student_details();
            break;
        case 5:
            list_student_details();
            break;
        case 6:
            add_marks();
            break;
        case 7:
            list_student_marks();
            break;
        case 8:
            show_student_marks();
            break;
        case 9:
            printf("Bye");
            break;
        default:
            printf("Invalid option");
            break;
        }
        getch();
    }while(choice != 8);
    
    return 0;
}