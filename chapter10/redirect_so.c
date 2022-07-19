// 重定向标准输出到out.log
// Created by weipeng2k on 2022/7/15.
//
#include <stdio.h>
#include <unistd.h>

int main(void) {

    puts("标准输出...");

    FILE *file = fopen("out.log", "w");

    if (file) {
        puts("重定向到out.log");
        // 重定向
        if (dup2(fileno(file), 1) == -1) {
            puts("重定向标准输出失败");
        }
    }

    puts("标准输出...");
    puts("标准输出...");
    puts("标准输出...");

    return 0;
}