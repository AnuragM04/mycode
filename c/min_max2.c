#include <stdio.h>

int main()
{
    int nums[100];
    int num_size=0, max=0, min=0;
    printf("Enter size of list: \n");
    scanf("%d", &num_size);
    if (num_size<=0)
    {
        printf("Invalid size");
        return 0;
    }
    for (int i=0; i<num_size; i++)
    {
        printf("Element %2d:", i+1);
        scanf("%d", &nums[i]);
    }
    min = max = nums[0];
    for (int i=0; i<num_size; i++)
    {
        printf("%d\n", nums[i]);
        if (nums[i]>max)
        {
            max = nums[i];
        }
        if (nums[i]<min)
        {
            min = nums[i];
        }
    }    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}