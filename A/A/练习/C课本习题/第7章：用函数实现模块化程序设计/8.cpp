#include<stdio.h>

void A(int a)
{
	int i = 0, B[100];
	while (a > 0)
	{
		B[i++] = a % 10;
		a /= 10;
	}
	while (i > 0)
		printf("%d ", B[--i]);
}

int main()
{
	int a;
	scanf_s("%d", &a);
	A(a);
}