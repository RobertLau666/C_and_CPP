#include<stdio.h>
int main()
{
	int i;
	long int a, c, t;
	char H[67];
	while (scanf_s("%c", &H[0], 2) != EOF)
	{
		t = 0;
		a = 0;
		c = 0;
		if (H[0] == 'X')
			break;
		if (H[0] == 'A')
			a = 2;
		if (H[0] == 'C')
			c = 2;
		for (i = 1;; i++)
		{
			scanf_s("%c", &H[i], 2);
			if (H[i] == 'A')
				if (a == 0)
					a = 2;
				else
					a = a * 2;
			if (H[i] == 'C')
				if (c == 0)
					c = 2;
				else
					c = c * 2;
			if (H[i] == '\n')
				break;
		}
		if (a != 0)
			a = a - 1;
		if (c != 0)
			c = c - 1;
		t = a + c;
		printf("%d\n", t);
	}
	return 0;
}