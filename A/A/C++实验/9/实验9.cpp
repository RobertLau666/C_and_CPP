#include<iostream>
using namespace std;

class vehicle{
public:
	vehicle(){cout << "The vehicle has been constructed!" << endl;}
	vehicle(int max,float wei):MaxSpeed(max),Weight(wei){//两处可任留一处，效果一样，也可均留
		MaxSpeed = max;
		Weight = wei;
		cout << "The vehicle has been constructed!" << endl;
	}
	vehicle(vehicle&veh){
		MaxSpeed = veh.MaxSpeed;
		Weight = veh.Weight;
	}
	void print(){cout << MaxSpeed << "," << Weight << endl;}
	void Run(){cout << "The vehicle is running!" << endl;}
	void Stop(){cout << "The vehicle has stopped!" << endl;}
	~vehicle(){cout << "The vehicle has been deconstructed!" << endl;}
private:
	int MaxSpeed;
	float Weight;
};


class motorcar:public vehicle{
public:
	motorcar(){cout << "The motorcar has been constructed!" << endl;}
	motorcar(int max,float wei,float len, float hei, float gas) :vehicle(max,wei),Length(len), Height(hei), Gas(gas){
		cout << "The motorcar has been constructed!" << endl;
	}
	motorcar(motorcar&mot);//复制构造函数的函数体在外面时的情况
	void print(){
		vehicle::print();
		cout << Length << "," << Height << "," << Gas << endl;
	}
	void Run(){ cout << "The motorcar is running!" << endl;}
	void Stop(){cout << "The motorcar has stopped!" << endl;}
	~motorcar(){ cout << "The motorcar has been deconstructed!" << endl;}
private:
	float Length,Height,Gas;
};
motorcar::motorcar(motorcar&mot) :vehicle(mot){
	Length = mot.Length;
	Height = mot.Height;
	Gas = mot.Gas;
}


class motorcycle:public motorcar{
public:
	motorcycle(){cout << "The motorcycle has been constructed!" << endl;}
	motorcycle(int max, float wei, float len, float hei, float gas, int pow) :motorcar(max, wei, len,  hei, gas), Power(pow){
		cout << "The motorcycle has been constructed!" << endl;
	}
	motorcycle(motorcycle&mot) :motorcar(mot){
		Power = mot.Power;
	}
	void print(){
		motorcar::print();
		cout << Power << endl;
	}
	void Run(){cout << "The motorcycle is running!" << endl;}
	void Stop(){cout << "The motorcycle has stopped!" << endl;}
	~motorcycle(){cout << "The motorcycle has been deconstructed!" << endl;}
private:
	int Power;
};


int main()
{
	vehicle a(1,1.1);
	motorcar b(1,1.1,2.1,2.2,2.3);
	motorcycle c(1, 1.1, 2.1, 2.2, 2.3,3);
	a.Run();
	a.print();
	a.Stop();

	b.Run();
	b.print();
	b.Stop();

	c.Run();
	c.print();
	c.Stop();
	return 0;
}