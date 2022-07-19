//
// 使用函数指针，演示策略模式
// Created by weipeng2k on 2022/7/9.
//
#include <stdio.h>

typedef enum Type {
    A, B, C
} Type;

/**
 * Item
 */
typedef struct Item {
    // 名称
    char *name;
    // 类型
    Type type;
} Item;

void a(Item *item) {
    printf("A{%s}A\n", item->name);
}

void b(Item *item) {
    printf("B{%s}B\n", item->name);
}

void c(Item *item) {
    printf("C{%s}C\n", item->name);
}

int main(void) {
    Item items[] = {{"A",  A},
                    {"AA", A},
                    {"B",  B},
                    {"C",  C}};

    void (*funMap[])(Item*) = {a, b, c};

    for (int i = 0; i < 4; i++) {
        // 太帅了
        funMap[items[i].type](&items[i]);
    }

    return 0;
}
