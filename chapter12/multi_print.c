// 多线程输出内容
// Created by weipeng2k on 2022/8/5.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/**
 * runnable
 * @param msg
 */
void* print(void *name) {
    char *str = name;
    for (int i = 0; i < 100; i++) {
        fprintf(stdout, "%s\n", str);
    }
    return NULL;
}

void error(char *msg) {
    fprintf(stderr, "%s, %s\n", msg, strerror(errno));
    exit(1);
}

int main(void) {
    pthread_t t0;
    pthread_t t1;

    if (pthread_create(&t0, NULL, print, "t0") == -1) {
        error("无法创建线程");
    }

    if (pthread_create(&t1, NULL, print, "t1") == -1) {
        error("无法创建线程");
    }

    puts("join");

    void *result;
    if (pthread_join(t0, &result) == -1) {
        error("无法回收线程");
    }

    if (pthread_join(t1, &result) == -1) {
        error("无法回收线程");
    }

    return 0;
}