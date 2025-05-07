#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, k, L, m, max;
	char A[100];
	while (scanf_s("%s", A, 100) != EOF)
	{
		max = 0;
		L = strlen(A);
		for (i = 0; i < L; i++)
			for (j = i + 1; j < L; j++)
			{
				for (k = i; k <= (i + j) / 2; k++)
					if (A[k] != A[i + j - k])
						break;
				if (k == (i + j) / 2 + 1)
				{
					m = j - i + 1;
					if (m > max)
						max = m;
				}
			}
		printf("%d\n", max);
	}
	return 0;
}

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<malloc.h>
//#include<cstdlib>
//#include<algorithm>
//#include<queue>
//#include<stack>
//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N = 110010;
//char s[N], ns[N * 2];
//int len, p[N * 2];
//void Manacher() {
//	int i, j, id, maxd = 0, ans = 1;
//	int l = len * 2 + 2;
//	for (int i = 0; i<l; ++i) {
//		if (maxd>i) {
//			p[i] = min(p[2 * id - i], maxd - i);
//		}
//		else {
//			p[i] = 1;
//		}
//		while (ns[i + p[i]] == ns[i - p[i]]) {
//			++p[i];
//		}
//		if (p[i] + i>maxd) {
//			maxd = p[i] + i;
//			id = i;
//		}
//		if (ans<p[i]) {
//			ans = p[i];
//		}
//	}
//	printf("%d\n", ans - 1);
//}
//int main() {
//	while (~scanf("%s", s)) {
//		len = strlen(s);
//		ns[0] = '$';
//		ns[1] = '#';
//		for (int i = 0; i<len; ++i) {
//			ns[i * 2 + 2] = s[i];
//			ns[i * 2 + 3] = '#';
//		}
//		ns[2 * len + 2] = '\0';
//		Manacher();
//	}
//}