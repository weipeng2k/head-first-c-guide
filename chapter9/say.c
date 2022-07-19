//
// Created by weipeng2k on 2022/7/13.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char content[100];
    char cmd[120];
    printf("Enter what you want to say:");

    fgets(content, 100, stdin);

    sprintf(cmd, "say '%s'", content);

    system(cmd);

    return 0;
}