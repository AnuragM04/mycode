// C29. Write a program to print fibonacii series.
#include <stdio.h>
void main() {
  int t1 = 0, t2 = 1,  next = 0, max;
  printf("Enter a max number: ");
  scanf("%d", &max);

  printf("Fibonacci Series: %d, %d, ", t1, t2);
  next = t1 + t2;

  while (next <= max) {
    printf("%d, ", next);
    t1 = t2;
    t2 = next;
    next = t1 + t2;
  }
}