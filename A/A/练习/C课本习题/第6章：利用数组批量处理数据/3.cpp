#include<stdio.h>
int main()
{
	int A[3][3], i, j;
	int s1 = 0;//���Խ��ߺ�
	int s2 = 0;//���Խ��ߺ�
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &A[i][j]);
			if (i == j)
				s1 += A[i][j];
			if (i + j == 2)
				s2 += A[i][j];
		}
	printf("����%d ����%d", s1, s2);
	return 0;
}