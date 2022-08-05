// 演示callable
// Created by weipeng2k on 2022/8/5.
// char (*name)(int)

#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

void* callable(void* arg) {
    sleep(5);
    char *name = arg;
    return name;
}

int main(void) {
    pthread_t pthread;
    pthread_create(&pthread, NULL, callable, "Param");

    void* result;
    pthread_join(pthread, &result);
    char *rstr = result;
    puts(rstr);
    return 0;
}