#include<iostream>  
using namespace std;
int main()
{
	int a[1010];
	int T, u, v, n, m, sum;
	cin >> T;
	while (T--)
	{
		sum = 0;
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
			a[i] = i;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			while (u != a[u])//�൱�ڰ��ظ������������Ұ�u��v��ת��Ϊ������ͨͼ��ͷ��
				u = a[u];
			while (v != a[v])
				v = a[v];
			if (u != v)
				a[u] = v;
		}
		for (int i = 1; i <= n; i++)
			if (i == a[i])
				sum++;
		cout << sum << endl;
	}
	return 0;
}


