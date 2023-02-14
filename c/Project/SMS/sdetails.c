#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "sms.h"

void show_student_details_header()
{
    system("cls");
    printf("\t\t\t\t\tStudent Details\n");
    printf("\t\t\t\t\t---------------\n\n");
    printf("%-10s\t%-40s\t%-9s\t%-9s\n", "Roll Number", "Name", "Class", "Section");
    printf("_____________________________________________________________\n\n");
}

void get_student_details(student_details* psd)
{
    printf("Student Details:\n");
    printf("Roll Number: ");
    scanf("%s", &psd->roll_no);
    printf("Name: ");
    scanf("%s", &psd->name);
    printf("Class: ");
    scanf("%s", &psd->clas);
    printf("Section: ");
    scanf("%s", &psd->section);
    printf("Moblie Number: ");
    scanf("%s", &psd->mob_no);
    printf("Blood Group: ");
    scanf("%s", &psd->blood_grp);
    printf("Email Id: ");
    scanf("%s", &psd->email_id);
    printf("DOB(dd/mm/yyyy): ");
    scanf("%s", &psd->dob);

    strupr(psd->roll_no);
    strupr(psd->name);
    strupr(psd->clas);
    strupr(psd->section);
    strupr(psd->blood_grp);
    strlwr(psd->email_id);
}

void add_student()
{
    char option;
    system("cls");
    student_details sd;
    get_student_details(&sd);


    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "ab");

    if (fp == NULL)
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
    if (option == 'Y' || option == 'y')
    {
        add_student();
    }
}

void delete_student()
{
}

void update_student()
{
    char roll_no[STUDENT_ROLL_NO];
    printf("Enter Student Roll Number: ");
    scanf("%s", &roll_no);
    strupr(roll_no);
    system("cls");
    student_details sd, nsd;

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb+");
    if (fp == NULL)
    {
        printf("Failed to open file for updating\n");
        return;
    }
    size_t sz = sizeof(nsd);
    fflush(stdin);
    do
    {
        if (fread(&sd, sizeof(student_details), 1, fp) != 0)
        {
            if (strcmp(roll_no, sd.roll_no) == 0)
            {
                // student_details nsd;
                fseek(fp, -sz, SEEK_CUR);
                get_student_details(&nsd);
                fwrite(&nsd, sz, 1, fp);
                printf("Successfully Updated\n");
                fclose(fp);
                return;
            }
        }
    } while (sz != 0);

    fclose(fp);

    printf("Successfully Updated\n");
}

void show_student_details()
{
    char roll_no[STUDENT_ROLL_NO] = {0};
    system("cls");
    printf("Enter Student ID: ");
    scanf("%s", &roll_no);
    strupr(roll_no);
    student_details sd;

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb");
    if (fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if (sz != 0)
        {
            if (strcmp(roll_no, sd.roll_no) == 0)
            {
                printf("\n\n%-20s %s\n\n", "Roll No:", sd.roll_no);
                printf("%-20s %s\n\n", "Name:", sd.name);
                printf("%-20s %s\n\n", "Class:", sd.clas);
                printf("%-20s %s\n\n", "Section:", sd.section);
                printf("%-20s %s\n\n", "Mobile No:", sd.mob_no);
                printf("%-20s %s\n\n", "Blood Group:", sd.blood_grp);
                printf("%-20s %s\n\n", "Email Id:", sd.email_id);
                printf("%-20s %s\n\n", "DOB(dd/mm/yyyy):", sd.dob);
                break;
            }
        }
    } while (sz != 0);

    if (strcmp(roll_no, sd.roll_no) != 0)
    {
        printf("\n\nInvalid Roll No, student not found\n");
    }

    fclose(fp);
}

void list_student_details()
{
    student_details sd;
    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb");

    if (fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    show_student_details_header();
    size_t sz = 0;
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if (sz != 0)
        {
            printf("%-10s\t%-40s\t%-9s\t%-9s\n", sd.roll_no, sd.name, sd.clas, sd.section);
        }
    } while (sz != 0);
    fclose(fp);
}