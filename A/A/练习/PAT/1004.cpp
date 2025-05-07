#include<stdio.h>
struct S
{
	char name[20];
	char no[20];
	int grade;
}s[100];
struct S t;
int main()
{
	int i, j, n;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf_s("%s %s %d", s[i].name, sizeof(s[i].name), s[i].no, sizeof(s[i].no), &s[i].grade);//pat:ÎÞ_s,±àÒë´íÎó£»ÎÞsizeof()¶Î´íÎó
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
				if (s[j].grade < s[j + 1].grade)
				{
					t = s[j];
					s[j] = s[j + 1];
					s[j + 1] = t;
				}
		printf("%s %s\n%s %s\n", s[0].name, s[0].no, s[n - 1].name, s[n - 1].no);
	}
	return 0;
}