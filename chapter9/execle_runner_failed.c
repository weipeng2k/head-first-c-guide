//
// 使用execle调用外部，失败使用errno
// Created by weipeng2k on 2022/7/14.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(void) {

    // 环境变量
    char *envs[] = {"JUICES=peach and apple", NULL};

    execle("diner_infos", "diner_infos", NULL, envs);

    puts(strerror(errno));

    return 0;
}