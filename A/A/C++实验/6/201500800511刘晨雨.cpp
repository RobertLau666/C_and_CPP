#include<iostream>
using namespace std;
enum CPU_Rank{ i3 = 2, i5, i7 };
enum RAM_Rank{ DDR, DDR2, DDR3 };
class CPU
{
private:
	CPU_Rank CPURank;
	int frequency;
	double voltage;
public:
	CPU(){
		cout << "正在构造CPU对象!" << endl;
	}
	CPU(CPU_Rank CPURank, int newf, double newv);
	CPU(const CPU &cpu);
	void SetRank(CPU_Rank CPURank);
	void SetFrequency(int f);
	void SetVoltage(double v);
	void Run();
	void print();
	void print()const;
	void GetRank();
	void GetFrequency();
	void GetVoltage();
	void GetRank()const;
	void GetFrequency()const;
	void GetVoltage()const;
	void Stop();
	~CPU()
	{
		cout << "正在删除CPU对象!" << endl;
	}
	friend class COMPUTER;
};
CPU::CPU(CPU_Rank CPURank, int newf, double newv)
{
	CPURank = i5;
	frequency = newf;
	voltage = newv;
	cout << "正在构造CPU对象!" << endl;
}
CPU::CPU(const CPU &cpu)
{
	CPURank = cpu.CPURank;
	frequency = cpu.frequency;
	voltage = cpu.voltage;
	cout << "正在复制构造CPU对象!" << endl;
}
void CPU::SetRank(CPU_Rank CPURank)
{
	CPURank = i5;
}
void CPU::SetFrequency(int f)
{
	frequency = f;
}
void CPU::SetVoltage(double v)
{
	voltage = v;
}
void CPU::Run()
{
	cout << "CPU开始运行!" << endl;
}
void CPU::print()
{
	GetRank();
	GetFrequency();
	GetVoltage();
}
void CPU::print()const
{
	GetRank();
	GetFrequency();
	GetVoltage();
}
void CPU::GetRank()
{
	cout << i5 << endl;
}
void CPU::GetFrequency()
{
	cout << frequency << endl;
}
void CPU::GetVoltage()
{
	cout << voltage << endl;
}
void CPU::GetRank()const
{
	cout << i5 << endl;
}
void CPU::GetFrequency()const
{
	cout << frequency << endl;
}
void CPU::GetVoltage()const
{
	cout << voltage << endl;
}
void CPU::Stop()
{
	cout << "CPU停止运行!" << endl;
}

class RAM
{
private:
	RAM_Rank RAMRank;
	int memory;
	double frequency;
public:
	RAM(){
		cout << "正在构造RAM对象!" << endl;
	}
	RAM(RAM_Rank RAMRank, int newm, double newf);
	RAM(const RAM &ram);
	void SetRank(RAM_Rank RAMRank);
	void Setmemory(int m);
	void SetFrequency(double f);
	void Run();
	void print();
	void print()const;
	void GetRank();
	void Getmemory();
	void GetFrequency();
	void GetRank()const;
	void Getmemory()const;
	void GetFrequency()const;
	void Stop();
	~RAM()
	{
		cout << "正在删除RAM对象!" << endl;
	};
	friend class COMPUTER;
};
RAM::RAM(RAM_Rank RAMRank, int newm, double newf)
{
	RAMRank = DDR3;
	memory = newm;
	frequency = newf;
	cout << "正在构造RAM对象!" << endl;
}
RAM::RAM(const RAM &ram)
{
	RAMRank = ram.RAMRank;
	memory = ram.memory;
	frequency = ram.frequency;
	cout << "正在复制构造RAM对象!" << endl;
}
void RAM::SetRank(RAM_Rank RAMRank)
{
	RAMRank = DDR3;
}
void RAM::SetFrequency(double f)
{
	frequency = f;
}
void RAM::Setmemory(int v)
{
	memory = v;
}
void RAM::Run()
{
	cout << "RAM开始运行!" << endl;
}
void RAM::print()
{
	GetRank();
	Getmemory();
	GetFrequency();
}
void RAM::print()const
{
	GetRank();
	Getmemory();
	GetFrequency();
}
void RAM::GetRank()
{
	cout << DDR3 << endl;
}
void RAM::Getmemory()
{
	cout << memory << endl;
}
void RAM::GetFrequency()
{
	cout << frequency << endl;
}
void RAM::GetRank()const
{
	cout << DDR3 << endl;
}
void RAM::Getmemory()const
{
	cout << memory << endl;
}
void RAM::GetFrequency()const
{
	cout << frequency << endl;
}
void RAM::Stop()
{
	cout << "RAM停止运行!" << endl;
}

class COMPUTER{
public:
	COMPUTER(){                                   
		cout << "正在构造COMPUTER对象!" << endl;
	}
	COMPUTER(CPU cc, RAM rr);                    
	COMPUTER(const COMPUTER&p);
	static void Showcount(){
		cout << "count:" << count << endl;
	}
	void Modifycpu(CPU c);
	void Modifyram(RAM r);
	void Getcomputer()const;
	void Print()const;
	void Setprice(int s);
	void Setprice(int s)const;
	void Getprice();
	void Getprice()const;
	~COMPUTER()
	{
		cout << "正在删除COMPUTER对象!" << endl;
		count--;
	};
private:
	CPU cpu1;
	RAM ram1;
	const CPU cpu2;
	const RAM ram2;
	static int count;
	int price;
};
int COMPUTER::count = 0;
COMPUTER::COMPUTER(const CPU cc,const RAM rr):cpu2(cc),ram2(rr){
	count++;
	cout << "正在构造COMPUTER对象!" << endl;
}
COMPUTER::COMPUTER(const COMPUTER&p):cpu2(p.cpu2), ram2(p.ram2) {
	cpu1= p.cpu1;
	ram1= p.ram1;
	count++;
	cout << "正在复制构造COMPUTER对象!" << endl;
}
void COMPUTER::Modifycpu(CPU c){
	c.CPURank=i3;
	c.frequency=4800;
	c.voltage=5.6;
}
void COMPUTER::Modifyram(RAM r){
	r.RAMRank=DDR;
	r.memory=16;
	r.frequency=4.8;
}
void COMPUTER::Getcomputer()const{
	cpu2.print();
	ram2.print();
}
void COMPUTER::Setprice(int s = 0){
	price = s;
}
void COMPUTER::Setprice(int s = 0)const{};
void COMPUTER::Getprice(){
	cout << price << endl;
}
void COMPUTER::Getprice()const{
	cout << price << endl;
}

int main()
{
	COMPUTER::Showcount();
	CPU xcpu(i5,2400,2.8);
	RAM xram(DDR3,8,2.4);
	COMPUTER computer1(xcpu,xram);
	COMPUTER::Showcount();
	computer1.Modifycpu(xcpu);
	computer1.Modifyram(xram);
	computer1.Getcomputer();
	const CPU ycpu(i3,1200,1.4);
	const RAM yram(DDR,4,1.2);
	const COMPUTER computer2(ycpu,yram);
	COMPUTER::Showcount();
	computer2.Getcomputer();
	
	COMPUTER computer3=computer2;
	COMPUTER::Showcount();
	computer3.Getcomputer();
	computer3.Setprice(40000000);
	computer3.Getprice();
	return 0;
}