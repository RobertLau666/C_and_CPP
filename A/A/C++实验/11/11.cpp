#include<iostream>
#include<cassert>
using namespace std;
class Point
{
	friend class ArrayofPoints;
public:

	Point() :x(0), y(0)
	{
		cout << "Default Constructor called." << endl;
	}
	Point(int x, int y) :x(x), y(y)
	{
		cout << "Constructor called." << endl;
	}
	~Point() { cout << "Destructor called." << endl; }
	int getx() { return x; }
	int gety() { return y; }
	void move(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
private:
	int x, y;
};
class ArrayofPoints
{
public:
	ArrayofPoints(int size) :size(size)
	{
		points = new Point[size];
	}
	ArrayofPoints(ArrayofPoints &array)
	{
		size = array.size;
		points = new Point[size];
		for (int i = 0; i < size; i++)
			points[i] = array.points[i];
	}
	~ArrayofPoints()
	{
		cout << "Deleting..." << endl;
		delete[]points;
	}
	Point &element(int index)
	{
		assert(index >= 0 && index < size);
		return points[index];
	}
	Point & operator[](int i)const
	{
		assert(i >= 0 && i < size);
		return points[i];
	}
	ArrayofPoints operator+(const ArrayofPoints &c2)const;
	ArrayofPoints operator-(const ArrayofPoints &c2)const;
	friend ostream & operator<<(ostream &out, const ArrayofPoints &a)
	{
		int i;
		for (i = 0; i < a.size; i++)
			cout << "(" << a.points[i].getx() << "," << a.points[i].gety() << ")" << endl;
		return out;
	}
	ArrayofPoints operator=(const ArrayofPoints &r)
	{
		if (&r != this)
		{
			if (size != r.size)
			{
				delete[]points;
				size = r.size;
				points = new Point[size];
			}
			for (int i = 0; i < size; i++)
				points[i] = r.points[i];
		}
		return *this;
	}
	void print(int i)const
	{
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
private:
	Point *points;
	int size;
};
ArrayofPoints ArrayofPoints::operator+(const ArrayofPoints &c2)const
{
	ArrayofPoints a1(size);
	for (int j = 0; j < size; j++)
	{
		a1.points[j].x = points[j].x + c2.points[j].x;
		a1.points[j].y = points[j].y + c2.points[j].y;
	}
	return a1;
}
ArrayofPoints ArrayofPoints::operator-(const ArrayofPoints &c2)const
{
	ArrayofPoints a1(size);
	for (int j = 0; j < size; j++)
	{
		a1.points[j].x = points[j].x - c2.points[j].x;
		a1.points[j].y = points[j].y - c2.points[j].y;
	}
	return a1;
}
int main()
{
	int num, i, a1, a2, b1, b2;
	cin >> num;
	ArrayofPoints c1(num);
	ArrayofPoints c2(num);
	ArrayofPoints c3(num);
	for (i = 0; i < num; i++)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		c1[i].move(a1, b1);
		c2[i].move(a2, b2);
	}
	c3 = c1 + c2;
	for (i = 0; i < num; i++)
	{
		cout << "c3.element[" << i << "] = c1.element[" << i << "] + c2.element[" << i << "]=";
		cout << c3 << endl;
	}
	c3 = c1 - c2;
	for (i = 0; i < num; i++)
	{
		cout << "c3.element[" << i << "] = c1.element[" << i << "] - c2.element[" << i << "]=";
		cout << c3 << endl;
	}
	return 0;
}
