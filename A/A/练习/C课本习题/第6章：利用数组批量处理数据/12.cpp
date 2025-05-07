#include<stdio.h>
int main()
{
	char S[] = "absa13123&^&*HJKHJKGKG", c;
	int i;
	puts(S);
	for (i = 0; (c = S[i]) != '\0'; i++)
	{
		if (c >= 'a'&&c <= 'z')
			S[i] = 219 - c;
		if (c >= 'A'&&c <= 'Z')
			S[i] = 155 - c;
	}
	printf("%s\n", S);
}