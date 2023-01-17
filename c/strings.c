#include <stdio.h>
#include <string.h>

int main()
{
    char strFirst[] = {'A', 'n', 'u', 'r', 'a', 'g', '\0'};
    char strLast[] = "Meshram";

    char strFullName[30];
    char newname[30];
    int len = 0;

    strcpy(strFullName, strFirst);
    strcat(strFullName, " ");
    strcat(strFullName, strLast);

    len = strlen(strFullName);

    printf("First: %s\n", strFirst);
    printf("Last:  %s\n", strLast);
    printf("Full:  %s\n", strFullName);
    printf("Full Length:  %d sizeof: %d\n", len, sizeof(strFullName));

    strupr(strFullName);
    printf("Full Upper:  %s\n", strFullName);
    printf("Full Length:  %d sizeof: %d\n", strlen(strFullName), sizeof(strFullName));

    strlwr(strFullName);
    printf("Full Lower:  %s\n", strFullName);
    printf("Full Length:  %d sizeof: %d\n", strlen(strFullName), sizeof(strFullName));

    strrev(strFullName);
    printf("Full Reverse:  %s\n", strFullName);
    printf("Full Length:  %d sizeof: %d\n", strlen(strFullName), sizeof(strFullName));


    printf("Enter your new name: ");
// scanf takes space as end of string    
// scanf("%s", &newname);
    gets(newname);

    strcpy(strFullName, strFirst);
    strcat(strFullName, " ");
    strcat(strFullName, strLast);

// strcmp is case sensitive... any change of case then strings are different
    if(strcmp(newname, strFullName) == 0) {
        printf("New name is same as old\n");
    }
    else {
        printf("Congratulations you have new name\n");
    }
    printf("Full:  %s\n", strFullName);
    printf("New:  %s\n", newname);
 
 // stricmp is case insensitive.
    if(stricmp(newname, strFullName) == 0) {
        printf("New name is same as old\n");
    }
    else {
        printf("Congratulations you have new name\n");
    }
    printf("Full:  %s\n", strFullName);
    printf("New:  %s\n", newname);

// Searches for a character in a string
    char *p = strchr(strFullName, ' ');

    if( p == NULL) {
        printf("There are no spaces in Full Name\n");
    }
    else{
        printf("Space found in Full Name\n");
    }



 // Buffer overflow or memory corruption when copying beyond its limits
    char test[10];
    char testch = 'A';
    printf("TestNumber:  %c\n", testch);
    strcpy(test, strFullName);   
    printf("Test:  %s\n", test);
    printf("Full Length:  %d sizeof: %d\n", strlen(test), sizeof(test));
    printf("TestNumber:  %c\n", testch);
    printf("test Addr:  %ld\n", &test[9]);
    printf("TestNumber Addr:  %ld\n", &testch);


// Type safe string functions
//    strcpy_s
//    strncpy_s
//    strncmp
//    strcat_s
   

    return 0;
}