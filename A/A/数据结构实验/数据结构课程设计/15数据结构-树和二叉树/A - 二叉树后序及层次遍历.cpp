#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
struct node
{
	char data;
	struct node *l, *r;
};
struct node *creat(int n, char *str1, char *str2)//二叉树的先序遍历的第一个节点是子树的根，中序遍历中根节点的左边全都是左子树的中序，右边是右子树的中序  
{
	struct node *root;
	char *p;
	if (n == 0)//当节点为零时表明数据全部进入二叉树；
		return NULL;
	root = (struct node *)malloc(sizeof(struct node));
	root->data = str1[0];//先序的第一个为根节点  
	for (p = str2; p != '\0'; p++)
	{
		if (*p == str1[0])//在中序中找到根节点，从而分为左右两个部分；  
			break;
	}
	int t = p - str2;//左子树节点的个数  
	root->l = creat(t, str1 + 1, str2);//递归创建左子树；  
	root->r = creat(n - t - 1, str1 + t + 1, p + 1);//递归创建右子树  
	return root;
};
void houxu(struct node *root)//后序遍历
{
	if (root)
	{
		houxu(root->l);
		houxu(root->r);
		printf("%c", root->data);
	}
}
void bianli(struct node *root)//层次遍历
{
	int cnt = 0;
	int r1 = 1;
	struct node *q[60];//指针控制  
	q[0] = root;
	while (cnt<r1)//每一个q[cnt]都是子数树根；  
	{
		if (q[cnt])//为二叉树所以最多有2个子树，且只有当二叉树不为空时才可能有数据，为空时即可跳过，不打印  
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
	printf("输入组数：\n");
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		printf("分别输入前序、中序遍历：\n");
		scanf("%s %s", str1, str2);
		int n = strlen(str1);
		root = creat(n, str1, str2);
		printf("后序、层序遍历分别为：\n");
		houxu(root);
		printf("\n");
		bianli(root);
		printf("\n");
	}
	return 0;
}

