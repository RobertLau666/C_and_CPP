//ѡ�񷨶�ʮ��������
#include<stdio.h>
int main()
{
	int A[10], i, j;
	int M;//���/Сֵ
	int Pos;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &A[i]);
	for (i = 0; i < 9; i++)
	{
		M = A[i];
		Pos = i;
		for (j = i + 1; j < 10; j++)
			if (A[j] < M)//��С�ž���������/��ʱA[j]С��Ҫ��λ����֪С�ں�
			{
				M = A[j];
				Pos = j;
			}
		A[Pos] = A[i];
		A[i] = M;
	}
	printf("%d", A[0]);
	for (i = 1; i < 10; i++)
		printf(" %d", A[i]);
	printf("\n");
	return 0;
}