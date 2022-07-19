#include<stdio.h>

void func(char msg[]) {
	printf("func msg sizeof %d\n", (int)sizeof(msg));
}

int main() {
	int int_size = sizeof(int);
	printf("int sizeof is %d\n", int_size);
	int string_size = sizeof("STRING!_Java");
	printf("STRING!_Java size is %d\n", string_size);
	char msg[] = "AB";
	int char_array_size = sizeof(msg);
	printf("sizeof(msg[]) is %d\n", char_array_size);
	func(msg);
	printf("whats is fuck 3rd: %d\n", msg[2]);
	printf("中文 所占字符 是：%d\n", (int)sizeof("中文"));
}
