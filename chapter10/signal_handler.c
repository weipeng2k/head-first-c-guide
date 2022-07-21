// 演示Signal的处理
// 构造sigaction调用
// Created by weipeng2k on 2022/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void diediedie(int sig) {
    puts("再见，残酷的世界！");
    exit(1);
}

int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    // 这是一个宏
    action.sa_handler = handler;
    // 也是一个宏
    sigemptyset(&(action.sa_mask));
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main(void) {
    if (catch_signal(SIGINT, diediedie) == -1) {
        fprintf(stderr, "can not map handler");
        exit(2);
    }

    char name[20];
    printf("Enter Your Name:");
    fgets(name, 20, stdin);
    printf("Hello:%s\n", name);

    return 0;
}