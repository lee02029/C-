#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct student {
	char name[10];
	int age;
};

void get_input(int num, struct student* s);

int main()

{
	struct student* s;

	int cnt, i;
	printf("입력할 학생 수:");
	scanf("%d", &cnt);

	s = (struct student*)malloc((sizeof(struct student*)) * cnt);

	get_input(cnt,s);

	printf("\n\n-- 학생 명단 --\n");
	for (i = 0; i < cnt; i++)
		printf("이름:%s , 나이:%d \n", s[i].name, s[i].age);
	free(s);
}

void get_input(int num, struct student* s) {
	int i = 0;
	int cnt = num;
	for (i = 0; i < cnt; i++)
	{
		printf("이름과 나이 입력 :");
		scanf("%s%d", &(s + i)->name, &(s + i)->age);
	}
}


