//
// Created by weipeng2k on 2022/6/23.
//
#include <stdio.h>
#include <string.h>

int main() {

    char *source = "SOURCE";
    char *pattern = "RC";

    char *p = strstr(source, pattern);

    puts(p);

    p = strstr(source, "NO");

    puts(p);
    return 0;
}