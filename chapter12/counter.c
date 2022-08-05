//
// Created by weipeng2k on 2022/8/5.
//

#include <pthread.h>
#include <printf.h>

int counter = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* add(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
}

int main(void) {
    pthread_t pthreads[20];
    for (int i = 0; i < 20; i++) {
        pthread_create(&pthreads[i], NULL, add, NULL);
    }

    void *result;
    for (int i = 0; i < 20; i++) {
        pthread_join(pthreads[i], &result);
    }

    printf("counter is %i\n", counter);
    return 0;
}