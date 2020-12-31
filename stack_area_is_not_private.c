#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *var);

int main(){
    int a = 1;
    pthread_t tid;
    printf("%d\n", a);
    pthread_create(&tid, NULL, thread, (void *)&a);
    printf("%d", a);
    return 0;
}

void *thread(void *var){
    int *p = (int *)var;
    *p = 2;
    return 0;
}
