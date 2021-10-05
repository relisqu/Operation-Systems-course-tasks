#include <stdio.h>

int main() {
    int size,i=0;
    printf("Enter array size: \n");
    scanf("%d", &size);

    int *a = malloc(size*sizeof(int));
    for (; i<size; i++)
        a[i] = i;

    printf("Result array:\n");
    for (i = 0; i<size; i++)
        printf("%d ", a[i]);
    free(a);
    return(0);
}
