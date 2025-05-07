#include<stdio.h>
int main()
{
	int A[3][3], i, j;
	int s1 = 0;//主对角线和
	int s2 = 0;//副对角线和
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &A[i][j]);
			if (i == j)
				s1 += A[i][j];
			if (i + j == 2)
				s2 += A[i][j];
		}
	printf("主：%d 副：%d", s1, s2);
	return 0;
}