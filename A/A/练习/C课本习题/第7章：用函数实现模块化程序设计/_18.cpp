#include <stdio.h>

int main()
{
	int year, month, day;//年月日
	int judge, i;
	int sum = 0;//标记天数
	int date[2][12] = {
		{ 31,28,31,30,31,30,31,31,30,31,30,31 },
		{ 31,29,31,30,31,30,31,31,30,31,30,31 } };//储存闰年和非闰年每一月的天数
	printf("输入年月日:");
	scanf("%d %d %d", &year, &month, &day);

	judge = (year % 4 == 0) || (year % 400 == 0 && year % 100 != 0);
	//判断年份是不是闰年  是闰年judge就是1;否则就是0

	for (i = 0; i < month - 1; i++)//加month之前的所有天数
		sum += date[judge][i];
	sum += day;//加当天月份的天数day

	printf("它是%d年中的第%d天\n", year, sum);
	return 0;
}