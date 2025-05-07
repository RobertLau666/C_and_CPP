#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*fp1;
	char a[1000][10],c,d;
	int i, j;
	errno_t e;
	if (e = fopen_s(&fp, "10-11×ÖÄ¸×ª»»\\zimu.txt", "w") != 0)
	{
		printf("1cannot open the file\n");
		exit(0);
	}
	printf("enter strings\n");
	for (i = 0;; i++)
	{
		scanf_s("%s",a[i],10);
		c = getchar();
		printf("continue?y\\n\n");
		d = getchar();
		c = getchar();
		if (d == 'n')
		{
			i++;
			break;
		}
	}
	for (j = 0; j < i; j++)
	{
		fputs(a[j], fp);
		fputs("\n",fp);
	}
	fclose(fp);
	if (e = fopen_s(&fp1, "10-11×ÖÄ¸×ª»»\\zimu.txt", "r") != 0)
	{
		printf("2cannot open the file\n");
		exit(0);
	}
	i = 0;
	while (fgets(a[i], 10, fp1) != NULL)
	{
		for (j = 0;( c = a[i][j]) != '\n'; j++)
			if (c >= 'a'&&c <= 'z')
				a[i][j] -= 32;
		printf("%s",a[i]);
		i++;
	}
	fclose(fp1);
	return 0;
}