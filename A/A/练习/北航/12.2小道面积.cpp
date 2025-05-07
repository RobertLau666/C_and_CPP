#include<stdio.h>
int main()
{
	int N, i, j, A[100][100], a, b, T = 0;

	scanf_s("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf_s("%d", &A[i][j]);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (A[i][j] == 0)
			{
				for (b = 0; b < j; b++)//行左右有1
					if (A[i][b] == 1)
						for (b = j + 1; b < N; b++)
							if (A[i][b] == 1)
								A[i][j] = 2;

				for (a = 0; a < i; a++)//列上下有1
					if (A[a][j] == 1)
						for (a = i + 1; a < N; a++)
							if ((A[a][j] == 1) && (A[i][j] == 2))
								A[i][j] = 3;
			}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (A[i][j] == 3)
				T++;
	printf("%d\n", T);
	return 0;
}