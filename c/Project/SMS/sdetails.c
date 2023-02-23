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
    printf("\n\n\t\t\t\t\t\t\tStudent Details:\n");
    printf("\n\t\t\t\t\t\t\tRoll Number: ");
    scanf("%s", &psd->roll_no);
    printf("\n\t\t\t\t\t\t\tName: ");
    scanf("%s", &psd->name);
    printf("\n\t\t\t\t\t\t\tClass: ");
    scanf("%s", &psd->clas);
    printf("\n\t\t\t\t\t\t\tSection: ");
    scanf("%s", &psd->section);
    printf("\n\t\t\t\t\t\t\tMoblie Number: ");
    scanf("%s", &psd->mob_no);
    printf("\n\t\t\t\t\t\t\tBlood Group: ");
    scanf("%s", &psd->blood_grp);
    printf("\n\t\t\t\t\t\t\tEmail Id: ");
    scanf("%s", &psd->email_id);
    printf("\n\t\t\t\t\t\t\tDOB(dd/mm/yyyy): ");
    scanf("%s", &psd->dob);

    strupr(psd->roll_no);
    strupr(psd->name);
    strupr(psd->clas);
    strupr(psd->section);
    strupr(psd->blood_grp);
    strlwr(psd->email_id);
}

int check_std_exists(char* pid)
{    
    //  Opening Student details file to check if student details exists.
    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb+");
    if (fp == NULL)
    {
        printf("Failed to open file for updating\n");
        return -1;
    }
    
    size_t sz = sizeof(student_details);
    student_details sd;
    do
    {   
        //  Reading each student's details from database file. 
        if (fread(&sd, sz, 1, fp) != 0)
        {   
            //  Comapring input ID and (database)ID to check if student details exists.
            if (strcmp(pid, sd.roll_no) == 0)
            {   
                //  If student details exists - return 1.
                fclose(fp);
                return 1;
            }
        }
        else
        {
            //  We reached EOF and should stop reading further.
            break;
        }

    } while (sz != 0);

    fclose(fp);

    //  If student details doesn't exist - return 0.
    return 0;
}

void update_student(student_details* psd)
{
    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "rb+");
    if (fp == NULL)
    {
        printf("Failed to open file for updating\n");
        return;
    }
    
    size_t sz = sizeof(student_details);
    student_details sd;
    do
    {
        if (fread(&sd, sz, 1, fp) != 0)
        {
            if (strcmp(psd->roll_no, sd.roll_no) == 0)
            {
                // student_details nsd;
                fseek(fp, -sz, SEEK_CUR);
                fwrite(psd, sz, 1, fp);
                printf("Successfully Updated\n");
                fclose(fp);
                getch();
                return;
            }
        }
        else
        {
            break;
        }
    } while (sz != 0);

    fclose(fp);

    printf("Failed to find Student with ID: %s\n", psd->roll_no);
    getch();
}

void add_student()
{
    char cadd, cupdate;
    system("cls");

    student_details sd;
    get_student_details(&sd);
    
    int ret = check_std_exists(sd.roll_no);
    if(ret == 1)
    {
        printf("Student details already exists\nDo you want to update this student details?");
        fflush(stdin);
        scanf("%c", &cupdate);
        if (cupdate == 'Y' || cupdate == 'y')
        {
            update_student(&sd);
            return;
        }
        else
        {
            return;
        }
    }

    FILE *fp = fopen(STUDENT_DETAILS_FILENAME, "ab");
    if (fp == NULL)
    {
        printf("Failed to open file for writing\n");
        return;
    }

    fwrite(&sd, sizeof(student_details), 1, fp);
    fclose(fp);

    printf("Do you want to add anymore student details(Y/N)?");
    fflush(stdin);
    scanf("%c", &cadd);
    if (cadd == 'Y' || cadd == 'y')
    {
        add_student();
    }
}

//  Main Update student.
void update_student()
{
    char roll_no[STUDENT_ROLL_NO];
    
    system("cls");
    fflush(stdin);
        
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Student Roll Number: ");
    scanf("%s", &roll_no);
    strupr(roll_no);
    
    //  Check if student exists.
    int ret = check_std_exists(roll_no);
    if(ret == 1)
    {
        //  Get new details and update.
        student_details nsd;
        get_student_details(&nsd);
        update_student(&nsd);
    }
    else
    {   
        //  If Student details not found or file doesnt exist.
        char option;
        printf("Student details doesnt exist.\nDo you want to add new Student details");
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'Y' || option == 'y')
        {
            add_student();
        }
    }
}

void delete_student()
{
    char roll_no[STUDENT_ROLL_NO] = {0};
    system("cls");
    printf("Enter Student ID: ");
    scanf("%s", &roll_no);
    strupr(roll_no);

    int ret = check_std_exists(roll_no);
    if(ret != 1)
    {
        //  Get new details and update.
        printf("%s Student details doesn't exist\n", roll_no);
        return;
    }
    
    char command[100] = {0};
    sprintf(command, "copy /y %s %s > tmp", STUDENT_DETAILS_FILENAME, STUDENT_DETAILS_TMP_FILENAME);
    system(command);

    //  Opening Student details TEMP file for reading.
    FILE *sfp = fopen(STUDENT_DETAILS_TMP_FILENAME, "rb+");
    if (sfp == NULL)
    {
        printf("Failed to open TEMP database file for reading\n");
        return;
    }
    
    //  Truncate original file and update with new details. 
    FILE *dfp = fopen(STUDENT_DETAILS_FILENAME, "wb");
    if (dfp == NULL)
    {
        printf("Failed to open database file for updating\n");
        return;
    }
    
    size_t sz = sizeof(student_details);
    student_details sd;
    do
    {   
        //  Reading each student's details from database file. 
        if (fread(&sd, sz, 1, sfp) != 0)
        {   
            //  Update main database with all except for the one deleted.
            if (strcmp(roll_no, sd.roll_no) != 0)
            {   
                //  Update main database with student details.
                fwrite(&sd, sz, 1, dfp);
            }
        }
        else
        {
            //  We reached EOF and should stop reading further.
            break;
        }

    } while (sz != 0);

    fclose(sfp);    
    fclose(dfp); 
    
    //  Delete temporary database file.  
    remove(STUDENT_DETAILS_TMP_FILENAME);
    remove("tmp");
    printf("Successfully deleted student details\n");
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
            printf("%-10s\t%-60s\t%-9s\t%-9s\n", sd.roll_no, sd.name, sd.clas, sd.section);
        }
    } while (sz != 0);
    fclose(fp);
}