#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2//溢出

#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)

typedef int Status;
typedef int KeyType;

typedef struct {
	KeyType key;
}SNode;

typedef struct {
	SNode *elem;
	int length;
}SSTable;

Status Create(SSTable &ST, int n)
{
	int i;
	ST.elem = (SNode *)malloc(n * sizeof(SNode));
	ST.length = n;
	if (!ST.elem)
		exit(OVERFLOW);
	printf("依次输入元素:");
	for (i = 1; i <=n; i++)      //不含elem[0]
		scanf_s("%d", &ST.elem[i].key);
	return OK;
}

int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1, high = ST.length, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid].key))
			return mid;
		else
			if (LT(key, ST.elem[mid].key))
				high = mid - 1;
			else
				low = mid + 1;
	}
	return 0;//不存在待查元素
}
int main()
{
	SSTable T;
	int n, m, i = 2;
	printf("顺序存储及折半查找\n输入有序表的元素个数：");
	scanf_s("%d", &n);
	Create(T, n);
	while (i)
	{
		printf("输入待查元素：");
		scanf_s("%d", &m);
		printf("位置是：%d\n", Search_Bin(T, m));
		i--;
	}
}