#include<stdio.h>
int main()
{
	int A[3][3], i, j;
	void sort(int a[][3]);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf_s("%d", &A[i][j]);
	sort(A);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (j == 0)
				printf("%d", A[i][j]);
			else
				printf(" %d", A[i][j]);
		printf("\n");
	}
}

void sort(int a[][3])
{
	int i, j, t;
	for (i = 0; i < 3; i++)
		for (j = 0; j < i; j++)
		{
			t = a[i][j];
			printf("%d`", t);
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
}