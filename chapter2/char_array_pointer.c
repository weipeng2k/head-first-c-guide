///
// Created by weipeng2k on 2022/6/21.
//

#include <stdio.h>

void array_char_pointer();

void pointer_pointer();

void size_of_char_array(char *msg) {
    puts("@size_of_char_array");
    puts(msg);
    printf("sizeof(msg) = %li\n", sizeof msg );
}

int main() {

    printf("sizeof(\"c\") = %li\n", sizeof "c");

    size_of_char_array("c");

    array_char_pointer();

    pointer_pointer();

    return 0;
}

void pointer_pointer() {
    puts("@pointer_pointer");
    int x = 10;
    int *x_pointer = &x;
    printf("x_pointer is %p\n", x_pointer);
    printf("x_pointer store in %p\n", &x_pointer);
    printf("x value is %d\n", **&x_pointer);
}

/**
 * 直接定义的字符串引用，sizeof返回具体长度，而通过新引用指向后，新引用的大小就是指针大小
 */
void array_char_pointer() {
    char array[20];

    char *x = array;

    printf("sizeof(array) = %li\n", sizeof array);
    printf("sizeof(x) = %li\n", sizeof x);
}
