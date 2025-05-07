#include<stdio.h>
#include<math.h>
void A(double a, double b, double c)
{
	double n = sqrt(b*b - 4 * a*c);
	double x1, x2;
	x1 = (-b + n) / (2 * a);
	x2 = (-b - n) / (2 * a);
	printf("x1=%.1f\nx2=%.1f", x1, x2);
}
void B(double a, double b, double c)
{
	double x1, x2;
	x1=x2= (-b)/ (2 * a);
	printf("x1=%.1f\nx2=%.1f", x1, x2);
}
void C(double a, double b, double c)
{
	printf("Ã»ÓÐ¸ù");
}
int main()
{
	double a, b, c, n;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	n = b*b - 4 * a*c;
	if (n > 0)
		A(a, b, c);
	if (n == 0)
		B(a, b, c);
	if (n < 0)
		C(a, b, c);
}