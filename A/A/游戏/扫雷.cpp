#include <iostream>
#include<fstream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include<stdio.h> //ʱ�� //�ļ�
#include <string>
#define random(x)(rand()%x)
using namespace std;
void thunder(int Dif, int Row, int Column, char *USer)
{
	int r, c, alls[22][22], backstage[22][22] = { 0 };
	srand((int)time(0));
	for (r = 1; r <= Row; r++)                                      // ����alls��0~1��1����
	{
		for (c = 1; c <= Column; c++)
		{
			if (random(6)<1) { alls[r][c] = 1; }
			else { alls[r][c] = 0; };
		}
	};
	for (r = 0; r <= Row + 1; r++)                                //���� backstage����ȷ�𰸣�
	{
		for (int c = 0; c <= Column + 1; c++)
		{
			if (alls[r][c] == 1)
			{
				(int)backstage[r][c] = '*';             //��1��Ϊ *  ������
			}
			else
			{
				for (int i = r - 1; i <= r + 1; i++)             //��0��Ϊ���� ��������Χ������
					for (int j = c - 1; j <= c + 1; j++)
					{

						if (alls[i][j] != alls[r][c] && alls[i][j] == 1) { backstage[r][c]++; };
					}
			};  //else ���� 
		};    // for ����
	};          // for ���� 
	cout << "======================*********================================" << endl;
	char surface[22][22];              //����surface(�û�����)
	for (r = 0; r<22; r++)                  //ȫ��Ϊ��
		for (c = 0; c<22; c++)
		{
			surface[r][c] = '0';
		}
	for (r = 1; r <= Row; r++)                 //�м仯 #   �γ�0��Χ#����ʽ  ��ͨ����  #-->(*||���֣� �ĸ���  Ӯ��ʱ��ֹͣѭ����
		for (c = 1; c <= Column; c++)
		{
			surface[r][c] = '#';
		}
	for (r = 1; r <= Row; r++)                      //���  surface   ����  ���ڼ��
	{
		for (c = 1; c <= Column; c++) { cout << "  " << surface[r][c]; };
		cout << endl;
	};
	cout << "�밴��ʽ����" << endl
		<< "ǰ��������Ϊ���꣬���һ�����֡�1����ʾ��λ��Ϊ�ף���0�����ʾ���ǡ�" << endl
		<< "�磺1 3 1  ��ʾһ���������ף�2 4 0 ��ʾ�������в�����" << endl
		<< "��ʾ����������Χ�׶���ɨ��ʱ�����ٴΰ�Ҫ�������λ�ã��ɵõ���Χ���֡�" << endl;
	long  i = 10000000L;         //����ʱ�俪ʼ
	clock_t start, finish;
	double duration;
	start = clock();
	while (i--);                //����ʱ�俪ʼ
	int num = Row*Column;        //����#�Ÿ���
	while (num != 0)              //���� �Ƿ��������λ��
	{
		int x, y, judge;
		cin >> x >> y >> judge;
		if (alls[x][y] != judge)
		{
			cout << "you lose!!!" << endl;
			cout << "The answer is:" << endl;
			for (r = 1; r <= Row; r++)                    //����   ���backstage  ��ʾ��ȷ��
			{
				for (int c = 1; c <= Column; c++)
				{
					cout << "  " << (char)(backstage[r][c] == 42 ? backstage[r][c] : backstage[r][c] + '0');  //���backstage
				}
				cout << endl;
			}
			break;
		}
		else
		{
			if (alls[x][y] == 1) { if (surface[x][y] == '#') { num--; }surface[x][y] = '@'; }      // �� �ж���ȷ ��ʾ��@��������#��
			else
			{
				if (backstage[x][y] != 0)                                                  //  ���� �ж���ȷ ��ʾ����
				{
					if (surface[x][y] == '#') { num--; surface[x][y] = backstage[x][y] + '0'; }  //   ����#��
					else
					{
						int lei_num = 0;
						for (int i = x - 1; i <= x + 1; i++)                                         //�� ������Χ �׵ĸ���                                     
							for (int j = y - 1; j <= y + 1; j++)
							{
								if (surface[i][j] == '@')
									lei_num++;
							}
						if (backstage[x][y] == lei_num)                                   // ��������Χ���Ƿ�ȫ��ɨ��  ��ʾ ��ʾ������Χ
						{
							for (int i = x - 1; i <= x + 1; i++)
								for (int j = y - 1; j <= y + 1; j++)
									if (surface[i][j] == '#')                         //����#��
									{
										surface[i][j] = backstage[i][j] + '0';
										num--;
									}
						}
					}
				}
				else                                                                   // ����Ϊ��ʱ   ��ʾ����Χ����
				{
					if (surface[x][y] == '#') { num--; };                                    //����#��
					surface[x][y] = backstage[x][y] + '0';
					for (int i = x - 1; i <= x + 1; i++)                                          //  ��ʾ����Χ������
						for (int j = y - 1; j <= y + 1; j++)
							if (surface[i][j] == '#')                                     // ���� ��ѭ��
							{
								surface[i][j] = backstage[i][j] + '0';
								num--;  				                               //����#��
							}
					for (int k = 0; k<20; k++)                                       //���20���� ���������ϵ��㣩
					{
						for (int R = 1; R <= Row; R++)                                //���������
							for (int C = 1; C <= Column; C++)                          //�ٴ���ʾ����Χ������
							{
								if (surface[R][C] == '0')
								{
									for (int i = R - 1; i <= R + 1; i++)
										for (int j = C - 1; j <= C + 1; j++)
										{
											if (surface[i][j] == '#')                         // ���� ��ѭ�� ����#��
											{
												surface[i][j] = backstage[i][j] + '0';
												num--;
											}
										}
								}
							} //ƥ��for �� 
					} //ƥ�� for ��
				}//ƥ��else
			}//ƥ��else
		}//ƥ��els
		cout << endl;
		cout << "======================*********================================" << endl;
		for (r = 1; r <= Row; r++)                                                                          //������棨���޸ģ�
		{
			for (c = 1; c <= Column; c++) { cout << "  " << surface[r][c]; };
			cout << endl;
		};
	}                                                                                               //ƥ��while
	finish = clock();                                                                                //����ʱ�����
	duration = (double)(finish - start) / CLOCKS_PER_SEC;                                                //ʱ�����
	if (num == 0)                                                                                      //����
	{
		cout << "              You win!  Congratulations!!                 " << endl;
		cout << "                Your time is: " << duration << endl;
		if (Dif == 1)                                                                            //��ȡ ��ɨ�� �Ĵ洢�ļ�
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("ɨ�� ��.txt");
			for (i = 0; i<5; i++)                                                                    //�ļ�����Ϣ���뵽������
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //���������Ϣ
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //ð������
			{
				for (i = 0; i<5 - j; i++)
				{
					if (times[i]>times[i + 1])
					{
						t1 = times[i];
						times[i] = times[i + 1];
						times[i + 1] = t1;
						t2 = name[i];
						name[i] = name[i + 1];
						name[i + 1] = t2;
					}
				}
			}
			ofstream outf("ɨ�� ��.txt");
			for (i = 0; i<5; i++)                                                                   //��ǰ���������Ϣ�洢���ļ���
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
		if (Dif == 2)                                                                            //��ȡ һ��ɨ�� �Ĵ洢�ļ�
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("ɨ�� һ��.txt");
			for (i = 0; i<5; i++)                                                                    //�ļ�����Ϣ���뵽������
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //���������Ϣ
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //ð������
			{
				for (i = 0; i<5 - j; i++)
				{
					if (times[i]>times[i + 1])
					{
						t1 = times[i];
						times[i] = times[i + 1];
						times[i + 1] = t1;
						t2 = name[i];
						name[i] = name[i + 1];
						name[i + 1] = t2;
					}
				}
			}
			ofstream outf("ɨ�� һ��.txt");
			for (i = 0; i<5; i++)                                                                   //��ǰ���������Ϣ�洢���ļ��� �����
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
		if (Dif == 3)                                                                            //��ȡ ����ɨ�� �Ĵ洢�ļ�
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("ɨ�� ����.txt");
			for (i = 0; i<5; i++)                                                                    //�ļ�����Ϣ���뵽������
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //���������Ϣ
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //ð������
			{
				for (i = 0; i<5 - j; i++)
				{
					if (times[i]>times[i + 1])
					{
						t1 = times[i];
						times[i] = times[i + 1];
						times[i + 1] = t1;
						t2 = name[i];
						name[i] = name[i + 1];
						name[i + 1] = t2;
					}
				}
			}
			ofstream outf("ɨ�� ����.txt");
			for (i = 0; i<5; i++)                                                                   //��ǰ���������Ϣ�洢���ļ���
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
	}
}
void scale(int dif, char *User)    //ѡ���Ѷ�
{
	int row, column;
	if (dif == 1) { row = 3; column = 3; }
	if (dif == 2) { row = 7; column = 7; }
	if (dif == 3) { row = 10; column = 10; }
	cout << "The scale is: " << row << "*" << column << endl;
	thunder(dif, row, column, User);
};
int main()
{
	int Continue = 1;
	int difficulty;
	char user[10];
	cout << "                       Welcom to the game!                  " << endl
		<< "                         �������û���!                      " << endl;
	cin >> user;
	while (Continue == 1)
	{
		cout << "=======================*******************=======================" << endl
			<< "                          ��ѡ���Ѷȣ�                        " << endl
			<< "                          �򵥡���1                           " << endl
			<< "                          һ�㡪��2                           " << endl
			<< "                          ���ѡ���3                           " << endl;
		cin >> difficulty;
		scale(difficulty, user);
		cout << "������Ϸ����1     ������Ϸ����0" << endl;
		cin >> Continue;
	}
	return 0;
}