#include <stdio.h>

void show_array(void);

void show_string(void);

/**
 * @brief
 * @return
 */
int main() {
    show_array();

    show_string();
}

/**
 * Print a changed array.
 */
void show_array(void) {
    puts("show_array(void)");
    char array[] = "ABC";
    array[1] = 'C';
    puts(&array[1]);
}

/**
 * Change string element, failed, cause by BUS ERROR, which means can not set value to String Literal.
 */
void show_string(void) {
    puts("show_string(void)");
    char *str = "ABC";

    *(str + 1) = 'D';
    puts(str + 1);
}
