#include<iostream>
using namespace std;
class vehicle
{
public:
	vehicle() :maxspeed(0), weight(0)
	{
		cout << "The vehicle has been constructed" << endl;
	}
	vehicle(int newmaxspeed, float newweight)
	{
		maxspeed = newmaxspeed;
		weight = newweight;
		cout << "AAA The vehicle has been constructed" << endl;
	}
	vehicle(vehicle &v)
	{
		maxspeed = v.maxspeed;
		weight = v.weight;
		cout << "The vehicle has been copy" << endl;
	}
	~vehicle()
	{
		cout << "The vehicle has been deconstructed" << endl;
	}
	virtual void print()const = 0;
	virtual void Run()const = 0;
	virtual void Stop()const = 0;
private:
	int maxspeed;
	float weight;
};
class motorcar :public vehicle
{
public:
	motorcar() :length(0), weight(0), height(0), gas(0)
	{
		cout << "The motorcar has been constructed" << endl;
	}
	motorcar(int m, float w, float newlength, float newweight, float newheight, float newgas);
	motorcar(motorcar &m);
	~motorcar()
	{
		cout << "The motorcar has been deconstructed" << endl;
	}
	void print()const
	{
		cout << "length:" << length << "weight:" << weight << "height:" << height << "gas:" << gas << endl;
	}
	void Run()const
	{
		cout << "The motorcar is running!" << endl;
	}
	void Stop()const
	{
		cout << "The motorcar has stopped!" << endl;
	}
private:
	float length, weight, height, gas;
};
motorcar::motorcar(int m, float w, float newlength, float newweight, float newheight, float newgas) :vehicle(m, w)
{

	length = newlength;
	weight = newweight;
	height = newheight;
	gas = newgas;
	cout << "AAA The motorcar has been constructed" << endl;
}
motorcar::motorcar(motorcar &m) :vehicle(m)
{

	length = m.length;
	weight = m.weight;
	height = m.height;
	gas = m.gas;
	cout << "The motorcar has been copy" << endl;
}
class motorcycle :public motorcar
{
public:
	motorcycle() :power(0)
	{
		cout << "The motorcycle has been constructed" << endl;
	}
	motorcycle(int m, float w, float newlength, float newweight, float newheight, float newgas, int newpower) :motorcar(m, w, newlength, newweight, newheight, newgas)
	{

		power = newpower;
		cout << "AAA The motorcycle has been constructed" << endl;
	}
	motorcycle(motorcycle &p) :motorcar(p)
	{

		power = p.power;
		cout << "The motorcycle has been copy" << endl;
	}
	~motorcycle()
	{
		cout << "The motorcycle has been deconstructed" << endl;
	}
	void print()const
	{
		cout << "power:" << power << endl;
	}
	void Run()const
	{
		cout << "The motorcycle is running!" << endl;
	}
	void Stop()const
	{
		cout << "The motorcycle has stopped!" << endl;
	}
private:
	int power;
};
void fun(vehicle *ptr)
{
	ptr->print();
	ptr->Run();
	ptr->Stop();
}
int main()
{
	motorcar motor(2, 6.6, 1.2, 2.3, 3.4, 5.6);
	motorcycle motorc(2, 6.6, 1.2, 2.3, 3.4, 5.6, 1);
	fun(&motor);
	fun(&motorc);
	return 0;
}