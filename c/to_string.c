// C7. Write a program to convert short, int, long, float to string.
#include <stdio.h>
int main()
{
	char string[50];
	int a = 10;
    float b = 20;
	sprintf(string, "%d %f", a, b);
	printf("%s", string);
	return 0;
}
