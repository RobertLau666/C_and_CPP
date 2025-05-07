#include<stdio.h>
#include<string>
int main()
{
	int i, j;
	char A[10] = "asdf", B[] = "wer";
	for (i = strlen(A), j = 0; j < strlen(B); i++, j++)
		A[i] = B[j];
	puts(A);
	return 0;
}