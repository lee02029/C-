
int main()
{
	int s[10];
	int tmp;
	int i, k, j;

	int* p;

	p = s;

	for (i = 0; i < 10; i++)
	{
		printf("s[%d]의 데이터 : ",i+1);
		scanf("%d", &s[i]); 
		printf("\n");
	}

	printf("데이터 정렬:");
	scanf("%d", &j);
	
	if (j==1)
	{
		for (i = 0; i < 9; i++)
		{
			for (k = i + 1; k < 10; k++)
			{
				if (*(p + i) > *(p + k))
				{
					tmp = *(p + i);
					*(p + i) = *(p + k);
					*(p + k) = tmp;
				}
			}
		}
	}

	if (j==2)
	{
		for (i = 0; i < 9; i++)
		{
			for (k = i + 1; k < 10; k++)
			{
				if (*(p + i) < *(p + k))
				{
					tmp = *(p + i);
					*(p + i) = *(p + k);
					*(p + k) = tmp;
				}
			}
		}
	}
	printf("정렬 후 배열 s ==> ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");		
}
