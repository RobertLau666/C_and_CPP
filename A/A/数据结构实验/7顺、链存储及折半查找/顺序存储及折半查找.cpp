#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2//���

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
	printf("��������Ԫ��:");
	for (i = 1; i <=n; i++)      //����elem[0]
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
	return 0;//�����ڴ���Ԫ��
}
int main()
{
	SSTable T;
	int n, m, i = 2;
	printf("˳��洢���۰����\n����������Ԫ�ظ�����");
	scanf_s("%d", &n);
	Create(T, n);
	while (i)
	{
		printf("�������Ԫ�أ�");
		scanf_s("%d", &m);
		printf("λ���ǣ�%d\n", Search_Bin(T, m));
		i--;
	}
}