#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "sms.h"

// void add_marks(); // To call functions which are below another functon, declare like this.
extern void add_student();
extern void delete_student();
extern void update_student();
extern void show_student_details();
extern void list_student_details();
extern void show_student_marks();
extern void list_student_marks();
extern void add_marks();

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