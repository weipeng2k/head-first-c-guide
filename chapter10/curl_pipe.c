// 演示pipe，使用curl命令，获取数据
// Created by weipeng2k on 2022/7/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

/**
 * curl && pipe
 * @return
 */
int main(void) {
    int fd[2];
    if (pipe(fd) == -1) {
        error("无法创建pipe");
    }

    pid_t pid = fork();
    if (!pid) { // child process
        close(fd[0]);
        dup2(fd[1], 1);
        if (execlp("curl", "curl", "https://www.baidu.com", NULL) != -1) {
            error("执行curl失败");
        }
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];
    while (fgets(line, 255, stdin)) {
        printf("%s", line);
    }

    return 0;
}