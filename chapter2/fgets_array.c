//
// Created by weipeng2k on 2022/6/22.
//
#include <stdio.h>

/**
 * Enter Name:
 * 12345678901234567890123
 * 1234567890123456789
 * @return
 */
int main() {
    char name[20];
    puts("Enter Name:");

    // 限定长度，长度与数组长度一致，19 + '\0'
    fgets(name, 20, stdin);

    puts(name);

    return 0;
}