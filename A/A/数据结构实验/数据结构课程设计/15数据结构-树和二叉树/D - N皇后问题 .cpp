#include <stdio.h>  
#include <string.h>  

int map[20][20], cnt;
int ans[20] = { 0 }, num, n;

void dfs(int x, int y)
{
	if (map[x][y])
		return;
	int i, xx, yy;
	if (x == n)
	{
		num++;
		return;
	}
	//对8个方向进行搜索  
	xx = x; yy = y;
	while (xx>0) map[xx--][yy]++;
	xx = x; yy = y;
	while (yy>0) map[xx][yy--]++;
	xx = x; yy = y;
	while (xx <= n) map[xx++][yy]++;
	xx = x; yy = y;
	while (yy <= n) map[xx][yy++]++;
	xx = x; yy = y;
	while (xx <= n && yy <= n) map[xx++][yy++]++;
	xx = x; yy = y;
	while (xx>0 && yy <= n) map[xx--][yy++]++;
	xx = x; yy = y;
	while (xx <= n && yy>0) map[xx++][yy--]++;
	xx = x; yy = y;
	while (xx>0 && yy>0) map[xx--][yy--]++;

	for (i = 1; i <= n; i++)
	{
		dfs(x + 1, i);
	}
	//恢复原样  
	xx = x; yy = y;
	while (xx>0) map[xx--][yy]--;
	xx = x; yy = y;
	while (yy>0) map[xx][yy--]--;
	xx = x; yy = y;
	while (xx <= n) map[xx++][yy]--;
	xx = x; yy = y;
	while (yy <= n) map[xx][yy++]--;
	xx = x; yy = y;
	while (xx <= n && yy <= n) map[xx++][yy++]--;
	xx = x; yy = y;
	while (xx <= n && yy>0) map[xx++][yy--]--;
	xx = x; yy = y;
	while (xx>0 && yy <= n) map[xx--][yy++]--;
	xx = x; yy = y;
	while (xx>0 && yy>0) map[xx--][yy--]--;
}

void set()
{
	int i, j;
	for (i = 1; i <= 10; i++)
	{
		num = 0; n = i;
		for (j = 1; j <= i; j++)
		{
			memset(map, 0, sizeof(map));
			dfs(1, j);
		}
		ans[i] = num;
	}
}

int main()
{
	set();
	while (~scanf("%d", &n), n)
	{
		printf("%d\n", ans[n]);
	}

	return 0;
}
