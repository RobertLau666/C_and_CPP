#include<stdio.h>
int main()
{
	int A[10] = { 1,2,3,4,5 }, N, i, j, p;
	scanf_s("%d", &N);
	for (i = 0; i < 5; i++)
	{
		if (N <= A[0])
		{
			p = 0;
			break;
		}

		if (A[5] <= N)
		{
			p = 5;
			break;
		}

		if (A[i] <= N&&N <= A[i + 1])
		{
			p = i + 1;
			break;
		}
	}
	for (i = 4; i >= p; i--)
		A[i + 1] = A[i];
	A[p] = N;
	printf("%d", A[0]);
	for (i = 1; i < 6; i++)
		printf(" %d", A[i]);
	printf("\n");
	return 0;
}