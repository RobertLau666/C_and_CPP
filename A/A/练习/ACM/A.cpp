#include<stdio.h>
#include<string.h>
int main()
{
	int n, i, j,t;
	char s[100],r[100];
	scanf_s("%d",&n);
	getchar();
	for (i = 0; i < n; i++)
	{
		t = 0;
		gets_s(s,100);
		gets_s(r,100);
		for (j = 0; j < strlen(s); j++)
		{
			if (s[j] == r[j])
				t++;
		}
		printf("%d\n",t);
	}
	return 0;
}