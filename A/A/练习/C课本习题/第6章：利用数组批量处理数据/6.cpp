#include<stdio.h>
int main()
{
	int i, j, A[10][10];
	for (i = 0; i < 10; i++)
		for (j = 0; j <= i; j++)
			if (j == 0)
				A[i][j] = 1;
			else if (i == j)
				A[i][j] = 1;
			else
				A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
	for (i = 0; i < 10; i++)
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				printf("%3d", A[i][j]);
			else
				printf(" %3d", A[i][j]);
			if (i == j)
				printf("\n");
		}
	return 0;
}