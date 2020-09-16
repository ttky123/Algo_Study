#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num = 0;
	for (int i = 1; i < 1001; i++)
	{
		num += i;
	}
	printf("%d", num/2);
}
