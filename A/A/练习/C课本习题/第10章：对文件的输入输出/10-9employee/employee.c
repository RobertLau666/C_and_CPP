#include<stdio.h>
#include<stdlib.h>
#define N 3
struct employee {
	char name[10];
	int num;
	char sex;
	double wages;
}em[N];
int main()
{
	int i;
	FILE *fp;
	errno_t e;
	printf("enter the data of employees\n");
	for (i = 0; i < N; i++)
		scanf_s("%s %d %c %lf",em[i].name,10,&em[i].num,&em[i].sex,1,&em[i].wages);
	if ((e = fopen_s(&fp, "10-9employee\\employee.txt", "wb")) != 0)
	{
		printf("1cannot open the file");
		exit(0);
	}
	for (i = 0; i < N; i++)
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);

	if ((e = fopen_s(&fp, "10-9employee\\employee.txt","rb")) != 0)
	{
		printf("2cannot open the file");
		exit(0);
	}
	printf("输出1、3位的所有数据\n");
	for (i = 0; i < N; i += 2)
	{
		fseek(fp, i * sizeof(struct employee), 0);
		fread(&em[i],sizeof(struct employee),1,fp);
		printf("%s %d %c %.2f\n", em[i].name,em[i].num,em[i].sex,em[i].wages);
	}
	printf("输出所有员工的名字、工资\n");
	for (i = 0; i < N; i ++)
	{
		fread(&em[i], sizeof(struct employee), 1, fp);
		printf("%s %.2f\n", em[i].name,em[i].wages);
	}
	fclose(fp);
	return 0;
}