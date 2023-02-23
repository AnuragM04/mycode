#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "sms.h"

extern void add_student();
extern void delete_student();
extern void update_student();
extern void show_student_details();
extern void list_student_details();
extern void show_student_marks();
extern void list_student_marks();
extern void add_marks();

void show_student_menu()
{
    int choice = 0;
    do
    {
        system("cls");
        fflush(stdin);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\tSTUDENT DETAILS\n");
        printf("\t\t\t\t\t\t________________________________\n\n");
        printf("\t\t\t\t\t\t1. Add Student\n\n");
        printf("\t\t\t\t\t\t2. Delete Student\n\n");
        printf("\t\t\t\t\t\t3. Update Student\n\n");
        printf("\t\t\t\t\t\t4. Show Student details\n\n");
        printf("\t\t\t\t\t\t5. List all Student details\n\n");
        printf("\t\t\t\t\t\t6. Return to Main Menu\n\n");
        printf("\t\t\t\t\t\tEnter your choice: ");
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
            return;
        default:
            printf("\n\n\t\t\t\t\t\tInvalid option");
            break;
        }
        getch();
    }while(choice <= 5);
}

void show_marks_menu()
{
    int choice = 0;
    do
    {
        system("cls");
        fflush(stdin);
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\tSTUDENT MARKS\n");
        printf("\t\t\t\t\t\t_____________________________\n\n");        
        printf("\t\t\t\t\t\t1. Add Marks\n\n");
        printf("\t\t\t\t\t\t2. List all Student marks\n\n");
        printf("\t\t\t\t\t\t3. Show Student marks\n\n");
        printf("\t\t\t\t\t\t4. Return to Main Menu\n\n");
        printf("\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_marks();
            break;
        case 2:
            list_student_marks();
            break;
        case 3:
            show_student_marks();
            break;
        case 4:
            return;
        default:
            printf("\n\n\t\t\t\t\t\tInvalid option");
            break;
        }
        getch();
    }while(choice <= 3);
}