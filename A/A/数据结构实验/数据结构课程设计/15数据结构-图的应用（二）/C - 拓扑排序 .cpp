#include <stdio.h>
#include <string.h>
int op, tp, n, m;
int link[14], map[14][14], IN[14];
//���������㷨�������
void topo()
{
	for (int i = 1; i <= n; i++)//Ѱ�����Ϊ��ĵ�
		if (IN[i] == 0)//�ж��Ƿ������Ϊ��ĵ�
			link[tp++] = i;//�����Ϊ��ĵ����
	while (op < tp)//���µĹ���
	{
		for (int i = 1; i <= n; i++)//Ѱ�����Ϊ��ǰ���н��ĵ�ĵ�
			if (map[link[op]][i] == 1)//�ж��Ƿ����Ϊ��ǰ���н��
			{
				IN[i]--;//��������Ŀ����
				if (IN[i] == 0)//�жϸ��º��Ƿ������Ϊ��ĵ�
					link[tp++] = i;//�����º����Ϊ��ĵ����
			}
		op++;//��ǰ���н�����
	}
	if (op == n)//�жϳ��ӽ�����Ƿ����ܽ���������ǣ���Ϊ�Ϸ��������У������ǣ�����������·
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int u, v;
	while (~scanf("%d %d", &n, &m))
	{
		op = tp = 0;//���б�Ǳ�����ʼ��
		memset(map, 0, sizeof(map));//map�����ʼ����������map��ǰsizeof��map��λ����Ϊ0
		memset(IN, 0, sizeof(IN));//IN���飨��¼��������Ŀ����ʼ��
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &u, &v);
			map[u][v] = 1;
			IN[v] += 1;
		}
		topo();
	}
	return 0;
}
