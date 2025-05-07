#include<stdio.h>
int MAX_LEN(char s[])
{
	int L[100];
	int word = 0, num = 1, k = -1;
	char c;
	for (int i = 0; (c = s[i]) != '\0'; i++)
	{
		if (c == ' ')
			word = 0;
		else
			if (word == 0)
			{
				k++;
				L[k] = 1;
				word = 1;
				num++;
			}
			else
				L[k]++;
	}
	int max = L[0];
	for (int i = 1; i < num; i++)
		if (L[i] > max)
			max = L[i];
	return max;
}
int main()
{
	char S[100];
	gets_s(S, 100);
	printf("%d", MAX_LEN(S));
}