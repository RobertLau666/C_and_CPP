//二分/折半查找
#include<stdio.h>
int main()
{
	int A[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, N;
	int low = 0, high = 15 - 1, mid;
	scanf_s("%d", &N);
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (N > A[mid])
			low = mid + 1;
		else if (N < A[mid])
			high = mid - 1;
		else
		{
			printf("%d", mid);
			break;
		}
	}
	if (low > high)
		printf("无此数");
	return 0;
}