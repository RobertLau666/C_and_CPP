//�ֱ��AB������ĸ���ٽ���ĸ����浽C��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *in1,*in2,*out,*inc;
	errno_t e1, e2;
	int i, j, k,t;
	char ch, a[20], b[10];
	printf("����A��");
	if ((e1 = fopen_s(&in1, "A+B=C\\A.txt", "w")) != 0)
	{
		printf("1���ܴ򿪣�");
		exit(0);
	}
	scanf_s("%s",a,20);
	ch = getchar();
	fputs(a,in1);
	printf("����B��");
	if ((e2 = fopen_s(&in2, "A+B=C\\B.txt", "w")) != 0)
	{
		printf("2���ܴ򿪣�");
		exit(0);
	}
	scanf_s("%s", b, 10);
	ch = getchar(); 
	fputs(b,in2);
	fclose(in1);
	fclose(in2);
	if ((e1 = fopen_s(&in1, "A+B=C\\A.txt", "r")) != 0)
	{
		printf("3���ܴ򿪣�");
		exit(0);
	}
	if ((e2 = fopen_s(&in2, "A+B=C\\B.txt", "r")) != 0)
	{
		printf("4���ܴ򿪣�");
		exit(0);
	}
	fgets(a,10,in1);
	fgets(b,10,in2);
	fclose(in1);
	fclose(in2);
	printf("%s\n",a);
	printf("%s\n",b);
	strcat_s(a, 20, b);
	printf("���Ӻ�Ϊ��%s\n",a);
	for (i = 0;a[i]!='\0'; i++)
	{
		k = i;
		for (j = i + 1; a[j]!='\0'; j++)
			if (a[j] <a[k])
				k = j;
		t = a[k]; a[k] = a[i]; a[i] = t;
	}
	printf("������Ϊ��%s\n",a);
	if ((e1 = fopen_s(&out, "A+B=C\\C.txt", "w")) != 0)
	{
		printf("5���ܴ򿪣�");
		exit(0);
	}
	fputs(a,out);
	fclose(out);
	if ((e2 = fopen_s(&inc, "A+B=C\\C.txt", "r")) != 0)
	{
		printf("6���ܴ򿪣�");
		exit(0);
	}
	fputs(a,inc);
	printf("������Ϊ��%s\n",a);
	return 0;
}