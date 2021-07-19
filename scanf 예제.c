#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	int result;

	scanf("%d %d", &a, &b);
	
	result = a + b;
	printf("%d +%d=%d\n", a, b, result);

	result = a - b;
	printf("%d -%d=%d\n", a, b, result);

	result = a * b;
	printf("%d *%d=%d\n", a, b, result);

	result = a / b;
	printf("%d /%d=%d\n", a, b, result);

	system("pause");
	return 0;
}
