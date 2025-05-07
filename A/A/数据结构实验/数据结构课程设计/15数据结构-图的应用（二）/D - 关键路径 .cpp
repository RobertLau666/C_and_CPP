#include<iostream>  
#include<algorithm>  
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<math.h>  

using namespace std;
const int INF = 0;

struct node
{
	int x, y, z;
}q[1001000];

struct node1
{
	int a, b;
};

int n, m;
int t;
struct node1 num[1100001];

void add(int x, int y, int z)
{
	q[t].x = x;
	q[t].y = y;
	q[t++].z = z;
}

void BF()
{
	for (int i = 0; i <= n; i++)
	{
		num[i].a = INF;
		num[i].b = -1;
	}
	num[n].a = 0;
	int flag = 0;
	for (int i = 1; i<n; i++)
	{
		flag = 0;
		for (int j = 0; j<t; j++)
			if (num[q[j].y].a - q[j].z < num[q[j].x].a || (num[q[j].y].a - q[j].z == num[q[j].x].a&&q[j].y<num[q[j].x].b))
			{
				num[q[j].x].a = (num[q[j].y].a - q[j].z);
				num[q[j].x].b = q[j].y;
				//num[q[j].y].b = q[j].x;
				flag = 1;
			}
		if (flag == 0)
			break;
	}
	printf("%d\n", -num[1].a);
	int xx[10100];
	memset(xx, 0, sizeof(xx));
	int h = 0;
	xx[h++] = 1;
	for (int i = 1; num[i].b != n;)
	{
		i = num[i].b;
		xx[h++] = i;
	}
	xx[h] = n;
	for (int i = 0; i<h; i++)
		printf("%d %d\n", xx[i], xx[i + 1]);
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		t = 0;
		int x, y, z;
		for (int i = 0; i<m; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		BF();
	}
	return 0;
}
