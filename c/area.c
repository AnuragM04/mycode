#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "area.h"

int main()
{
    int choice=0;
    float x, y, result=0;
    do {
        system("cls");
        printf("Area\n");
        printf("1. Square\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter side of Square:\n");
                scanf("%f",&x);
                result = square(x);
                printf("\nArea of Square: %f", result);
                break;
            case 2:
                printf("Enter length and breadth of Rectangle:\n");
                scanf("%f %f", &x, &y);
                result = rectangle(x, y);
                printf("\nArea of Rectangle: %f", result);
                break;
            case 3:
                printf("Enter base and height of Triangle\n");
                scanf("%f %f", &x, &y);
                result = triangle(x, y);
                printf("\nArea of Triangle: %f", result);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        getch();
    }while (choice>0 && choice<4);

    return 0;
}
