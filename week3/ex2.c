#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int arr[6]={11, 12, 2, 4, 2, 1};

    printf("Array before sorting: ");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);

    bubble_sort(arr, sizeof(arr)/sizeof(int));

    printf("\nArray after sorting: ");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);

    printf("\n ");
    return 0;
}
