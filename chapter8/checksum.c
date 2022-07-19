//
// Created by weipeng2k on 2022/7/12.
//
#include "checksum.h"

int checksum(char *message) {
    int c = 0;

    while (*message) {
        c += c ^ (*message);
        message++;
    }

    return c;
}