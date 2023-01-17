#include <stdio.h>

int main()
{
    int row = 0, space = row -1, x, y;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    for(x=0; x< row; x++)
    {
        for(y=0; y<space; y++)
        {
            printf(" ");
        }

        for(y=0;y<=x;y++)
	    {
		    printf("*");
	    }
		
	    printf("\n");
	    space--;
    }
    return 0;
}