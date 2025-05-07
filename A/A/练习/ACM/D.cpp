#include<stdio.h>
int main()
{
	int n, k, a1, a2, b1, b2, c1, c2, x, y, t;
	double k1, k2, k3, f1, f2, f3;
	scanf_s("%d", &n);
	for (k = 0; k < n; k++)
	{
		t = 0;
		scanf_s("%d %d %d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2, &x, &y);
		if (a1 - b1 != 0)
		{
			k1 = (a2 - b2) / (a1 - b1);
			f1 = (k1*(x - a1) + a2 - y)*(k1*(c1 - a1) + a2 - c2);
		}
		else
			f1 = (x - b1)*(c1 - b1);
		if (f1 > 0)
			t++;
		else
		{
			if (f1 < 0)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				continue;
			}
		}

		if (a1 - c1 != 0)
		{
			k2 = (a2 - c2) / (a1 - c1);
			f2 = (k2*(x - a1) + a2 - y)*(k2*(b1 - a1) + a2 - b2);
		}
		else
			f2 = (x - c1)*(b1 - c1);
		if (f2 > 0)
			t++;
		else
		{
			if (f2 < 0)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				continue;
			}
		}

		if (c1 - b1 != 0)
		{
			k3 = (c2 - b2) / (c1 - b1);
			f3 = (k3*(x - b1) + b2 - y)*(k3*(a1 - b1) + b2 - a2);
		}
		else
			f3 = (x - b1)*(a1 - b1);
		if (f3 > 0)
			t++;
		else
		{
			if (f3 < 0)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				continue;
			}
		}

		if (t == 3)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
