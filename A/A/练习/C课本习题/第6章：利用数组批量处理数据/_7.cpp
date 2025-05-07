#include<stdio.h>
int main()
{
	int i, j, n, a[25][25], p = 0, k;
	if (p == 0)
	{
		scanf("%d", &n);
		if (n >= 1 && n <= 25 && n % 2 == 1)
			p = 1;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j] = 0;
	j /= 2;
	a[1][j] = 1;
	for (k = 2; k <= n*n; k++)
	{
		i--;
		j++;
		if (i<1 && j>n)
		{
			i += 2;
			j--;
		}
		else
		{
			if (i < 1)
				i = n;
			if (j > n)
				j = 1;
		}
		if (a[i][j] == 0)
			a[i][j] = k;
		else
		{
			i += 2;
			j--;
			a[i][j] = k;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return p;
}