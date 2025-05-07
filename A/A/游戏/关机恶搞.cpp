#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n;
	char a[10];
	printf("叫大哥,不叫就关机(你有一分钟的时间,如果关闭本程序一样要关机)\n");
	//system("cls");//清屏,等于在DOS上使用cls命令
	//system("notepad");//打开记事本程序，关闭之后才继续运行以下
	//system("calc.exe");//运行计算器
	system("shutdown -r");//关机提醒
	while (1)
	{
		printf("叫:");
		scanf("%s", &a);
		n = strcmp(a, "大哥");
		if (n == 0)
		{
			system("shutdown -a");//取消关机
			printf("嗯，真乖!!!爽!哈哈哈!!！");
			break;
		}
	}
}