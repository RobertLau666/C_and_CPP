//#include <iostream>
//using namespace std;
//typedef char Elem_Type;
//typedef struct BiTNode
//{
//	Elem_Type data;
//	BiTNode *lchild;
//	BiTNode *rchild;
//}BiTNode;
//void CreateBiTree(BiTNode* *root)
//{
//	Elem_Type temp;
//	cin >> temp;
//	if (temp == ',')
//		*root = NULL;
//	else
//	{
//		*root = new BiTNode;
//		(*root)->data = temp;
//		CreateBiTree(&(*root)->lchild);
//		CreateBiTree(&(*root)->rchild);
//	}
//}
//void InOrderTraverse(BiTNode *root)
//{
//	if (root)
//	{
//		InOrderTraverse(root->lchild);
//		cout << root->data;
//		InOrderTraverse(root->rchild);
//	}
//}
//void PostOrderTraverse(BiTNode *root)
//{
//	if (root)
//	{
//		PostOrderTraverse(root->lchild);
//		PostOrderTraverse(root->rchild);
//		cout << root->data;
//	}
//}
//int LeafNodes(BiTNode *root)
//{
//	static int count = 0;
//	if (!root)
//		return 0;
//	if (!root->lchild && !root->rchild)
//		count++;
//	LeafNodes(root->lchild);
//	LeafNodes(root->rchild);
//	return count;
//}
//int BiTreeDepth(BiTNode *root)
//{
//	if (!root)
//		return 0;
//	return (BiTreeDepth(root->lchild) > BiTreeDepth(root->rchild) ?
//		BiTreeDepth(root->lchild) : BiTreeDepth(root->rchild)) + 1;
//}
//int main()
//{
//	BiTNode *root = NULL;
//	CreateBiTree(&root);
//	/*InOrderTraverse(root);
//	cout << endl;
//	PostOrderTraverse(root);
//	cout << endl;*/
//	cout << LeafNodes(root) << endl;
//	/*cout << BiTreeDepth(root) << endl;*/
//	return  0;
//}

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char a[100];
int l1;
struct node
{
	int data;
	struct node *lchild, *rchild;
};
struct node *creat()
{
	struct node  *root;
	char c;
	c = a[l1++];
	if (c == ',')
		return NULL;
	else
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->data = c;
		root->lchild = creat();
		root->rchild = creat();
	}
	return root;
}
int leave(struct node *root)
{
	if (root == NULL)
		return 0;
	if (root->lchild == NULL&&root->rchild == NULL)
		return 1;
	else
		return leave(root->lchild) + leave(root->rchild);
}
int main()
{
	int i, j, n, m, k, t;
	struct node *root;
	while (scanf("%s", a) != EOF)
	{
		l1 = 0;
		root = (struct node *)malloc(sizeof(struct node));
		root = creat();
		k = leave(root);
		printf("%d\n", k);
	}
	return 0;
}
