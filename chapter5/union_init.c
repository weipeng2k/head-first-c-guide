//
// Created by weipeng2k on 2022/7/3.
//
#include <stdio.h>
#include <stdlib.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef enum {
    RED, GREEN
} color;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
     int x:1;
    color col;
} margarita;

int main() {
    margarita m = {2.0, 1.0,  .citrus.lemon=2, .x=1, .col=GREEN};
    printf("%d", m.x);

    return 0;
}


