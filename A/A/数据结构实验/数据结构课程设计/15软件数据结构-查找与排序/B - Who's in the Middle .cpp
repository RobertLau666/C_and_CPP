#include<stdio.h>
int main()
{
	int i, j, n, A[10001], t;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
				if (A[j] > A[j + 1])
				{
					t = A[j];
					A[j] = A[j + 1];
					A[j + 1] = t;
				}
		printf("%d\n", A[n / 2]);
	}
	return 0;
}