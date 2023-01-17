#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{
    int choice=0;
    float num1=0, num2=0, result=0;
    do {
        system("cls");
        printf("Calculator\n");
        printf("1. Add\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if (choice>0 && choice<5) {
            printf("Enter num1: ");
            scanf("%f",&num1);
            printf("Enter num2: ");
            scanf("%f",&num2);
        }

        switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("%f + %f = %f", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("%f - %f = %f", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("%f * %f = %f", num1, num2, result);
                break;
            case 4:
                if (num2!=0) {
                    result = division(num1, num2);
                    printf("%f / %f = %f", num1, num2, result);
                }
                else {
                    printf("Invalid operation\n");
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        getch();
    }while (choice>0 && choice<5);

    return 0;
}