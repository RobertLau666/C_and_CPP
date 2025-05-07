#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include <algorithm>
#include<functional>//greater
using namespace std;
int main()
{
	int t, i, n, m, a, b, sum, d[10000];
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		memset(d, 0, sizeof(d));
		priority_queue<int, vector<int>, greater<int> >p;//优先队列
		scanf("%d%d", &n, &m);
		for (i = 0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			d[a]++;
			d[b]++;
		}
		sort(d + 1, d + n + 1);//对度数排序
		for (i = 1; i <= n; i++)
			if (d[i]<2)
				p.push(d[i]);
			else
				break;
		while (p.size() >= 2)
		{
			a = p.top();
			p.pop();
			b = p.top();
			p.pop();
			a++;
			b++;
			sum++;
			if (a<2)
				p.push(a);
			if (b<2)
				p.push(b);
		}
		if (!p.empty())
			sum++;
		printf("%d\n", sum);
	}
	return 0;
}
