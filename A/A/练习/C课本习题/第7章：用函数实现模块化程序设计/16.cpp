#include<stdio.h>
#include<string.h>

int P(int a, int b)
{
	int i, j, t = 1;
	for (i = 0; i < b; i++)
		t *= 16;
	t *= a;
	return t;
}
int A(char s[])
{
	char c;
	int len = strlen(s);
	int S = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
			S += P((int)(s[i] - 48), len - i - 1);
		if (s[i] >= 'A'&&s[i] <= 'F')
			S += P((int)(s[i] - 55), len - i - 1);
	}
	return S;
}
int main()
{
	char s[100];
	printf("输入十六进制数：");
	gets_s(s, 100);
	printf("十进制数：%d", A(s));
}