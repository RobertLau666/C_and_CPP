#include<stdio.h>
#include<string.h>
void A(char a[], char b[])
{
	printf("%s", strcat(a, b));
}
int main()
{
	char a[100], b[100];
	scanf_s("%s %s", a, 100, b, 100);
	A(a, b);
}