#include<stdio.h>
#include<string.h>

int main()
{
	char name[3][100], t_name[100];
	int num[3], t_num, n;

	int i, j;

	for (i = 0; i < 3; i++)
		scanf_s("%s %d", name[i], 100, &num[i]);

	printf("ÊäÈëÒª²éÕÒºÅ:");
	scanf_s("%d", &n);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2 - i; j++)
			if (num[j] > num[j + 1])
			{
				t_num = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t_num;
				strcpy_s(t_name, name[j]);
				strcpy_s(name[j], name[j + 1]);
				strcpy_s(name[j + 1], t_name);
			}

	int low = 0, high = 3 - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (n > num[mid])
			low = mid + 1;
		else if (n < num[mid])
			high = mid - 1;
		else
		{
			printf("%d %s\n", num[mid], name[mid]);
			break;
		}
	}
}