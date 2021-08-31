#include <stdio.h>

void swap(int*, int*);
int main()
{
    int x, y;
    printf("Enter 2 integers: \n");
    scanf("%d%d",&x,&y);
    printf("Before Swapping: \n x = %d\n y = %d\n", x, y);
    swap(&x, &y);
    printf("After Swapping: \n x = %d\n y = %d\n", x, y);
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}

