#include<stdio.h>

void A(int n)
{
	char s[100] = {'\0'}, t;//¼Ó{'\0'}
	int i = 0, k;
	while (n > 0)
	{
		s[i++] = '0' + n % 10;
		n /= 10;
	}
	k = i;
	for (i = 0; i < k / 2; i++)
	{
		t = s[i];
		s[i] = s[k - i - 1];
		s[k - i - 1] = t;
	}
	puts(s);
}

int main()
{
	int n;
	scanf_s("%d", &n);
	A(n);
}