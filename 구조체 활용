#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct
{
	int num; // 학번
	char name[20]; // 이름
	int kor, eng, mat; // 3과목 점수
	int tot; // 총점
	double avg; // 평균
	char grade; // 학점
} Student;

int cnt = 0; // 학생 수는 전역변수로 선언
void input_data(Student* pary)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("학번 :");
		scanf("%d", &(pary+i)->num);
		printf("이름 :");
		scanf("%s", &(pary + i)->name);
		printf("국어 영어 수학 점수 :");
		scanf("%d %d %d", &(pary + i)->kor, &(pary + i)->eng, &(pary + i)->mat);
	}
}
void calc_data(Student* pary)
{
	for (int i = 0; i < cnt; i++)
	{
		(pary + i)->tot = (pary + i)->kor + (pary + i)->eng + (pary + i)->mat;
		(pary + i)->avg = (double)(pary + i)->tot / 3;

		if ((pary + i)->avg >= 90)
			(pary + i)->grade = 'A';
		else if ((pary + i)->avg >= 80)
			(pary + i)->grade = 'B';
		else if ((pary + i)->avg >= 70)
			(pary + i)->grade = 'C';
		else
			(pary + i)->grade = 'F';

	}
}
void sort_data(Student* pary)
{
	for (int i = 0; i < cnt; i++) {
		for (int j = i; j < cnt; j++) {
			if ((pary + i)->avg  < (pary + j)->avg) {	// 버블 정렬 사용
				Student temp = pary[i];
				pary[i] = pary[j];
				pary[j] = temp;
			}
		}
	}
}
void print_data(Student* pary)
{
	for (int i = 0; i < cnt; i++) {
		printf("%2d%10s%5d%5d%5d%5d%10.1f%7c\n", (pary + i)->num, (pary + i)->name, (pary + i)->kor, (pary + i)->eng, (pary + i)->mat, (pary + i)->tot, (pary + i)->avg, (pary + i)->grade);
	}
}


int main(void)
{
	Student* ary; // n명 학생의 성적
	printf("학생수 : ");
	scanf("%d", &cnt);
	ary = (Student*)malloc(sizeof(Student) * cnt);

	input_data(ary); // 학생수, 학번, 이름, 과목 점수 입력
	calc_data(ary); // 총점, 평균, 학점 계산
	printf("# 정렬 전 데이터...\n");
	print_data(ary); // 정렬 전 출력
	sort_data(ary); // 총점 순으로 내림차순 정렬
	printf("\n# 정렬 후 데이터...\n");
	print_data(ary); // 정렬 후 출력
	return 0;
}
