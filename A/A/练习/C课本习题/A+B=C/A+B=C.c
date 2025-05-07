//分别对AB输入字母，再将字母排序存到C。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *in1,*in2,*out,*inc;
	errno_t e1, e2;
	int i, j, k,t;
	char ch, a[20], b[10];
	printf("输入A：");
	if ((e1 = fopen_s(&in1, "A+B=C\\A.txt", "w")) != 0)
	{
		printf("1不能打开！");
		exit(0);
	}
	scanf_s("%s",a,20);
	ch = getchar();
	fputs(a,in1);
	printf("输入B：");
	if ((e2 = fopen_s(&in2, "A+B=C\\B.txt", "w")) != 0)
	{
		printf("2不能打开！");
		exit(0);
	}
	scanf_s("%s", b, 10);
	ch = getchar(); 
	fputs(b,in2);
	fclose(in1);
	fclose(in2);
	if ((e1 = fopen_s(&in1, "A+B=C\\A.txt", "r")) != 0)
	{
		printf("3不能打开！");
		exit(0);
	}
	if ((e2 = fopen_s(&in2, "A+B=C\\B.txt", "r")) != 0)
	{
		printf("4不能打开！");
		exit(0);
	}
	fgets(a,10,in1);
	fgets(b,10,in2);
	fclose(in1);
	fclose(in2);
	printf("%s\n",a);
	printf("%s\n",b);
	strcat_s(a, 20, b);
	printf("连接后为：%s\n",a);
	for (i = 0;a[i]!='\0'; i++)
	{
		k = i;
		for (j = i + 1; a[j]!='\0'; j++)
			if (a[j] <a[k])
				k = j;
		t = a[k]; a[k] = a[i]; a[i] = t;
	}
	printf("排完序为：%s\n",a);
	if ((e1 = fopen_s(&out, "A+B=C\\C.txt", "w")) != 0)
	{
		printf("5不能打开！");
		exit(0);
	}
	fputs(a,out);
	fclose(out);
	if ((e2 = fopen_s(&inc, "A+B=C\\C.txt", "r")) != 0)
	{
		printf("6不能打开！");
		exit(0);
	}
	fputs(a,inc);
	printf("读出来为：%s\n",a);
	return 0;
}