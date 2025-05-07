#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, j, s, a;
	for (n = 2; n <= 100; n++)
	{
		for (a = 2; a <= (s = sqrt(n)); a++)
			if (n%a == 0)
				break;
		if(a>s)
			printf("%d\n", n);
	}
	return 0;
}