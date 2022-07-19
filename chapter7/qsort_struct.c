//
// 排序
// Created by weipeng2k on 2022/7/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    char *name;
} Node;

int compare_node(Node *a, Node *b) {
    return a->id > b->id;
}

/**
 * 打印Node
 * @param node node指针
 */
void print_node(Node *node) {
    printf("Node:{%i, %s}\n", node->id, node->name);
}

void consume_nodes(Node nodes[], int length, void (*consumeFn)(Node*)) {
    for (int i = 0; i < length; i++) {
        consumeFn(&nodes[i]);
    }
}

int main(void) {
    Node nodes[] = {{1,  "H"},
                    {-1, "G"},
                    {3,  "X"},
                    {2,  "Z"}};

    consume_nodes(nodes, 4, print_node);

    qsort(nodes, 4, sizeof(Node), (int (*)(const void *, const void *)) compare_node);

    puts("--------------------");

    consume_nodes(nodes, 4, print_node);
    return 0;
}
