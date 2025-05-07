#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

const int N = 1010;

int n, pre[N], in[N];
stack<int> st;

void build(int l1, int r1, int l2, int r2) {
	int i, j;
	st.push(pre[l1]);
	for (i = l2; i <= r2; i++)
		if (in[i] == pre[l1])
			break;
	j = l1 + (i - l2 + 1); 
	if (j <= r1 && i + 1 <= r2) 
		build(j, r1, i + 1, r2);
	if (l1 + 1 <= j - 1 && l2 <= i - 1)
		build(l1 + 1, j - 1, l2, i - 1);
}

int main() {
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &in[i]);
		build(0, n - 1, 0, n - 1);
		while (!st.empty())
		{
			printf("%d", st.top());
			st.pop();
			if (!st.empty())
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}