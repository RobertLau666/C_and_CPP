#include<stdio.h>
#include<string>
int main()
{
	int max(char a[], char b[]);
	char A[10], B[10], c, i;
	/*gets_s(A, 10);
	gets_s(B, 10);*/
	scanf_s("%s %s", A, 10, B, 10);
	for (i = 0; i < max(A, B); i++)
	{
		if (A[i] > B[i])
		{
			printf("%d", A[i] - B[i]);
			return 0;
		}
		if (A[i] < B[i])
		{
			printf("%d", A[i] - B[i]);
			return 0;
		}
	}
	printf("%d", A[i] - B[i]);
	return 0;
}
int max(char a[], char b[])
{
	return strlen(a) >= strlen(b) ? strlen(a) : strlen(b);
}