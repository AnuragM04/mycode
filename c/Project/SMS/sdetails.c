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

void add_student()
{
    char option;
    system("cls");
    student_details sd;
    printf("Student Details:\n");
    printf("Roll Number: ");
    scanf("%s", &sd.roll_no);
    printf("Name: ");
    scanf("%s", &sd.name);
    printf("Class: ");
    scanf("%s", &sd.clas);
    printf("Section: ");
    scanf("%s", &sd.section);
    printf("Moblie Number: ");
    scanf("%s", &sd.mob_no);
    printf("Blood Group: ");
    scanf("%s", &sd.blood_grp);
    printf("Email Id: ");
    scanf("%s", &sd.email_id);
    printf("DOB(dd/mm/yyyy): ");
    scanf("%s", &sd.dob);

    strupr(sd.roll_no);
    strupr(sd.name);
    strupr(sd.clas);
    strupr(sd.section);
    strupr(sd.blood_grp);
    strlwr(sd.email_id);

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
    size_t sz = 0;
    fflush(stdin);
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if (sz != 0)
        {
            if (strcmp(roll_no, sd.roll_no) == 0)
            {
                // student_details nsd;
                printf("Student Details:\n");
                printf("Roll Number: ");
                scanf("%s", &nsd.roll_no);
                printf("Name: ");
                scanf("%s", &nsd.name);
                printf("Class: ");
                scanf("%s", &nsd.clas);
                printf("Section: ");
                scanf("%s", &nsd.section);
                printf("Moblie Number: ");
                scanf("%s", &nsd.mob_no);
                printf("Blood Group: ");
                scanf("%s", &nsd.blood_grp);
                printf("Email Id: ");
                scanf("%s", &nsd.email_id);
                printf("DOB(dd/mm/yyyy): ");
                scanf("%s", &nsd.dob);
                fwrite(&nsd, sizeof(nsd), 1, fp);
                // fflush(fp);
                printf("Successfully Updated\n");
                break;
            }
        }
    } while (sz != 0);
    // fflush(fp);
    fclose(fp);
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