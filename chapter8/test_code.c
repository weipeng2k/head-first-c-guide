// 测试checksum和encrypt
// Created by weipeng2k on 2022/7/12.
//
#include <stdio.h>
#include "checksum.h"
#include "encrypt.h"

int main() {
    char s[] = "Speak friend and enter";
    // 字符串也会复制
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));

    encrypt(s);

    printf("DeEncrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
    return 0;
}