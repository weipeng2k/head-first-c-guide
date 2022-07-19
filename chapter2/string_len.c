//
// Created by weipeng2k on 2022/6/23.
//
#include <stdio.h>
#include <string.h>

int main() {
    char *s = "ABC";

    printf("strlen(\"ABC\") = %li\n", strlen(s));

    char input[80];

    fgets(input, 80, stdin);

    puts(input);

    puts("======");

    printf("%c\n", input[strlen(input) - 2]);

    // 少一个？
    input[strlen(input) - 1] = '\0';

    puts(input);

    return 0;
}