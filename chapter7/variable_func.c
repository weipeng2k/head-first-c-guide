//
// 演示可变参数函数
// Created by weipeng2k on 2022/7/9.
//

#include <stdio.h>
#include <stdarg.h>

void print_int(int num, ...) {
    va_list vaList;
    va_start(vaList, num);

    for (int i = 0; i < num; i++) {
        printf("arg:%i\n", va_arg(vaList, int));
    }

    va_end(vaList);
}

int main(void) {

    print_int(3, 1, 2, 3);

    return 0;
}

