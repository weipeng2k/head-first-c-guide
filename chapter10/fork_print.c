// 演示fork
// Created by weipeng2k on 2022/7/17.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (!pid) {
            printf("子进程[%i]\n", getpid());
            exit(1);
        }
    }

    puts("main quit");

    return 0;
}
