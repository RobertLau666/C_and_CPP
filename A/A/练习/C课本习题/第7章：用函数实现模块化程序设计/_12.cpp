#include<stdio.h>
#include<math.h>

int main()
{
	double solut(double, double, double, double);//函数原型声明
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	printf("%.2f", solut(a, b, c, d));
	return 0;
}

double solut(double a, double b, double c, double d)
{
	double x = 1, x0;
	do
	{
		x0 = x;
		x = x0 - (((a*x + b)*x + c)*x + d) / ((3 * a*x + 2 * b)*x + c);
	} while (fabs(x - x0) >= 1e-5);//为点xn+1与xn之间的距离，当两点的距离无限接近于0时，就时我们所要求的根x*。如果取x*这个点为例，我们发现方程在该点的切线与x轴的交点为x*，此时x与x0之间的距离为零。
	return x;
}