#include<stdio.h>

int main() {
	const char array[] = "ABC";
	array[1] = 'D';
	printf("%s", array);
}
