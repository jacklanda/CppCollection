#include <stdio.h>
#include <stdlib.h>

int VALUES[] = {88, 56, 100, 2, 25};

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(int argv, char *argc[]) {
    printf("排序之前的列表：\n");
    for (int n = 0; n < 5; n++) {
        printf("%d ", VALUES[n]);
    }

    qsort(VALUES, 5, sizeof(int), cmpfunc);

    printf("\n排序之后的列表：\n");
    for (int n = 0; n < 5; n++) {
        printf("%d ", VALUES[n]);
    }

    return (0);
}
