#include <stdio.h>

int main()
{
	int year, month, day;//������
	int judge, i;
	int sum = 0;//�������
	int date[2][12] = {
		{ 31,28,31,30,31,30,31,31,30,31,30,31 },
		{ 31,29,31,30,31,30,31,31,30,31,30,31 } };//��������ͷ�����ÿһ�µ�����
	printf("����������:");
	scanf("%d %d %d", &year, &month, &day);

	judge = (year % 4 == 0) || (year % 400 == 0 && year % 100 != 0);
	//�ж�����ǲ�������  ������judge����1;�������0

	for (i = 0; i < month - 1; i++)//��month֮ǰ����������
		sum += date[judge][i];
	sum += day;//�ӵ����·ݵ�����day

	printf("����%d���еĵ�%d��\n", year, sum);
	return 0;
}