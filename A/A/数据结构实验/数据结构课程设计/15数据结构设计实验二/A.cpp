#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, M, N, a, e, t;
	int A[100];
	char B[10], C[10];
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &N);
		scanf("%s", B);
		if (strcmp(B, "FIFO") == 0)
		{
			t = 1;
			e = 1;
			for (j = 0; j < N; j++)
			{
				scanf("%s", C);
				if (strcmp(C, "IN") == 0)
				{
					scanf("%d", &a);
					A[e++] = a;
				}
				else
					if (t < e)
					{
						printf("%d\n", A[t]);
						t++;
					}
					else
						printf("None\n");
			}
		}
		else
		{
			e = 1;
			for (j = 0; j < N; j++)
			{
				scanf("%s", C);
				if (strcmp(C, "IN") == 0)
				{
					scanf("%d", &a);
					A[e++] = a;
				}
				else
				{
					if (e > 1)
						printf("%d\n", A[--e]);
					else
						printf("None\n");
				}
			}
		}
	}
	return 0;
}