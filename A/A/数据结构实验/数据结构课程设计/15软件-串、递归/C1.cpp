#include<stdio.h>
#include<string.h>
int t=0;
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		t++;
	if (n > 1)
	{
		hanoi(n - 1, x, z, y);
		t++;
		hanoi(n - 1, y, x, z);
	}
	if (n == 0)
		return;
}
int main()
{
	int i, a, c, L;
	char H[63];
	while (scanf_s("%c", &H[0],2) != EOF)
	{
		t = 0;
		a = 0;
		c = 0;
		if (H[0] == 'X')
			break;
		if (H[0] == 'A')
			a++;
		if (H[0] == 'C')
			c++;
		for (i = 1;;i++)
		{
			scanf_s("%c", &H[i],2);
			if (H[i] == 'A')
				a++;
			if (H[i] == 'C')
				c++;
			if (H[i] == '\n')
				break;
		}
		L = i;
		hanoi(a, 'A', 'C', 'B');
		a = t;
		t = 0;
		hanoi(c, 'A', 'C', 'B');
		c = t;
		printf("%d\n", a + c);
	}
	return 0;
}