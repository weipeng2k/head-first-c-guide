//
// Created by weipeng2k on 2022/7/12.
//

#include "encrypt.h"

void encrypt(char *message) {
    while (*message) {
        *message ^= 31;
        message++;
    }
}
