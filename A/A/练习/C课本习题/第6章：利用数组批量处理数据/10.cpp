#include<stdio.h>
#include<string>
int main()
{
	char S[3][30] = { { "2138hjash AGS^&^&" },{ "2138hjashAGS^&^&" },{ "2138hjashAGS^&^&" } }, c;
	int i, j, a1, a2, a3, a4, a5, n;
	a1 = a2 = a3 = a4 = a5 = n = 0;
	for (i = 0; i < 3; i++)
	{
		n += strlen(S[i]);
		for (j = 0; (c = S[i][j]) != '\0'; j++)
		{
			if (c >= 'a'&&c <= 'z')
				a1++;
			if (c >= 'A'&&c <= 'Z')
				a2++;
			if (c >= '0'&&c <= '9')
				a3++;
			if (c == ' ')
				a4++;
		}
	}
	a5 = n - (a1 + a2 + a3 + a4);
	printf("%d %d %d %d %d\n", a1, a2, a3, a4, a5);
	return 0;
}