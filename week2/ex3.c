#include <stdio.h>

int main() {
    int i, space, height, j = 0;
    printf("Enter the triangle height: ");
    scanf("%d", &height);
    for (i = 1; i <= height; ++i, j = 0) {
        for (space = 1; space <= height - i; ++space) {
            printf(" ");
        }
        while (j != 2 * i - 1) {
            printf("*");
            ++j;
        }
        printf("\n");
    }

}
 
