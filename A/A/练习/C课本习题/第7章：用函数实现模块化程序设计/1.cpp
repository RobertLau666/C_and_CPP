#include<stdio.h>
int main()
{
	int MaxGY(int a, int b);
	int MinGB(int a, int b);

	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d ", MaxGY(a, b));
	printf("%d ", MinGB(a, b));
	return 0;
}

int MaxGY(int a,int b)
{
	int i;
	for (i = a; i > 0; i--)
		if (a%i == 0 && b%i == 0)
			return i;
	if (i == 0)
		return -1;
}

int MinGB(int a, int b)
{
	int i;
	for (i = a; ; i++)
		if (i%a == 0 && i%b == 0)
			break;
	return i;
}