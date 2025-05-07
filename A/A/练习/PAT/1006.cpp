#include<stdio.h>
int main()
{
	int n, i, j, A[10];
	while (scanf_s("%d", &n) != EOF)
	{
		i = 0;
		while (n > 0)
		{
			A[i++] = n % 10;
			n /= 10;
		}
		j = i - 1;
		while (j > -1)
		{
			if (j == 2)
				for (i = 0; i < A[j]; i++)
					printf("B");
			if (j == 1)
				for (i = 0; i < A[j]; i++)
					printf("S");
			if (j == 0)
				for (i = 1; i <= A[j]; i++)
					printf("%d", i);
			j--;
		}
		printf("\n");
	}
	return 0;
}