#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "sms.h"

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