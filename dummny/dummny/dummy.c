#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num =28;
	for (int i = 708; i < 1001; i++) {
		num += i;
	}
	printf("%d", num);
}
