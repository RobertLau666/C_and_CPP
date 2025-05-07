#include<stdio.h>
int main()
{
	int i, j, g, k, a, b, t, N, x, m, C[20];//t表示个数
	char A[10], B[10];
	while (scanf_s("%d", &N) != EOF)
	{
		a = -2;
		b = -2;
		k = 0;
		t = 0;
		x = 0;
		m = -1;
		scanf_s("%s", A, 10);
		scanf_s("%s", B, 10);
		for (j = 0; j < N; j++)
		{
			for (i = 0; i < N; i++)
			{
				if (A[i] != B[j] && i > m)//
				{
					C[k++] = 1;
					t++;
				}
				else
					if (A[i] == B[j])
					{
						if (a != -2)
							b = a;
						a = i;
						if (a > m)
							m = a;
						if (a == b + 1)
							C[k++] = 0;
						else
							if (a < b && (a == t - 1 || t == 1 || a == b + t - 1 || t <= a))
							{
								C[k++] = 2;
								t--;
							}
							else
								if (a < b - 1 && t > a + 1)
								{
									x = 1;
									printf("No.\nFINISH\n");
									break;
								}
								else
								{
									for (g = 0; g < a - m - 1; g++)
									{
										C[k++] = 1;
										t++;
									}
									if (a + 1 == t)
										C[k++] = 2;
									else
										C[k++] = 0;
								}
						break;
					}
			}
			if (a < t - 1)
				break;
		}
		if (x == 0)
		{
			printf("Yes.\n");
			for (i = 0; i < k; i++)
			{
				if (C[i] == 0)
					printf("in\nout\n");
				if (C[i] == 1)
					printf("in\n");
				if (C[i] == 2)
					printf("out\n");
			}
			printf("FINISH\n");
		}
	}
	return 0;
}