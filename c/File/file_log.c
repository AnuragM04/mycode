#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE_NAME "mylog.log"

void mylog(char *type, char *msg)
{
    time_t t = time(NULL);
    struct tm tm;
	tm = *localtime(&t);
    FILE *fp = fopen(LOG_FILE_NAME, "a");
    if(fp == NULL)
    {
        printf("Failed to open file for appending\n");
        return;
    }
    fprintf(fp, "%d-%d-%d %d:%d:%d\t%s\t%s\t%s\t%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec, type, msg, __FILE__, __LINE__);
    // Can also use __DATE__ to get date string.
    fclose(fp);
}

int main()
{
    int i=0;
    mylog("INFO", "starting main");
    for(i=0; i<10; i++)
    {
        mylog("INFO", "processing task");
        sleep(1);
    }
    mylog("INFO", "finshed\n");
    return 0;
}