#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n;
	char a[10];
	printf("�д��,���о͹ػ�(����һ���ӵ�ʱ��,����رձ�����һ��Ҫ�ػ�)\n");
	//system("cls");//����,������DOS��ʹ��cls����
	//system("notepad");//�򿪼��±����򣬹ر�֮��ż�����������
	//system("calc.exe");//���м�����
	system("shutdown -r");//�ػ�����
	while (1)
	{
		printf("��:");
		scanf("%s", &a);
		n = strcmp(a, "���");
		if (n == 0)
		{
			system("shutdown -a");//ȡ���ػ�
			printf("�ţ����!!!ˬ!������!!��");
			break;
		}
	}
}