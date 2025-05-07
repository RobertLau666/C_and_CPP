//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<queue>
//using namespace std;
//class cmp
//{
//public:
//	bool operator()(const __int64 a, const __int64 b)const
//	{
//		return a>b;
//	}
//};
//int main(void)
//{
//	int n;
//	while (cin >> n)
//	{
//		priority_queue<__int64, vector<__int64>, cmp>Queue;
//		for (int i = 1; i <= n; i++)
//		{
//			__int64 temp;
//			scanf("%I64d", &temp);
//			Queue.push(temp);
//		}
//		__int64 mincost = 0;
//		while (Queue.size()>1)
//		{
//			__int64 a = Queue.top();
//			Queue.pop();
//			__int64 b = Queue.top();
//			Queue.pop();
//			Queue.push(a + b);
//			mincost += a + b;
//		}
//		printf("%I64d\n", mincost);
//		while (!Queue.empty())
//			Queue.pop();
//	}
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int *a;
	int i, j, n, sum;
	__int64 ans;   //不用64位过不了
	while (~scanf("%d", &n))
	{
		a = new int[n];   //每个模板的价值
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		ans = 0;
		for (i = 0; i < n - 1; ++i)
		{
			sum = a[i] + a[i + 1];
			ans += sum;
			for (j = i + 2; j < n; ++j)
			{
				if (sum > a[j])
					a[j - 1] = a[j];
				else
				{
					a[j - 1] = sum;
					break;
				}
			}
			if (j == n)   //说明sum比所有元素都大,把sum直接放在最后
				a[j - 1] = sum;
		}
		printf("%I64d\n", ans);;
	}
	return 0;
}