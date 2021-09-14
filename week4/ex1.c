#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n = 69;
    int x = fork();
    if (x < 0) {
        return EXIT_FAILURE;
    } else if (x == 0) {
        printf("Hello from child[%d, %d]\n", getpid(), n);
    }else {
        printf("Hello from parent[%d, %d]\n", getpid(), n);
    }
    if (x != 0) waitpid(x, NULL, 0);
    return EXIT_SUCCESS;
}
