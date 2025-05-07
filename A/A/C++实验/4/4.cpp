//4.1
#include<iostream>
using namespace std;
class CPU
{
public:
	CPU(int xx = 0)
	{
		x = xx;
	}
	CPU(CPU&p)
	{
		x = p.x;
		cout << "正在复制构造CPU对象" << endl;
	}
	int print()
	{
		return x;
	}
	~CPU()
	{
		cout << "正在删除CPU对象！" << endl;
	}
private:
	int x;
};
void fun1(CPU p)
{
	cout << p.print() << endl;
}
CPU fun2()
{
	CPU a(1);
	return a;
}
int main()
{
	CPU a(4);
	CPU b = a;
	cout << b.print() << endl;
	fun1(b);
	b = fun2();
	cout << b.print() << endl;
	return 0;
}
//4.2
#include<iostream>
using namespace std;

enum CPU_Rank{ i3 = 2, i5, i7 };

class CPU
{
public:
	CPU(){}
	CPU(CPU_Rank i, int f, float v);
	CPU(CPU&p);
	void GetRank();
	void GetFrequency();
	void GetVoltage();
	void Print();
	void SetRank(CPU_Rank i);
	void SetFrequency(int f);
	void SetVoltage(float v);
	void Run();
	void Stop();
	~CPU()
	{
		cout << "正在删除CPU对象!" << endl;
	}
private:
	CPU_Rank Rank;
	int frequency;
	float voltage;
};
CPU::CPU(CPU_Rank i, int f, float v)
{
	Rank = i;
	voltage = v;
	frequency = f;
	cout << "正在构造对象!" << endl;
}
CPU::CPU(CPU &p)
{
	Rank = p.Rank;
	frequency = p.frequency;
	voltage = p.voltage;
	cout << "正在复制构造CPU对象" << endl;
}
void CPU::GetRank()
{
	cout << Rank << endl;
}
void CPU::GetFrequency()
{
	cout << frequency << endl;
}
void CPU::GetVoltage()
{
	cout << voltage << endl;
}
void CPU::SetRank(CPU_Rank i)
{
	Rank = i;
}
void CPU::SetFrequency(int f)
{
	frequency = f;
}
void CPU::SetVoltage(float v)
{
	voltage = v;
}
void CPU::Print()
{
	GetRank();
	GetFrequency();
	GetVoltage();
}
void CPU::Run()
{
	cout << "CPU开始运行!" << endl;
}
void CPU::Stop()
{
	cout << "CPU停止运行!" << endl;
}

enum RAM_Rank{ DDR = 1, DDR2, DDR3 };

class RAM
{
public:
	RAM(){}
	RAM(RAM_Rank d, int m, float f);
	RAM(RAM&p);
	void GetRank();
	void GetFrequency();
	void GetMemory();
	void SetRank(RAM_Rank d);
	void SetFrequency(float f);
	void SetMemory(int m);
	void Print();
	void Run();
	void Stop();
	~RAM()
	{
		cout << "正在删除RAM对象!" << endl;
	}
private:
	RAM_Rank Rank;
	int memory;
	float frequency;
};
RAM::RAM(RAM_Rank d, int m, float f)
{
	Rank = d;
	memory = m;
	frequency = f;
}
RAM::RAM(RAM&p)
{
	Rank = p.Rank;
	memory = p.memory;
	frequency = p.frequency;
	cout << "正在复制构造RAM对象" << endl;
}
void RAM::GetRank()
{
	cout << Rank << endl;
}
void RAM::GetFrequency()
{
	cout << frequency << endl;
}
void RAM::GetMemory()
{
	cout << memory << endl;
}
void RAM::SetRank(RAM_Rank d)
{
	Rank = d;
}
void RAM::SetFrequency(float f)
{
	frequency = f;
}
void RAM::SetMemory(int m)
{
	memory = m;
}
void RAM::Print()
{
	GetRank();
	GetFrequency();
	GetMemory();
}
void RAM::Run()
{
	cout << "RAM开始运行！" << endl;
}
void RAM::Stop()
{
	cout << "RAM停止运行！" << endl;
}

class COMPUTER
{
public:
	COMPUTER();
	COMPUTER(CPU xc, RAM xr);
	COMPUTER(COMPUTER&p);
	void SetComputer();
	void GetComputer();
	void Print();
	void Run();
	void Stop();
	~COMPUTER()
	{
		cout << "正在删除COMPUTER对象!" << endl;
	}
private:
	CPU cpu;
	RAM ram;
	string brand;
	int price;
};
COMPUTER::COMPUTER()
{
	cout << "默认构造了一个COMPUTER!" << endl;
}
COMPUTER::COMPUTER(CPU xc, RAM xr) :cpu(xc), ram(xr)
{
	cout << "初始化构造了一个COMPUTER!" << endl;
}
COMPUTER::COMPUTER(COMPUTER&p) : cpu(p.cpu), ram(p.ram)
{
	cout << "调用COMPUTER的复制构造函数!" << endl;
}
void COMPUTER::SetComputer()
{
	cpu.SetRank(i5);
	cpu.SetFrequency(2400);
	cpu.SetVoltage(2.8);
	ram.SetRank(DDR3);
	ram.SetMemory(8);
	ram.SetFrequency(2.4);
}
void COMPUTER::GetComputer()
{
	cpu.GetRank();
	cpu.GetFrequency();
	cpu.GetVoltage();
	ram.GetRank();
	ram.GetFrequency();
	ram.GetMemory();
}
void COMPUTER::Print()
{
	cpu.Print();
	ram.Print();
}
void COMPUTER::Run()
{
	cpu.Run();
	ram.Run();
	cout << "COMPUTER开始运行!" << endl;
}
void COMPUTER::Stop()
{
	cpu.Stop();
	ram.Stop();
	cout << "COMPUTER停止运行!" << endl;
}
int main()
{
	CPU cpu(i5, 2400, 2.8);
	RAM ram(DDR3, 8, 2.4);
	COMPUTER computer1, computer2;
	computer1.SetComputer();
	computer1.GetComputer();
	computer1.Print();
	computer1.Run();
	computer1.Stop();
	computer2 = computer1;
	computer2.GetComputer();
	return 0;
}