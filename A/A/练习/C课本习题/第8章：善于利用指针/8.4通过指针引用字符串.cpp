////���һ���ַ���
//#include<stdio.h>
//int main()
//{
//    //8.16������
//	char String[] = "I Love China!";
//	printf("%s\n", String);
//	printf("%c\n", *(String + 7));
//	printf("%c\n", String[7]);
//
//    //8.17���ַ�ָ�����
//	char *string = "I Love China!";
//	printf("%s\n", string);
//	printf("%c\n", *(string + 2));
//	printf("%c\n", string[2]);
//	return 0;
//}

//8.18 a���Ƶ�b�����
//#include<stdio.h>
//int main()
//{
//	char a[] = "I am a student.", b[20];
//	int i;
//	for (i = 0; *(a + i) != '\0'; i++)
//		*(b + i) = *(a + i);
//	*(b + i) = '\0';
//	printf("string a is:%s\n", a);
//	printf("string b is:");
//	for (i = 0; *(b + i) != '\0'; i++)
//		printf("%c", *(b + i));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a[] = "I am a student.", b[20];
//	int i;
//	for (i = 0; a[i] != '\0'; i++)
//		b[i] = a[i];
//	b[i] = '\0';
//	printf("string a is:%s\n", a);
//	printf("string b is:");
//	for (i = 0; b[i] != '\0'; i++)
//		printf("%c", b[i]);
//	return 0;
//}

//8.19��ָ���������8.18
//#include<stdio.h>
//int main()
//{
//	char a[] = "I am a student.", b[20];
//	char *p1, *p2;
//	p1 = a, p2 = b;
//	for (; *p1 != '\0'; p1++, p2++)
//		*p2 = *p1;
//	*p2 = '\0';
//	printf("string a is:%s\n", a);
//	printf("string b is:%s\n", b);
//	return 0;
//}

//8.20�ú�������ʵ���ַ�������
//�ַ�����������
//#include<stdio.h>
//int main()
//{
//	void copy_string(char from[], char to[]);
//	char a[] = "I am a teacher.";
//	char b[] = "You are a student.";
//	printf("string a=%s\nstring b=%s\n", a, b);
//	printf("copy a to b:\n");
//	copy_string(a, b);
//	printf("string a=%s\nstring b=%s\n", a, b);
//	return 0;
//}
//void copy_string(char from[], char to[])
//{
//	int i = 0;
//	while (from[i] != '\0')
//	{
//		to[i] = from[i];
//		i++;
//	}
//	to[i] = '\0';
//}
//�ַ���ָ�������ʵ��
//#include<stdio.h>
//int main()
//{
//	void copy_string(char from[], char to[]);
//	char a[] = "I am a teacher.";
//	char b[] = "You are a student.";
//	char *from = a, *to = b;//
//	printf("string a=%s\nstring b=%s\n", a, b);
//	printf("copy a to b:\n");
//	copy_string(from, to);
//	printf("string a=%s\nstring b=%s\n", a, b);
//	return 0;
//}
//void copy_string(char from[], char to[])
//{
//	int i = 0;
//	while (from[i] != '\0')
//	{
//		to[i] = from[i];
//		i++;
//	}
//	to[i] = '\0';
//}
//�ַ�ָ��������βκ�ʵ��
//#include<stdio.h>
//int main()
//{
//	void copy_string(char * from,char * to);
//	char *a = "I am a teachar.";
//	char b[] = "You are a student.";
//	char *p = b;
//	printf("string a=%s\nstring b=%s\n", a, b);
//	printf("copy a to b:\n");
//	copy_string(a,p);
//	printf("string a=%s\nstring b=%s\n", a, b);
//	return 0;
//}
//void copy_string(char * from, char * to)
//{
//	for (; *from != '\0'; from++, to++)
//		*to = *from;
//	*to = '\0';
//
//	//while ((*to = *from) != '\0')
//	//{
//	//	to++;
//	//	from++;
//	//}
//
//	//while ((*to++ = *from++) != '\0');
//
//	//while (*from != '\0')
//	//	*to++ = *from++;
//	//*to = '\0';
//}

//8.20�ı�ָ�������ֵ
#include<stdio.h>
int main()
{
	char *a = "I Love China!";

	printf("%s\n", a);

	a = a + 7;
	printf("%s\n", a);

	char *format1 = "%s\n";
	printf(format1, a);

	char *format2;
	format2 = "%s\n";
	printf(format2, a);

	/////////////////////////////////
	char format3[] = "%s\n";
	printf(format3, a);
	//�Ƿ�
	//char format4[];
	//format4 = "%s\n";
	//printf(format4, a);

	return 0;
}