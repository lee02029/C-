#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	char out[100];
	char ch1, ch2;
	int i, len;
	int diff = 'a' - 'A';
	int count=0;


	printf("여러 글자를 입력 : ");
	gets(str);

	len = strlen(str);

	printf("기존 문자와 새로운 문자 : ");
	scanf("%c %c", &ch1, &ch2);


	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch1)
			str[i] = ch2;
	}

	printf("변환된 결과1 ==> %s \n", str);

	

	for (i = 0; i < len; i++)
	{
		if (('A' <= str[i]) && (str[i] <= 'Z'))
		{
			out[i] = str[i] + diff;
			count++;
		}
		else if (('a' <= str[i]) && (str[i] <= 'z'))
		{
			out[i] = str[i] - diff;
			count++;
		}
		else {
			out[i] = str[i];
		}
	}
	out[i] = '\0';


	printf("변환된 결과2 ==> %s \n", out);
	printf("변환된 개수 ==> %d", count);
}
