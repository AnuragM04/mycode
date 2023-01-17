#include <stdio.h>
#include <malloc.h>

// The following preprocessor disables or modifies padding behaviour
//#pragma pack (1)

#define MAX_STUDENTS 3

struct Student
{
    char name[15];   // 15 bytes
    int year;        //  4 bytes
    int maths;       //  4 bytes
    int physics;     //  4 bytes
    int chemistry;   //  4 bytes
};

struct Employee
{
    int age;        //  4 bytes
    int bonus;       //  4 bytes
    int salary;     //  4 bytes
    int tax;   //  4 bytes
    char ch[5];    // 3 bytes are additionally reserved or padding
    int test;    
};


void printStudent(struct Student st)
{
    printf("Student Details\n");
    printf("Name: %s\n", st.name);
    printf("Year:%2d\n", st.year);
    printf("Maths:%2d\n", st.maths);
    printf("Physics:%2d\n", st.physics);
    printf("Chemistry:%2d\n", st.chemistry);
}

void memsizetest()
{
    struct Student stest;
    printf("Size of Student: %d\n", sizeof(stest));

    struct Employee etest;
    printf("Size of Employee: %d\n", sizeof(etest));
    printf("Addr Age: %ld\n", &etest.age);
    printf("Addr bonus: %ld\n", &etest.bonus);
    printf("Addr salary: %ld\n", &etest.salary);
    printf("Addr tax: %ld\n", &etest.tax);
    printf("Addr ch: %ld\n", &etest.ch);
    printf("Addr test: %ld\n", &etest.test);
}

void addEmployees()
{
    struct Employee emp;
    struct Employee* pEmployee = NULL;

    int empnum = 0;

    printf("Enter number of Employees:");
    scanf("%d", &empnum);

    if(empnum <= 0)
    {
        printf("Invalid number of Employees");
        return;
    }

    int memsize = sizeof(emp)*empnum;

    pEmployee = (struct Employee*) malloc(memsize);

    if(pEmployee == NULL)
    {
        printf("Failed to allocate memory for Employees");
        return;
    }

    for(int i = 0; i < empnum; i++)
    {
        printf("Age:");
        scanf("%d", &pEmployee[i].age);
        printf("Bonus:");
        scanf("%d", &pEmployee[i].bonus);
        printf("Salary:");
        scanf("%d", &pEmployee[i].salary);
        printf("Tax:");
        scanf("%d", &pEmployee[i].tax);
        printf("Ch:");
        scanf("%s", &pEmployee[i].ch);
        printf("Test:");
        scanf("%d", &pEmployee[i].test);
               
    }

    printf("Employee details:\n");

    for(int i = 0; i < empnum; i++)
    {
        printf("Age: %d\n", pEmployee[i].age);
        printf("Bonus: %d\n", pEmployee[i].bonus);
        printf("Salary: %d\n", pEmployee[i].salary);
        printf("Tax: %d\n", pEmployee[i].tax);
        printf("Ch: %s\n", pEmployee[i].ch);
        printf("Test: %d\n", pEmployee[i].test);        
    }

    printf("Sizeof Employee: %d\n", sizeof(emp));
    printf("Sizeof Memory Allocated for %d employees:%d \n", empnum, memsize);
//    printf("Sizeof Memory Allocated: %d\n", sizeof(*pEmployee));

    free(pEmployee);
 }


int main()
{
    struct Student stud[MAX_STUDENTS];

    printf("Enter Student Details:\n");

    for(int i = 0; i < MAX_STUDENTS; i++)
    {
        printf("Name:");
        scanf("%s", &stud[i].name);
        printf("Year:");
        scanf("%d", &stud[i].year);
        printf("Maths:");
        scanf("%d", &stud[i].maths);
        printf("Physics:");
        scanf("%d", &stud[i].physics);
        printf("Chemistry:");
        scanf("%d", &stud[i].chemistry);
    }
    
    for(int i = 0; i < MAX_STUDENTS; i++)
    {
        printStudent(stud[i]);
    }
 
    return 0;
}