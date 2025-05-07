//两个值交换
//#include<stdio.h>
//int main()
//{
//	void swap(int *p1, int *p2);
//	int a, b;
//	int *pointer_1, *pointer_2;
//	printf("please enter a and b:");
//	scanf_s("%d %d", &a, &b);
//	pointer_1 = &a;
//	pointer_2 = &b;
//	if (a < b)
//		swap(pointer_1, pointer_2);
//	printf("%d %d", a, b);
//	return 0;
//}
//void swap(int *p1, int *p2)
//{
//	int temp;
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}

//函数实现三数排序
//#include<stdio.h>
//int main()
//{
//	void exchange(int *q1, int *q2, int *q3);
//	int a, b, c;
//	int *p1, *p2, *p3;
//	scanf_s("%d %d %d", &a, &b, &c);
//	p1 = &a, p2 = &b, p3 = &c;
//	exchange(p1, p2, p3);
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//void exchange(int *q1, int *q2, int *q3)
//{
//	void swap(int *pt1, int *pt2);
//	if (*q1 > *q2)
//		swap(q1, q2);
//	if (*q1 > *q3)
//		swap(q1, q3);
//	if (*q2 > *q3)
//		swap(q2, q3);
//}
//void swap(int *pt1, int *pt2)
//{
//	int temp;
//	temp = *pt1;
//	*pt1 = *pt2;
//	*pt2 = temp;
//}

#include<stdio.h>
int main()
{
	void swap(int *p1, int *p2);
	int *p, A[3];
	p = A;
	int i; 
	for (i = 0; i < 3; i++)
		scanf_s("%d", &A[i]);
	for (i = 0; i < 3; i++)
		if (A[i] > A[i + 1])
			swap(p + i, p + i + 1);
	for (i = 0; i < 3; i++)
		printf("%d ", A[i]);
	return 0;
}
void swap(int *p1, int*p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//无函数
//#include<stdio.h>
//int main()
//{
//	int a, b, c, *p1, *p2, *p3, *p;
//	printf("请输入3个数字:\n");
//	scanf("%d %d %d", &a, &b, &c);
//	p1 = &a; p2 = &b; p3 = &c;
//	if (a > b) { p = p1; p1 = p2; p2 = p; }
//	if (a > c) { p = p1; p1 = p3; p3 = p; }
//	if (b > c) { p = p2; p2 = p3; p3 = p; }
//	printf("由小到大排列是\n");
//	printf("%d %d %d", *p1, *p2, *p3);
//	return 0;
//}