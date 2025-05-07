#include <iostream>  
using namespace std;
int father[30001]; //存储father index  
int group[30001]; //存储当前  集合的人数  
				  //初始化  
void init(int len) {
	for (int i = 0; i <= len; i++) {
		father[i] = i;
		group[i] = 1;
	}
}
//查找i的最终father  
int find_set(int i) {
	if (i != father[i]) {
		father[i] = find_set(father[i]); //路径压缩  
	}
	return father[i];
}
//合并两个点  
void join(int x, int y) {
	int i = find_set(x);
	int j = find_set(y);
	if (i != j) {
		father[i] = father[j];
		group[j] += group[i]; //合并时，由于最终father保存当前集合人数  

	}
}

int main() {
	int n, m, k;
	while (cin >> n >> m) {
		if (n == 0)
			break;
		init(n); //初始化  
		for (int i = 0; i<m; i++) {
			cin >> k;
			int pre, cur; //前一个 和 当前  
			for (int j = 0; j<k; j++) {
				cin >> cur;
				if (j) //第一个数不用管  
					join(pre, cur);
				pre = cur;
			}
		}
		//测试  
		//      for(int i=0; i<n; i++)  
		//          cout << father[i] << " ";  
		//      cout << endl;  
		//  
		//      for(int i=0; i<n; i++)  
		//                  cout << group[i] << " ";  
		//              cout << endl;  
		//  
		//      cout << find_set(0) << endl;  
		cout << group[find_set(0)] << endl;
	}
	return 0;
}
