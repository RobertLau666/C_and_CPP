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
//const int N = 1e6 + 5;
//char str[N];
//int n;
//bool judge() {
//	stack<int>s1;
//	stack<int>s2;
//	for (int i = 0; i<n; ++i) {
//		if ('(' == str[i]) {
//			s1.push(i);
//		}
//		else if ('?' == str[i]) {
//			s2.push(i);
//		}
//		else {
//			if (s1.empty() && s2.empty()) {
//				return 0;
//			}
//			if (!s1.empty()) {
//				s1.pop();
//			}
//			else {
//				s2.pop();
//			}
//		}
//	}
//	if (s1.size()>s2.size()) {
//		return 0;
//	}
//	else {
//		while (!s1.empty()) {
//			int t1 = s1.top();//×óÀ¨ºÅ
//			int t2 = s2.top();//ÎÊºÅ
//			if (t1>t2)return 0;
//			s1.pop();
//			s2.pop();
//		}
//		return 1;
//	}
//}
//int main() {
//	while (~scanf("%s", str)) {
//		n = strlen(str);
//		if (n % 2 == 1) {
//			printf("None\n");
//			continue;
//		}
//		bool f1 = judge(), f2 = 0;
//		if (!f1) {
//			printf("None\n");
//			continue;
//		}
//		int i;
//		for (i = 0; i<n; ++i) {
//			if ('?' == str[i]) {
//				str[i] = '(';
//				f1 = judge();
//				str[i] = ')';
//				f2 = judge();
//				if (f1&&f2) {
//					printf("Many\n");
//					break;
//				}
//				else if (!f1 && !f2) {
//					printf("None\n");
//					break;
//				}
//				else if (f1 && !f2) {
//					str[i] = '(';
//				}
//			}
//		}
//		if (i == n) {
//			printf("Unique\n");
//		}
//	}
//}