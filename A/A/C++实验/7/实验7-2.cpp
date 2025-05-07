#include<iostream>
#include<cassert>
using namespace std;
enum CPU_Rank{ i3= 1, i5, i7 };
class CPU
{
private:
	CPU_Rank CPURank;
	int frequency;
	float voltage;
public:
	CPU()
	{
		cout << "无参正在构造对象" << endl;
	}
	CPU(CPU_Rank newr, int newf, float newv);
	CPU(CPU &cpu);
	void SetRank(CPU_Rank r);
	void SetFrequency(int f);
	void SetVoltage(float v);
	void Run();
	void print();
	void GetRank();
	void GetFrequency();
	void GetVoltage();
	void Stop();
	~CPU()
	{
		cout << "正在删除CPU对象!" << endl;
	};
};
CPU::CPU(CPU_Rank newr, int newf, float newv)
{
	CPURank = newr;
	frequency = newf;
	voltage = newv;
	cout << "正在构造对象" << endl;
}
CPU::CPU(CPU &cpu)
{
	CPURank = cpu.CPURank;
	frequency = cpu.frequency;
	voltage = cpu.voltage;
	cout << "正在复制构造CPU对象" << endl;
}
void CPU::SetRank(CPU_Rank r)
{
	CPURank=r;
}
void CPU::SetFrequency(int f)
{
	frequency = f;
}
void CPU::SetVoltage(float v)
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
void CPU::GetRank()
{
	cout << CPURank << endl;
}
void CPU::GetFrequency()
{
	cout << frequency << endl;
}
void CPU::GetVoltage()
{
	cout << voltage << endl;
}
void CPU::Stop()
{
	cout << "CPU停止运行!" << endl;
}
class ArrayOfCpu{
public:
	ArrayOfCpu(int size) :size(size){
		cpuArray = new CPU[size];
	}
	~ArrayOfCpu(){
		cout << "正在删除对象！....."<< endl;
		delete[] cpuArray;
	}
	CPU&element(int index){
		assert(index>= 0 && index < size);
		return cpuArray[index];
	}
private:
	CPU* cpuArray;
	int size;
};
int main()
{
	ArrayOfCpu cpuArray1(2);
	cpuArray1.element(0).SetRank(i3);
	cpuArray1.element(0).SetFrequency(2400);
	cpuArray1.element(0).SetVoltage(2.8);
	cpuArray1.element(0).Run();
	cpuArray1.element(0).print();
	cpuArray1.element(0).GetRank();
	cpuArray1.element(0).GetFrequency();
	cpuArray1.element(0).GetVoltage();
	cpuArray1.element(1).SetRank(i5);
	cpuArray1.element(1).SetFrequency(1200);
	cpuArray1.element(1).SetVoltage(1.4);
	cpuArray1.element(1).Run();
	cpuArray1.element(1).print();
	cpuArray1.element(1).GetRank();
	cpuArray1.element(1).GetFrequency();
	cpuArray1.element(1).GetVoltage();
	return 0;
}