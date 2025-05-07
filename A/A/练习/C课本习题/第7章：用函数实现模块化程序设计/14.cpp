#include<stdio.h>

void A1(int s[][5])
{
	int i, j;
	int K[3] = { 0 };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			K[i] += s[i][j];
		printf("%d ", K[i] /= 5);
	}
	printf(">1\n");
}

void A2(int s[][5])
{
	int i, j;
	int K[5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
			K[i] += s[j][i];
		printf("%d ", K[i] /= 3);
	}
	printf(">2\n");
}

void A3(int s[][5])
{
	int i, j;
	int max = s[0][0], m, n;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			if (s[i][j] > max)
			{
				max = s[i][j];
				m = i;
				n = j;
			}
	}
	printf("%d %d %d>3\n", max, m+1, n+1);
}

void A4(int s[][5])
{
	int i, j, a[3] = { 0 }, b[3] = { 0 }, A = 0, B = 0;
	int K[3] = { 0 };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			a[i] += s[i][j];
		a[i] /= 5;
	}
	for (i = 0; i < 3; i++)
	{
		A += a[i] * a[i];
		B += a[i];
	}
	int n = 3;
	printf("%d>4\n", A / n + (B / n)*(B / n));
}

int main()
{
	int score[3][5];
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			scanf_s("%d", &score[i][j]);
	A1(score);
	A2(score);
	A3(score);
	A4(score);
}