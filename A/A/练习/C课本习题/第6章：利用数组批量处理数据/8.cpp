#include<stdio.h>
int main()
{
	int A[4][4] = { {1,7,9,2} ,
					{2,8,9,3} ,
					{1,8,9,4} ,
					{3,4,8,3} }, i, j, k;
	int max, min, a, b;
	for (k = 0; k < 4; k++)
	{
		max = A[k][0];
		for (j = 0; j < 4; j++)
			if (A[k][j] > max)
			{
				max = A[k][j];
				b = j;
				//printf("%d %d\n", max, b);
			}
		min = A[0][b];
		for (i = 0; i < 4; i++)
			if (A[i][b] < min)
			{
				min = A[i][b];
				a = i;
				//printf("%d %d\n", min, a);
			}
		if (k == a)
			printf("A[%d,%d] %d\n", a, b, A[a][b]);
	}
	return 0;
}