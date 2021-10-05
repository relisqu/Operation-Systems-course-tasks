#include <stdio.h>

int main() {
    char **s = malloc(sizeof(char*)); //fixed
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %p\n",s); //fixed
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}
