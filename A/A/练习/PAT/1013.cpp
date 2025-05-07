#include<stdio.h>
#include<math.h>
int main()
{
	int M, N, a, k, i, j, A[10000], c;
	scanf_s("%d %d", &M, &N);
	c = 0;
	for (a = 2;; a++)
	{
		k = sqrt(a);
		for (i = 2; i <= k; i++)
			if (a%i == 0)
				break;
		if (i <= k)
			continue;
		else
			A[c++] = a;
		if (c == N)
			break;
	}
	for (i = M - 1; i < N; i++)
	{
		if ((i - (M - 1)) % 10 == 0)
			printf("%d", A[i]);
		else
			printf(" %d", A[i]);
		if ((i + 1 - (M - 1)) % 10 == 0)
			printf("\n");
	}
	return 0;
}