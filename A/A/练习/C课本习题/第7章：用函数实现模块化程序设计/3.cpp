#include<stdio.h>
void A(int N)
{
	int i, j;
	if (N == 1)
		printf("不是");
	else
	{
		for (i = 2; i < N; i++)
			if (N % i == 0)
				break;
		if (i >= N)
			printf("是");
		else
			printf("不是");
	}
}
int main()
{
	int N;
	scanf_s("%d",&N);
	A(N);
}