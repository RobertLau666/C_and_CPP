#include<stdio.h>
#include<string.h>
int main()
{
	int i, p, flog = 0;
	int N[100100], M[10010];
	int e1 = 10050, e2 = 10050;
	char a[100];
	scanf_s("%d", &i);
	for (int j = 1; j <= i; j++)
	{
		scanf_s("%s", a, 100);//因为编译器的问题，此处需要加“，100”，提交时省略，scanf_s
		if (strcmp(a, "LIN") == 0)
		{
			scanf_s("%d", &p);
			N[e1--] = p;
		}
		else if (strcmp(a, "RIN") == 0)
		{
			scanf_s("%d", &p);
			N[++e2] = p;
		}
		else if (strcmp(a, "LOUT") == 0)
			if (e1 >= e2)
			{
				M[flog++] = j;
				e1 = 10050;
				e2 = 10050;
			}
			else
				e1++;
		else if (strcmp(a, "ROUT") == 0)
			if (e1 >= e2)
			{
				M[flog++] = j;
				e1 = 10050;
				e2 = 10050;
			}
			else
				e2--;
	}
	if (e1 < e2)
		for (int j = e1 + 1; j <= e2; j++)
			if (j == e2)
				printf("%d\n", N[j]);
			else
				printf("%d ", N[j]);
	for (int j = 0; j < flog; j++)
		printf("%d ERROR\n", M[j]);
	return 0;
}

//下面这个是我参考写的
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i, j, n, m, e1 = 10, e2 = 10, p = 0;
//	char a[10];
//	int b[20], c[10];
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf_s("%s", a, 10);
//		if (strcmp(a, "LIN") == 0)
//		{
//			scanf_s("%d", &m);
//			b[e1--] = m;
//		}
//		else
//			if (strcmp(a, "RIN") == 0)
//			{
//				scanf_s("%d", &m);
//				b[++e2] = m;
//			}
//			else
//				if (strcmp(a, "LOUT") == 0)
//				{
//					if (e1 >= e2)
//					{
//						c[++p] = i;
//						e1 = 10;
//						e2 = 10;
//					}
//					else
//						e1++;
//				}
//				else
//					if (strcmp(a, "ROUT") == 0)
//					{
//						if (e1 >= e2)
//						{
//							c[++p] = i;
//							e1 = 10;
//							e2 = 10;
//						}
//						else
//							e2--;
//					}
//
//	}
//	if (e1 < e2)
//		for (i = e1 + 1; i <= e2; i++)
//		{
//			if (i == e2)
//				printf("%d", b[i]);
//			else
//				printf("%d ", b[i]);
//		}
//	for (i = 1; i <= p; i++)
//	{
//		printf("%d ERROR\n", c[i]);
//	}
//	return 0;
//}