//
// Created by weipeng2k on 2022/6/30.
//
#include <stdio.h>

int main(int argc, char *argv[]) {

    const int x = 5;


    for (int i = 0; i < argc; i++) {
        puts(argv[i]);
    }

    return 0;
}
