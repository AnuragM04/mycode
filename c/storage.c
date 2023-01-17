#include <stdio.h>

extern int storeValue;
extern void printStoreValue();

// static variable valid only in this source file.
// Without initialization its set to 0
static int test = 29;

int addStudents()
{
    // static storage class initializes variable to 0 
    static int students;
    students++;
    return students;
}

int fastCount()
{
    // register storage class doesn't use memory for variable 
    // Avoid CPU cycles fetching value from RAM, increments and store value back to RAM...
    register int count = 0;
    for(int i = 0; i < 1000; i++)
        count++;
    printf("Count: %d", count);
//    printf("Count Address: %d", &count);
    return count;
}


int main()
{
    int a = 5;
    char ch = 'n';
    float fpi = 3.14;

    int students = addStudents();
    printf("students: %d\n", students);

    students+=10;

    students = addStudents();
    printf("students: %d\n", students);
    
    students = addStudents();
    printf("students: %d\n", students);

    printf("StoreValue: %d\n", storeValue);

    printStoreValue();

    printf("storage test: %d\n", test);

    fastCount();

   return 0;
}