#include<iostream>
#include<string>
using namespace std;

class vehicle{
public:
	vehicle(){cout << "The vehicle has been constructed!" << endl;}
	vehicle(int max,float wei,float pri):MaxSpeed(max),Weight(wei),Price(pri){
		cout << "The vehicle has been constructed!" << endl;
	}
	vehicle(vehicle&veh){
		MaxSpeed = veh.MaxSpeed;
		Weight = veh.Weight;
		Price = veh.Price;
	}
	virtual void print(){//虚函数
		cout << MaxSpeed << ","<< Weight <<","<<Price<< endl;
	}
	void Run(){cout << "The vehicle is running!" << endl;}
	void Stop(){cout << "The vehicle has stopped!" << endl;}
	~vehicle(){cout << "The vehicle has been deconstructed!" << endl;}
private:
	int MaxSpeed;
	float Weight,Price;
};

class motorcar:virtual public vehicle{
public:
	motorcar(){cout << "The motorcar has been constructed!" << endl;}
	motorcar(int max, float wei, float pri, float len, float hei, float gas) :vehicle(max, wei, pri), Length(len), Height(hei), Gas(gas){
		cout << "The motorcar has been constructed!" << endl;
	}
	motorcar(motorcar&mot);
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
motorcar::motorcar(motorcar&mot):vehicle(mot){
	Length = mot.Length;
	Height = mot.Height;
	Gas = mot.Gas;
}

class bicycle :virtual public vehicle{
public:
	bicycle(){ cout << "The bicycle has been construcated!" << endl; }
	bicycle(int max, float wei, float pri, string mat) :vehicle(max, wei, pri), material(mat){ 
		cout << "The bicycle has been construcated!" << endl;
	}
	bicycle(bicycle&bic){
		material=bic.material;
	}
	void print(){
		vehicle::print();
		cout << material << endl;//照应头文件<string>
	}
	void Run(){ cout << "The bicycle is running!" << endl; }
	void Stop(){ cout << "The bicycle has stopped!" << endl; }
	~bicycle(){ cout << "The bicycle has been deconstructed!" << endl; }
private:
	string material;
};

class motorcycle:public motorcar,public bicycle{
public:
	motorcycle(){cout << "The motorcycle has been constructed!" << endl;}
	motorcycle(int max, float wei, float pri, float len, float hei, float gas, string mat, int pow) :vehicle(max, wei, pri), motorcar(max, wei, pri, len, hei, gas), bicycle(max, wei, pri,mat), Power(pow){
		cout << "The motorcycle has been constructed!" << endl;
	}
	motorcycle(motorcycle&mot){
		Power = mot.Power;
	}
	void print(){
		vehicle::print();
		motorcar::print();
		bicycle::print();
		cout << Power << endl;
	}
	void Run(){cout << "The motorcycle is running!" << endl;}
	void Stop(){cout << "The motorcycle has stopped!" << endl;}
	~motorcycle(){cout << "The motorcycle has been deconstructed!" << endl;}
private:
	int Power;
};

void fun(vehicle *p){
	p->print();
	p->Run();
	p->Stop();
}

int main()
{
	vehicle *p;
	vehicle a(10, 1.10, 1.20);
	motorcar b(11, 1.11, 1.21,  2.1, 2.2, 2.3);
	bicycle c(12, 1.12, 1.22,  "abc");
	motorcycle d(13, 1.13, 1.23,  2.2, 2.3, 2.4,  "def",  3);
	p = &a;
	fun(p);
	p = &b;
	fun(p);
	p = &c;
	fun(p);
	p = &d;
	fun(p);
	return 0;
}