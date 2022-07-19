//
// Created by weipeng2k on 2022/7/5.
//

#include <stdio.h>

/**
 * 读取文件并输出
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("FILE path should given.");
        return 1;
    }

    char buf[256];
    FILE *file = fopen(argv[1], "r");

//    while (fscanf(file, "%255[^\n]", buf) != EOF) {
//        puts(buf);
//    }

    while (!feof(file)) {
        fgets(buf, 255, file);
        printf("%s", buf);
    }

    fclose(file);

    return 0;
}
