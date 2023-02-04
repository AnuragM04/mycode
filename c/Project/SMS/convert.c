// This program is for converting csv text (comma separated) to database

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "sms.h"

void parse_details(char* pbuffer, student_details* psd)
{
    int i = 0;
    char values[8][40] = {0};
    char *str = strtok(pbuffer, ","); 
    while(str != NULL)
    {
        strcpy_s(values[i], 40, str);
        i++;
        str = strtok(NULL, ",");
    }
    strcpy_s(psd->roll_no, STUDENT_ROLL_NO, values[0]);
    strcpy_s(psd->name, STUDENT_NAME_MAX, values[1]);
    strcpy_s(psd->clas, STUDENT_CLAS_MAX, values[2]);
    strcpy_s(psd->section, STUDENT_SEC_MAX, values[3]);
    strcpy_s(psd->mob_no, STUDENT_MOB_MAX, values[4]);
    strcpy_s(psd->blood_grp, STUDENT_BLOOD_GRP_MAX, values[5]);
    strcpy_s(psd->email_id, STUDENT_EMAIL_MAX, values[6]);
    strcpy_s(psd->dob, STUDENT_DOB_MAX, values[7]);
}

void main()
{
    char buffer[1000];
    FILE *fps = fopen("SMS.csv", "r");
    if(fps == NULL)
    {
        printf("Failed to open file");
        exit(0);
    }
    FILE *fpd = fopen(STUDENT_DETAILS_FILENAME, "wb+");
    if(fpd == NULL)
    {
        printf("Failed to open file");
        exit(0);
    }
    student_details sd;
    while(fgets(buffer,1000,fps) != NULL)
    {
        parse_details(buffer, &sd);
        printf("%s\n", sd.roll_no);
        printf("%s\n", sd.name);
        printf("%s\n", sd.clas);
        printf("%s\n", sd.section);
        printf("%s\n", sd.mob_no);
        printf("%s\n", sd.blood_grp);
        printf("%s\n", sd.email_id);
        printf("%s\n", sd.dob);        
        fwrite(&sd, sizeof(student_details), 1, fpd);
    }
    fclose(fps);    
    fclose(fpd);
}