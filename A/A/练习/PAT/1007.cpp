//�ж�����
//����һ���ж�n�Ƿ��ܱ�2~n-1���������
//#include<stdio.h>
//int main()
//{
//	int i, n;
//	scanf_s("%d", &n);
//	for (i = 2; i < n; i++)
//		if (n%i == 0)
//			break;
//	if (i < n)
//		printf("This is not a prime.");
//	else
//		printf("This is a prime.");
//	return 0;
//}
//���������ж�n�Ƿ��ܱ�2~��n���������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i, n, k;
//	scanf_s("%d", &n);
//	k = sqrt(n);
//	for (i = 2; i <= k; i++)
//		if (n%i == 0)
//			break;
//	if (i <= k)
//		printf("This is not a prime.");
//	else
//		printf("This is a prime.");
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	int n, a, k, A[100000], i, j, c, m;
	while (scanf_s("%d", &n) != EOF)
	{
		c = 0;
		m = 0;
		for (a = 2; a <= n; a++)
		{
			k = sqrt(a);
			for (i = 2; i <= k; i++)
				if (a%i == 0)
					break;
			if (i <= k)
				continue;
			else
				A[c++] = a;
		}
		for (i = 1; i < c; i++)
			if (A[i] - A[i - 1] == 2)
				m++;
		printf("%d\n", m);
	}
	return 0;
}