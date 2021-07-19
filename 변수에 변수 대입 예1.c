#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a,b;
	float c,d;

	a = 100;
	b = a;

	c = 111.1f;
	d = c;

    printf("a,b의 값 ==> %d,%d\n", a,b);
	printf("c,d의 값 ==> %5.1f,%5.1f\n", c,d);
}
