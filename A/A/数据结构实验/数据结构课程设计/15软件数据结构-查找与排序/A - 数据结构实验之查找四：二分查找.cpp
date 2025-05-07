//#include<stdio.h>
//int n, A[1000001];
//int Search(int key)
//{
//	int low = 1, high = n, mid;//不能用sizeof,否则runtime error，数组越界
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (key == A[mid - 1])
//			return mid - 1;
//		else
//			if (key < A[mid - 1])
//				high = mid - 1;
//			else
//				low = mid + 1;
//	}
//	return -1;
//}
//int main()
//{
//	int i, m,b;
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++)
//		scanf("%d", &A[i]);
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &b);
//		printf("%d\n", Search(b));
//	}
//	return 0;
//}

#include<stdio.h>
int n, A[1000001];
int Search(int key)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == A[mid])
			return mid;
		else
			if (key < A[mid])
				high = mid - 1;
			else
				low = mid + 1;
	}
	return -1;
}
int main()
{
	int i, m, b;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b);
		printf("%d\n", Search(b));
	}
	return 0;
}