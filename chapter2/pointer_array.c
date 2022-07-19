//
// Created by weipeng2k on 2022/6/22.
//
#include <stdio.h>

/**
 * *s store in 0x1093fbf8e
 * sa store in 0x7ff7b6b0777b
 * sa1 store in 0x7ff7b6b07776
 * @return
 */
int main() {

    char *s = "TEST";
    printf("*s store in %p\n", s);

    char sa[] = "TEST";
    char sa1[] = "TEST";
    printf("sa store in %p\n", sa);
    printf("sa1 store in %p\n", sa1);

    return 0;
}