#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char ss[50];
	int count, i;
	char* p;

	printf("문자열을 입력하세요:");
	scanf("%s", ss);

	count = strlen(ss);

	p = ss;

	printf("내용을 거꾸로 출력 ==> ");
	for (i = 0; i < count; i++)
	{
		printf("%c", *(p + count - (i + 1)));
	}
	printf("\n");
}
