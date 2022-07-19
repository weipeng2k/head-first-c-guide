//
// 展示函数指针，通过选择不同函数指针，使用不同行为
// Created by weipeng2k on 2022/7/8.
//
#include <stdio.h>
#include <string.h>

int red(char *color) {
    return strstr(color, "red") != NULL;
}

void foreachContent(char *content[], int rowNums, int (*filterFn)(char *), int (*consumeFn)(char *)) {
    for (int i = 0; i < rowNums; i++) {
        char *row = content[i];
        if (filterFn(row)) {
            consumeFn(row);
        }
    }
}

int main(void) {

    char *content[] = {
            "red is good",
            "green is good",
            "blue is good"
    };

    foreachContent(content, 3, red, (int (*)(char *)) puts);


    return 0;
}