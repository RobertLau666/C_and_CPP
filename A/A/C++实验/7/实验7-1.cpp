#include<iostream>
using namespace std;
enum CPU_Rank{ i3 = 2, i5, i7 };
class CPU
{
private:
	CPU_Rank CPURank;
	int frequency;
	float voltage;
public:
	CPU(){
		cout << "�޲ε����ڹ������"<< endl;
	}
	CPU(CPU_Rank CPURank, int newf, float newv);
	CPU(CPU &cpu);
	void SetRank(CPU_Rank CPURank);
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
		cout << "����ɾ��RAM����!" << endl;
	};
};
CPU::CPU(CPU_Rank CPURank, int newf, float newv)
{
	CPURank = i5;
	frequency = newf;
	voltage = newv;
	cout << "���ڹ������" << endl;
}
CPU::CPU(CPU &cpu)
{
	CPURank = cpu.CPURank;
	frequency = cpu.frequency;
	voltage = cpu.voltage;
	cout << "���ڸ��ƹ���CPU����" << endl;
}
void CPU::SetRank(CPU_Rank CPURank)
{
	CPURank = i5;
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
	cout << "CPU��ʼ����!" << endl;
}
void CPU::print()
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
void CPU::Stop()
{
	cout << "CPUֹͣ����!" << endl;
}
int main()
{
	CPU*p = new CPU[2];
	p[0].SetRank(i3);
	p[0].SetFrequency(2400);
	p[0].SetVoltage(2.8);
	p[1].SetRank(i5);
	p[1].SetFrequency(1200);
	p[1].SetVoltage(1.4);
	delete[] p;
	return 0;
}