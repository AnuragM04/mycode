#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "sms.h"

// void add_marks(); // To call functions which are below another functon, declare like this.

extern void show_student_menu();
extern void show_marks_menu();

int main()
{
    int choice = 0;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\tSREYAS STUDENT MANAGEMENT SYSTEM\n");
        printf("\t\t\t\t\t\t________________________________________________\n\n");
        printf("\t\t\t\t\t\t1. Student Details\n\n");
        printf("\t\t\t\t\t\t2. Student Marks\n\n");
        printf("\t\t\t\t\t\t3. Exit\n\n");
        printf("\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            show_student_menu();
            break;
        case 2:
            show_marks_menu();
            break;
        case 3:
            printf("\n\n\t\t\t\t\t\tBye");
            return 0;
        default:
            printf("\n\n\t\t\t\t\t\tInvalid option");
            getch();
            break;
        }
    }while(choice != 8);
    
    return 0;
}