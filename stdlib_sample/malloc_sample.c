#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;

    str = (char *)malloc(15);
    strcpy(str, "Yon");
    printf("String = %s, Address = %p\n", str, str);

    str = (char *)realloc(str, 25);
    strcat(str, "Lau");
    printf("String = %s, Address = %p\n", str, str);

    free(str);

    return (0);
}
