#include<stdio.h>
char W[100][100];
int main()
{
	int N, n, i, j, k, T=0;
	int a, b, c, d;
	void A(int n,int a, int b, int c, int d,int T);
	scanf_s("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &n);
		for (j = 0; j <= n + 1; j++)
		{
			for (k = 0; k <= n + 1; k++)
				if (1 <= j&&j <= n && 1 <= k&&k <= n)
				{
					W[j][k] = getchar();
					if (W[j][k] == 'S')
					{
						a = j; b = k;
					}
					if (W[j][k] == 'T')
					{
						c = j; d = k;
					}
				}
				else
					W[j][k] = '.';
			getchar();
		}
		A(n,a,b,c,d,T);
	}
}
int MIN;
void A(int n, int a, int b, int c, int d, int T)
{
	int t = 0;
	for (int aa = 1; aa <= n; aa++)
		for (int bb = 1; bb <= n; bb++)
			if (aa + bb == a + b + 1 || aa + bb == a + b - 1)
			{
				if (W[aa][bb] == '*' || W[aa][bb] == 'T')
				{
					t++;
					T++;
					if (W[aa][bb] == '*')
						A(n, aa, bb, c, d, T);
					else
						if (MIN > T)
							MIN = T;
				}
				else
					break;
			}
	if (t == 0)
		MIN = -1;
	printf("%d\n", MIN);
}