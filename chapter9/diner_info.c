//
// 环境变量展示
// Created by weipeng2k on 2022/7/14.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    printf("Diners:%s\n", argv[1]);
    printf("Juice: %s\n", getenv("JUICE"));

    return 0;
}
