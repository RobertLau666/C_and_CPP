#include<stdio.h>

int c=0;//�ƶ�����

void move(char x,int n,char y)
//�����Ϊn��Բ�̴�x�Ƶ�y
{
	printf("%d.Move disk %d from %c to %c\n", ++c, n, x, y);
}
void hanoi(int n, char x, char y, char z)
//��������x�ϰ�ֱ���ɴ�С�����϶��±��Ϊ1��n��n��Բ�̰�����ᵽ����z�ϣ�y����������
{
	if (n == 1)
		move(x,1,z);//�����Ϊ1��Բ�̴�x�Ƶ�z
	else
	{
		hanoi(n-1,x,z,y);//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
		move(x,n,z);//�����Ϊ1��Բ�̴�x�Ƶ�z
		hanoi(n-1,y,x,z);//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
	}
}

void main()
{
	int n;
	printf("������Բ�̸���n�Խ��n�׺�ŵ�����⣺\n");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}