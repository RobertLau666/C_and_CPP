#include<stdio.h>
int main()
{
	int A[5] = { 1,2,3,4,5 }, i, j, t;
	for (i = 0; i < 5/2; i++)
	{
		t = A[i];
		A[i] = A[5 - 1 - i];
		A[5 - 1 - i] = t;
	}
	for (i = 0; i < 5; i++)
		printf("%d ", A[i]);
	return 0;
}