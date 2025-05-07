#include<stdio.h>

int P(int n, int x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n >= 1)
		return ((2 * n - 1)*x - P(n - 1, x) - (n - 1)*P(n - 2, x)) / n;
}

int main()
{
	int n, x;
	scanf_s("%d %d", &n, &x);
	printf("%d\n", P(n, x));
}