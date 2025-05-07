#include<iostream>  
using namespace std;
#define MAX_N 20000  
typedef long long ll;
int N, L[MAX_N + 1];

void solve()
{
	ll ans = 0;
	/*ֱ��ľ��Ϊ1Ϊֹ */ 
	while (N>1)
	{
		/*�����̵İ�mil1�ʹζ̵İ�mil2*/
		int mil1 = 0, mil2 = 1;
		if (L[mil1]>L[mil2])
			swap(mil1, mil2);
		for (int i = 2; i<N; i++)
			if (L[i] < L[mil1])
			{
				mil2 = mil1;
				mil1 = i;
			}
			else
				if (L[i] < L[mil2])
					mil2 = i;
		/*ƴ�������*/
		int t = L[mil1] + L[mil2];
		ans += t;
		if (mil1 == N - 1)
			swap(mil1, mil2);
		L[mil1] = t;
		L[mil2] = L[N - 1];
		N--;
	}
	cout << ans << endl;
}
int main()
{
	cin >> N;
	for (int i = 0; i<N; i++)
		cin >> L[i];
	solve();
	return 0;
}
