#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
struct node
{
	char data;
	struct node *l, *r;
};
struct node *creat(int n, char *str1, char *str2)//����������������ĵ�һ���ڵ��������ĸ�����������и��ڵ�����ȫ�����������������ұ���������������  
{
	struct node *root;
	char *p;
	if (n == 0)//���ڵ�Ϊ��ʱ��������ȫ�������������
		return NULL;
	root = (struct node *)malloc(sizeof(struct node));
	root->data = str1[0];//����ĵ�һ��Ϊ���ڵ�  
	for (p = str2; p != '\0'; p++)
	{
		if (*p == str1[0])//���������ҵ����ڵ㣬�Ӷ���Ϊ�����������֣�  
			break;
	}
	int t = p - str2;//�������ڵ�ĸ���  
	root->l = creat(t, str1 + 1, str2);//�ݹ鴴����������  
	root->r = creat(n - t - 1, str1 + t + 1, p + 1);//�ݹ鴴��������  
	return root;
};
void houxu(struct node *root)//�������
{
	if (root)
	{
		houxu(root->l);
		houxu(root->r);
		printf("%c", root->data);
	}
}
void bianli(struct node *root)//��α���
{
	int cnt = 0;
	int r1 = 1;
	struct node *q[60];//ָ�����  
	q[0] = root;
	while (cnt<r1)//ÿһ��q[cnt]��������������  
	{
		if (q[cnt])//Ϊ���������������2����������ֻ�е���������Ϊ��ʱ�ſ��������ݣ�Ϊ��ʱ��������������ӡ  
		{
			printf("%c", q[cnt]->data);
			q[r1++] = q[cnt]->l;
			q[r1++] = q[cnt]->r;
		}
		cnt++;
	}
}
int main()
{
	int n;
	char str1[60], str2[60];
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	printf("����������\n");
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		printf("�ֱ�����ǰ�����������\n");
		scanf("%s %s", str1, str2);
		int n = strlen(str1);
		root = creat(n, str1, str2);
		printf("���򡢲�������ֱ�Ϊ��\n");
		houxu(root);
		printf("\n");
		bianli(root);
		printf("\n");
	}
	return 0;
}

