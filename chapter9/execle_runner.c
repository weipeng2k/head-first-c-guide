//
// 使用execle调用外部
// Created by weipeng2k on 2022/7/14.
//

#include <stdio.h>
#include <unistd.h>

int main(void) {

    // 环境变量
    char *envs[] = {"JUICES=peach and apple", NULL};

    execle("diner_info", "diner_info", "4", NULL, envs);

    puts("Go go go!");

    return 0;
}