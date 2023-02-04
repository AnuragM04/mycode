#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "sms.h"

void  show_student_details_header()
{
    system("cls");
    printf("\t\t\t\t\tStudent Details\n");
    printf("\t\t\t\t\t---------------\n\n");
    printf("%-10s\t%20s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "Roll Number", "Name", "Class", "Section", "Mobile Number", "Blood Group", "Email Id", "DOB");
    printf("___________________________________________________________________________________________________________________\n\n");
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
    char roll_no[STUDENT_ROLL_NO];
    printf("Enter Student Roll Number: ");
    scanf("%s", &roll_no);
    strupr(roll_no);
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
            if(strcmp(roll_no, sd.roll_no) == 0)
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
    }while(sz != 0);
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
    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    size_t sz = 0;
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if(sz != 0)
        {
            // printf("%s\n", roll_no);
            // printf("%s\n", sd.roll_no);
            if(strcmp(roll_no, sd.roll_no) == 0)
            {
                printf("Roll No: %s\n", sd.roll_no);
                printf("Name: %s\n", sd.name);
                printf("Class: %s\n", sd.clas);
                printf("Section: %s\n", sd.section);
                printf("Mobile No: %s\n", sd.mob_no);
                printf("Blood Group: %s\n", sd.blood_grp);
                printf("Email Id: %s\n", sd.email_id);
                printf("DOB(dd/mm/yyyy): %s\n", sd.dob);
            }
        }
    }while(sz != 0);
    fclose(fp);
}

void list_student_details()
{
    student_details sd;
    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb");

    if(fp == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }
    show_student_details_header();
    size_t sz = 0;
    do
    {
        sz = fread(&sd, sizeof(student_details), 1, fp);
        if(sz != 0)
        {
            char details[100];
            sprintf(details, "%-10s\t%20s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s", sd.roll_no, sd.name, sd.clas, sd.section, sd.mob_no, sd.blood_grp, sd.email_id, sd.dob);
            printf("%s\n", details);
        }
    }while(sz != 0);
    fclose(fp);
}