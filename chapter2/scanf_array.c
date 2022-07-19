//
// Created by weipeng2k on 2022/6/22.
//
#include <stdio.h>

int main() {
    // 最大有19个有效字符，和一个 '\0'
    char name[20];
    puts("Enter Name:");

    // 最多读入10个字符，并加上 '\0'，也就是11个
    scanf("%10s", name);

    char *c = name;
//    name[2] = 0;
    puts(c);

    // 数组有值的槽放了值，没有的9个（假设输入了10个以上的字符）是随机的，第11个是 '\0'
    for (int i = 0; i < 20; i++) {
        printf("name[%i] = %i\n", i, name[i]);
    }

    return 0;
}