//
// 使用system系统调用的例子
// Created by weipeng2k on 2022/7/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now() {
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main(void) {
    char comment[80];
    char cmd[120];

    // 获取注释
    fgets(comment, 80, stdin);

    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

    system(cmd);
}