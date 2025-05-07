#include<stdio.h>
int SS(int aa)
{
	int i, t = 1;
	for (i = 1; i <= aa; i++)
		t *= i;
	return t;
}
int main()
{
	int N, a, b, S;
	while (scanf_s("%d", &N) != EOF)
	{
		b = N;
		S = 0;
		while (N > 0)
		{
			a = N % 10;
			N /= 10;
			S += SS(a);
		}
		if (b == S)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}