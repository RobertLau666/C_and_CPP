#include<stdio.h>
#include<string.h>
void PAI(char s[])
{
	int i, j;
	char t;
	for (i = 0; i < strlen(s) - 1; i++)
		for (j = 0; j < strlen(s) - 1 - i; j++)
			if (s[j] > s[j + 1])
			{
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
	puts(s);
}
int main()
{
	char S[10];
	gets_s(S, 10);
	PAI(S);
}