//
// Created by weipeng2k on 2022/6/21.
//
#include <stdio.h>

/**
 * x[10]
 *
 * x == &x == &x[0]
 * @return
 */
int main() {

    int x[10];

    printf("x[10]'s x address, %p\n", x);
    printf("x[10]'s x store in %p\n", &x);
    printf("x[0]'s address %p\n", &x[0]);

    return 0;
}