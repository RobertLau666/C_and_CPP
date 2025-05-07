#include<iostream>
using namespace std;
void fu1()
{
	static int n=1;
	n++;
	cout << n<< endl;
}
int main()
{
	for (int i = 0; i < 10; i++)
		fu1();
	return 0;
}