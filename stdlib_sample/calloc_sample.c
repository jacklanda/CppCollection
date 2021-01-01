#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    int *a;

    printf("要输入的元素个数：");
    scanf("%d", &n);

    a = (int *)calloc(n, sizeof(int));
    printf("输入%d个数字：\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("输入的数字为：");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return (0);
}
