//
// 键盘输入内容，然后存储到链表上，当输入为空时，打印链表
//
// Created by weipeng2k on 2022/7/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 节点
 */
typedef struct Node {
    /**
     * ID
     */
    int id;
    /**
     * 名字
     */
    char *name;
    /**
     * 下一个节点
     */
    struct Node *next;
} Node;

int ID = 0;

Node* createNodeWithoutTail(char *name) {
    Node *current = malloc(sizeof(Node));
    ID++;
    current->id = ID;
    current->name = strdup(name);
    current->next = NULL;
    return current;
}

/**
 * 由tail节点新增一个节点
 * @param tail tail
 * @param name 名称
 * @return 新增节点指针
 */
Node* createNode(Node *tail, char *name) {
    Node *current = createNodeWithoutTail(name);
    tail->next = current;
    return current;
}

/**
 * 打印节点的所有后继节点
 * @param start
 */
void printList(Node *start) {
    for (Node *current = start; current != NULL; current = current->next) {
        printf("{%8i, %-20s}\n", current->id, current->name);
    }
}

int main(void) {
    // 定义头尾节点
    Node *head = NULL;
    Node *tail = NULL;

    Node* (*xx)(Node*, char*);
    xx = createNode;
    xx(tail, "xx");

    char name[100];

    for (;;) {
        printf("Enter name:");
        fgets(name, 100, stdin);
        name[strlen(name) - 1] = '\0';
        if (strcmp(name, "quit") == 0) {
            break;
        }
        if (head == NULL) {
            // INIT
            Node *current = createNodeWithoutTail(name);
            head = current;
            tail = current;
        } else {
            Node *current = createNode(tail, name);
            tail = current;
        }
    }

    printList(head);

    return 0;
}