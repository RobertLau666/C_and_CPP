#include<stdio.h>

int c=0;//移动次数

void move(char x,int n,char y)
//将编号为n的圆盘从x移到y
{
	printf("%d.Move disk %d from %c to %c\n", ++c, n, x, y);
}
void hanoi(int n, char x, char y, char z)
//将塔座上x上按直径由大到小且自上而下编号为1至n的n个圆盘按规则搬到塔座z上，y作辅助塔座
{
	if (n == 1)
		move(x,1,z);//将编号为1的圆盘从x移到z
	else
	{
		hanoi(n-1,x,z,y);//将x上编号为1至n-1的圆盘移到y，z作辅助塔
		move(x,n,z);//将编号为1的圆盘从x移到z
		hanoi(n-1,y,x,z);//将x上编号为1至n-1的圆盘移到y，z作辅助塔
	}
}

void main()
{
	int n;
	printf("请输入圆盘个数n以解决n阶汉诺塔问题：\n");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}