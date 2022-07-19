// 获取选项的例子
// -a if true, print all name
// -f firstName
// -l lastName
// Created by weipeng2k on 2022/7/17.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *firstName;
    char *lastName;
    int full = 0;
    char ch;
    while ((ch = (char) getopt(argc, argv, "f:l:a")) != EOF) {
        switch (ch) {
            case 'a':
                full = 1;
                break;
            case 'f':
                firstName = optarg;
                break;
            case 'l':
                lastName = optarg;
                break;
        }
    }

    // 便于后续继续从命令提示符中获取内容
    argc -= optind;
    argv += optind;

    if (full) {
        printf("FULL Name %s %s\n", firstName, lastName);
    } else {
        printf("Name %s\n", firstName);
    }

    return 0;
}
