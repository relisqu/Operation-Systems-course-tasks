#include <stdio.h>
#include <memory.h>

#define X 5
#define Y 15

void *realloc(void *ptr, size_t size) {
    void* new_ptr = malloc(size);
    if (ptr == NULL)
        return new_ptr;
    if (!size) {
        free(ptr);
        return NULL;
    }
    memmove(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}


int main() {
    int *a = malloc(X*sizeof(int));
    realloc(a, Y*sizeof(int));
    return 0;
}

