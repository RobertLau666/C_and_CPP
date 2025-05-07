#include<stdio.h>
int main()
{
	char A[10], B[10];
	//gets_s( B, 10);
	scanf_s("%s", B, 10);
	int i = 0;
	while (B[i] != '\0')
	{
		A[i] = B[i];
		i++;
	}
	A[i] = B[i];
	printf("%s\n", A);
	printf("%s\n", B);
	return 0;
}