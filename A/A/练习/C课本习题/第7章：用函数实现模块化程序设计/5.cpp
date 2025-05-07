#include<stdio.h>
#include<string.h>

void change(char s[])
{
	char t;
	int i, m = strlen(s);
	for (i = 0; i < m / 2; i++)
	{
		t = s[i];
		s[i] = s[m - 1 - i];
		s[m - 1 - i] = t;
	}
}

int main()
{
	char s[100];
	scanf_s("%s", s, 100);
	change(s);
	printf("%s", s);
}