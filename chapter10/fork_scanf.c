//
// Created by weipeng2k on 2022/7/17.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (!pid) {
            char name[30];
            fgets(name, 30, stdin);
            printf("Process[%i]:%s", getpid(), name);
            exit(0);
        }
    }

    char name[30];
    fgets(name, 30, stdin);
    printf("Process[%i]:%s", getpid(), name);
    puts("main quit!");
    return 0;
}