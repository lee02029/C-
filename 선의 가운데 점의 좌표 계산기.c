#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "point.h"
#include "line.h"
#define b(x)  (((a.first.x)+(a.second.x))/(2))

int main(int argc, char* argv[])
{
	for (int i=0; i<argc; i++)
	{
		Line a = { {1,2}, {5,6} };
		Point b;
		printf("두점의 위치: ");
		scanf("%d %d %d %d", &a.first.x, &a.first.y, &a.second.x, &a.second.y);
		printf("선의 가운데 선의 좌표 : (%d, %d)\n", b(x), b(y));
	}
	
	return 0;
}
