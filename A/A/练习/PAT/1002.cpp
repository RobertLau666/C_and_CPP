#include<stdio.h>
int main()
{
	int i, a, s, A[1000],D[1000];
	char B[10][10] = { "ling","yi","er","san","si","wu","liu","qi", "ba","jiu" };
	char c,C[100];
	while (gets_s(C,100))
	{
		s = 0;
		for (i = 0; (c = C[i]) != '\0'; i++)
		{
			switch (c)
			{
			case '0':A[i] = 0; break;
			case '1':A[i] = 1; break;
			case '2':A[i] = 2; break;
			case '3':A[i] = 3; break;
			case '4':A[i] = 4; break;
			case '5':A[i] = 5; break;
			case '6':A[i] = 6; break;
			case '7':A[i] = 7; break;
			case '8':A[i] = 8; break;
			case '9':A[i] = 9; break;
			default:
				break;
			}
			s = s + A[i];
		}
		i = 0;
		while (s > 0)
		{
			a = s % 10;
			s = s / 10;
			D[i++] = a;
		}
		i--;
		printf("%s", B[D[i]]);
		i--;
		while (i > -1)
		{
			printf(" %s", B[D[i]]);
			i--;
		}
		printf("\n");
	}
	return 0;
}