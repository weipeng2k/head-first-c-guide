#include <stdio.h>

void print_int_pointer() {
    puts("print_int_pointer");
    // 打印整型变量i的地址
    int i = 0;
    puts("int i = 0;");
    printf("i store in hex(%p), decimal %ld\n", &i, &i);
    // 定义整型指针变量c，指向的地址为i的地址，指针变量中保存的是一个地址
    int *c = &i;
    // 将c地址的内容改为20
    *c = 20.0;
    puts("int *c = &i;");
    printf("i value is %d, store in hex(%p), decimal %ld\n", *c, c, c);
}

void func(int x, int y) {
    printf("func x store in hex(%p)\n", &x);
    printf("func y store in hex(%p)\n", &y);
}

/**
 * 函数的参数与实参，物理上并不在一起，是在栈上分配的，只是将参数拷贝过来的
 */
void print_func_address() {
    puts("print_func_address");
    int x = 0;
    int y = 1;
    printf("x store in hex(%p)\n", &x);
    printf("y store in hex(%p)\n", &y);
    func(x, y);
}

void print_pointer() {
    puts("print_pointer");
    int x = 10;
    int *d = &x;

    printf("x store in %p", d);
    printf("*d store in %p", &d);
}



int main() {
    print_int_pointer();

    print_func_address();

    print_pointer();

//    long d = (long) &i;
//    printf("i store in %li\n", d);
//    int array[] = {1, 2, 3};
//    printf("3rd is %d\n", 2[array]);
//    int *index = &i;
//    printf("2[index] is %d\n", 2[index]);
//    printf("index[2] is %d\n", index[2]);
    return 0;
}

