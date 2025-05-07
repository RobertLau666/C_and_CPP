#include<stdio.h>
#define N 3
struct student {
	int num;
	char name[10];
	float score[3];
	float aver;
}stu[N+1];
struct student new;
void write() {
	FILE *fp;
	int i;
	errno_t e;
	if ((e = fopen_s(&fp, "10-5.aver\\stu.txt", "wb")) != 0)
	{
		printf("cannot open file\n");
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);
}
void read() {
	struct student t;
	FILE *fp;
	int i,j,M;
	errno_t e;
	if ((e = fopen_s(&fp, "10-5.aver\\stu.txt", "rb")) != 0)
	{
		printf("cannot open file\n");
		return 0;
	}
	printf("读进去的内容：\n");
	for (i = 0; i < N; i++)
	{
		if (fread(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("file read error\n");
		printf("%d %s %.2f %.2f %.2f %.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
			if (stu[i].aver < stu[i + 1].aver)
				t = stu[i]; stu[i] = stu[i + 1]; stu[i + 1] = t;
	}
	if ((e = fopen_s(&fp, "10-5.aver\\stu_sort.txt", "wb")) != 0) {
		printf("cannot open file\n");
		return 0;
	}
	printf("排序之后：\n");
	for (i = 0; i < N;i++)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("file write error\n");
		printf("%d %s %.2f %.2f %.2f %.2f %d\n", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].aver,i+1);
	}
	fclose(fp);//是为了文件安全，并没有封锁里面的内容
	i--;
	printf("关闭指针fp之后（write all）还能显示出来：%d %s %.2f %.2f %.2f %.2f %d\n", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].aver, i+1);
	printf("enter the data of new student:\n");
	scanf_s("%d %s %f %f %f",&new.num,new.name,10,&new.score[0],&new.score[1],&new.score[2]);
	new.aver = (new.score[0]+ new.score[1]+new.score[2]) / 3;
	M=N+1;
	for (i = 0; i < M; i++)
		if (stu[i].aver > new.aver&&new.aver > stu[i + 1].aver)
		{
			for (j = M; j > i + 1; j--)
				stu[j] = stu[j - 1];
			stu[j] = new;
		}
		else
			stu[M] = new;
	if ((e = fopen_s(&fp, "10-5.aver\\stu_newsort.txt", "wb")) != 0)
	{
		printf("cannot open the file\n");
		return 0;
	}
	printf("插完再排序：\n");
	for (i = 0; i < M; i++)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("file write errr\n");
		printf("%d %s %.2f %.2f %.2f %.2f %d\n", stu[i].num, stu[i].name,stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].aver, i + 1);
	}

}
int main()
{
	int i,j;
	float s;
	printf("please enter data of studnet:\n");
	for (i = 0; i < N; i++)
	{
		s = 0;
		scanf_s("%d %s %f %f %f", &stu[i].num, stu[i].name,10, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		for (j = 0; j < N; j++)
			s = s + stu[i].score[j];
		stu[i].aver = s / 3;
	}
	write();
	read();
	return 0;
}