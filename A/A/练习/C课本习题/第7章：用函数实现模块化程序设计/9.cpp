#include<stdio.h>
void A(char s[])
{
	int kongge = 0, shuzi = 0, zimu = 0, qita = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 32)
			kongge++;
		else if (s[i] >= 48 && s[i] <= 57)
			shuzi++;
		else if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122)
			zimu++;
		else
			qita++;
	}
	printf("�ո�%d ���֣�%d ��ĸ��%d ������%d\n", kongge, shuzi, zimu, qita);
}
int main()
{
	char S[100];
	printf("�������ַ�����");
	gets_s(S, 100);//������scanf_s("%s",S,100);��Ϊ���ո�ֹͣ
	A(S);
}