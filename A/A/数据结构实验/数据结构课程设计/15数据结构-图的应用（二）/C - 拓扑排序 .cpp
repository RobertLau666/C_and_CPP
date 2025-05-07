#include <stdio.h>
#include <string.h>
int op, tp, n, m;
int link[14], map[14][14], IN[14];
//拓扑排序算法核心语句
void topo()
{
	for (int i = 1; i <= n; i++)//寻找入度为零的点
		if (IN[i] == 0)//判断是否是入度为零的点
			link[tp++] = i;//将入度为零的点入队
	while (op < tp)//更新的过程
	{
		for (int i = 1; i <= n; i++)//寻找入度为当前队列结点的点的点
			if (map[link[op]][i] == 1)//判断是否入度为当前队列结点
			{
				IN[i]--;//结点入度数目更新
				if (IN[i] == 0)//判断更新后是否有入度为零的点
					link[tp++] = i;//将更新后入度为零的点入队
			}
		op++;//当前队列结点出队
	}
	if (op == n)//判断出队结点数是否是总结点数，若是，则为合法拓扑序列，若不是，则存在有向回路
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int u, v;
	while (~scanf("%d %d", &n, &m))
	{
		op = tp = 0;//队列标记变量初始化
		memset(map, 0, sizeof(map));//map数组初始化，将数组map的前sizeof（map）位设置为0
		memset(IN, 0, sizeof(IN));//IN数组（记录结点入度数目）初始化
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &u, &v);
			map[u][v] = 1;
			IN[v] += 1;
		}
		topo();
	}
	return 0;
}
