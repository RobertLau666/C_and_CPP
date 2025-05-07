/*do {
scanf_s("%d", &a[i++]);
} while ((getchar()) != '\n');*///一系列数 以回车结束
#include<stdio.h>
int main()
{
	int A[1000], B[1000], i, j, p, N;
	int A1, a1;
	int A2, s, a2;
	int A3, a3;
	double A4; int a4;
	int A5, a5;

	while (scanf_s("%d", &N) != EOF)
	{
		A1 = A2 = A3 = A4 = A5 = 0;
		a1 = a2 = a3 = a4 = a5 = 0;
		i = 0;
		j = 0;
		p = 0;

		for (i = 0; i < N; i++)
			scanf_s("%d", &A[i]);
		for (i = 0; i < N; i++)
		{
			if (A[i] % 5 == 0 && A[i] % 2 == 0)
			{
				a1++;
				A1 += A[i];
			}
			if (A[i] % 5 == 1)
			{
				a2++;
				if (a2 % 2 == 0)
					s = -A[i];
				else
					s = A[i];
				A2 += s;
			}
			if (A[i] % 5 == 2)
			{
				a3++;
				A3++;
			}

			if (A[i] % 5 == 3)
			{
				a4++;
				A4 += A[i];
			}
			if (A[i] % 5 == 4)
			{
				a5++;
				B[j++] = A[i];
			}
		}
		if (a4 != 0)
			A4 /= a4;

		p = j;
		A5 = B[0];
		for (i = 0; i < p; i++)
			if (B[i] > A5)
				A5 = B[i];

		if (A1 == 0)
			printf("N");
		else
			printf("%d",A1);

		if (A2 == 0)
			printf(" N");
		else
			printf(" %d", A2);

		if (A3 == 0)
			printf(" N");
		else
			printf(" %d", A3);

		if (A4 == 0)
			printf(" N");
		else
			printf(" %.1f", A4);

		if (A5 == 0)
			printf(" N\n");
		else
			printf(" %d\n", A5);
	}
	return 0;
}