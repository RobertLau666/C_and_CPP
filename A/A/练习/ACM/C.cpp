#include<stdio.h>
void change(int &x,int &y)
{
	int t;
	t = x;
	x = y;
	y = t;
}
int main()
{
	int i, j, k, m, n, x, y, a[13][2], b[13];
	scanf_s("%d", &m);
	while (m)
	{
		scanf_s("%d", &n);
		for (i = 0; i < n; i++)
			b[i] = i + 1;
		for (i = 0; i < n; i++)
			scanf_s("%d %d", &a[i][0], &a[i][1]);
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
				if (a[j][0] < a[j + 1][0])
				{
					change(a[j][0], a[j + 1][0]);
					change(a[j][1], a[j + 1][1]);
					change(b[j], b[j + 1]);
				}
		for (i = 0; i < n; i++)
		{
			if (i == 0)
				x = 0;
			else
				x = y + 1;
			for (j = x;; j++)
				if (a[j] != a[j + 1])
					break;
			y = j;
			for (j = 0; j < y - x; j++)
				for (k = x; k < y - j; k++)
					if (a[k][1] > a[k + 1][1])
					{
						change(a[k][0], a[k + 1][0]);
						change(a[k][1], a[k + 1][1]);
						change(b[k], b[k + 1]);
					}
		}
		printf("%d", b[0]);
		for (i = 1; i < n; i++)
			printf(" %d", b[i]);
		printf("\n");
		m--;
	}
	return 0;
}