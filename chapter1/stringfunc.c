#include<stdio.h>

void fortune_cookie(char msg[]) {
	printf("read string:%s\n", msg);
}

void fortune_cookie_pointer(char *msg) {
	printf("read string:%s\n", msg);
}


int main() {
	char msg[] = "Hello, world!";
	fortune_cookie(msg);
	printf("================\n");
	fortune_cookie_pointer(msg);
	char s = *(msg + 1);
	printf("char @ [1] is %c\n", s);

	char chinese[] = "哈哈";
	printf("chinese @ [1] is %c\n",  *(chinese + 1));
	return 1;
}


