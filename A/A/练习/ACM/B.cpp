#include<stdio.h>
int main()
{
	int n, i, j, m, k;
	char r[100], s[9][4] = { {},{ 'A','B','C' },{ 'D','E','F' },{ 'G','H','I' },{ 'J','K','L' },{ 'M','N','O' },{ 'P','Q','R','S' },{ 'T','U','V' },{ 'W','X','Y','Z' } };
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(r, 100);
		for (j = 0; r[j] != '\0'; j++)
			for (m = 0; m < 9; m++)
				for (k = 0; k < 4; k++)
					if (s[m][k] == r[j] || s[m][k] + 32 == r[j])
						printf("%d%d", m + 1, k + 1);
		printf("\n");
	}
	return  0;
}