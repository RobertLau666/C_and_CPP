#include <iostream>  
using namespace std;
int father[30001]; //�洢father index  
int group[30001]; //�洢��ǰ  ���ϵ�����  
				  //��ʼ��  
void init(int len) {
	for (int i = 0; i <= len; i++) {
		father[i] = i;
		group[i] = 1;
	}
}
//����i������father  
int find_set(int i) {
	if (i != father[i]) {
		father[i] = find_set(father[i]); //·��ѹ��  
	}
	return father[i];
}
//�ϲ�������  
void join(int x, int y) {
	int i = find_set(x);
	int j = find_set(y);
	if (i != j) {
		father[i] = father[j];
		group[j] += group[i]; //�ϲ�ʱ����������father���浱ǰ��������  

	}
}

int main() {
	int n, m, k;
	while (cin >> n >> m) {
		if (n == 0)
			break;
		init(n); //��ʼ��  
		for (int i = 0; i<m; i++) {
			cin >> k;
			int pre, cur; //ǰһ�� �� ��ǰ  
			for (int j = 0; j<k; j++) {
				cin >> cur;
				if (j) //��һ�������ù�  
					join(pre, cur);
				pre = cur;
			}
		}
		//����  
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
