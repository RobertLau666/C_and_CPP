#include <iostream>
#include<fstream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include<stdio.h> //时间 //文件
#include <string>
#define random(x)(rand()%x)
using namespace std;
void thunder(int Dif, int Row, int Column, char *USer)
{
	int r, c, alls[22][22], backstage[22][22] = { 0 };
	srand((int)time(0));
	for (r = 1; r <= Row; r++)                                      // 生成alls（0~1）1是雷
	{
		for (c = 1; c <= Column; c++)
		{
			if (random(6)<1) { alls[r][c] = 1; }
			else { alls[r][c] = 0; };
		}
	};
	for (r = 0; r <= Row + 1; r++)                                //生成 backstage（正确答案）
	{
		for (int c = 0; c <= Column + 1; c++)
		{
			if (alls[r][c] == 1)
			{
				(int)backstage[r][c] = '*';             //将1变为 *  代表雷
			}
			else
			{
				for (int i = r - 1; i <= r + 1; i++)             //将0变为数字 （代表周围雷数）
					for (int j = c - 1; j <= c + 1; j++)
					{

						if (alls[i][j] != alls[r][c] && alls[i][j] == 1) { backstage[r][c]++; };
					}
			};  //else 结束 
		};    // for 结束
	};          // for 结束 
	cout << "======================*********================================" << endl;
	char surface[22][22];              //生成surface(用户界面)
	for (r = 0; r<22; r++)                  //全部为零
		for (c = 0; c<22; c++)
		{
			surface[r][c] = '0';
		}
	for (r = 1; r <= Row; r++)                 //中间化 #   形成0包围#的形式  （通过数  #-->(*||数字） 的个数  赢的时候停止循环）
		for (c = 1; c <= Column; c++)
		{
			surface[r][c] = '#';
		}
	for (r = 1; r <= Row; r++)                      //输出  surface   界面  便于检查
	{
		for (c = 1; c <= Column; c++) { cout << "  " << surface[r][c]; };
		cout << endl;
	};
	cout << "请按格式输入" << endl
		<< "前两个数字为坐标，最后一个数字“1”表示此位置为雷，“0”则表示不是。" << endl
		<< "如：1 3 1  表示一行三列是雷；2 4 0 表示二行四列不是雷" << endl
		<< "提示：当数字周围雷都被扫出时，可再次按要求输入此位置，可得到周围数字。" << endl;
	long  i = 10000000L;         //计算时间开始
	clock_t start, finish;
	double duration;
	start = clock();
	while (i--);                //计算时间开始
	int num = Row*Column;        //计算#号个数
	while (num != 0)              //控制 是否点完所有位置
	{
		int x, y, judge;
		cin >> x >> y >> judge;
		if (alls[x][y] != judge)
		{
			cout << "you lose!!!" << endl;
			cout << "The answer is:" << endl;
			for (r = 1; r <= Row; r++)                    //输了   输出backstage  显示正确答案
			{
				for (int c = 1; c <= Column; c++)
				{
					cout << "  " << (char)(backstage[r][c] == 42 ? backstage[r][c] : backstage[r][c] + '0');  //输出backstage
				}
				cout << endl;
			}
			break;
		}
		else
		{
			if (alls[x][y] == 1) { if (surface[x][y] == '#') { num--; }surface[x][y] = '@'; }      // 雷 判断正确 显示“@”；数“#”
			else
			{
				if (backstage[x][y] != 0)                                                  //  数字 判断正确 显示数字
				{
					if (surface[x][y] == '#') { num--; surface[x][y] = backstage[x][y] + '0'; }  //   数“#”
					else
					{
						int lei_num = 0;
						for (int i = x - 1; i <= x + 1; i++)                                         //数 数字周围 雷的个数                                     
							for (int j = y - 1; j <= y + 1; j++)
							{
								if (surface[i][j] == '@')
									lei_num++;
							}
						if (backstage[x][y] == lei_num)                                   // 看数字周围雷是否全部扫出  提示 显示数字周围
						{
							for (int i = x - 1; i <= x + 1; i++)
								for (int j = y - 1; j <= y + 1; j++)
									if (surface[i][j] == '#')                         //数“#”
									{
										surface[i][j] = backstage[i][j] + '0';
										num--;
									}
						}
					}
				}
				else                                                                   // 数字为零时   显示零周围的零
				{
					if (surface[x][y] == '#') { num--; };                                    //数“#”
					surface[x][y] = backstage[x][y] + '0';
					for (int i = x - 1; i <= x + 1; i++)                                          //  显示零周围的数字
						for (int j = y - 1; j <= y + 1; j++)
							if (surface[i][j] == '#')                                     // 避免 死循环
							{
								surface[i][j] = backstage[i][j] + '0';
								num--;  				                               //数“#”
							}
					for (int k = 0; k<20; k++)                                       //最多20层零 （点出最边上的零）
					{
						for (int R = 1; R <= Row; R++)                                //检查所有零
							for (int C = 1; C <= Column; C++)                          //再次显示零周围的数字
							{
								if (surface[R][C] == '0')
								{
									for (int i = R - 1; i <= R + 1; i++)
										for (int j = C - 1; j <= C + 1; j++)
										{
											if (surface[i][j] == '#')                         // 避免 死循环 数“#”
											{
												surface[i][j] = backstage[i][j] + '0';
												num--;
											}
										}
								}
							} //匹配for 内 
					} //匹配 for 外
				}//匹配else
			}//匹配else
		}//匹配els
		cout << endl;
		cout << "======================*********================================" << endl;
		for (r = 1; r <= Row; r++)                                                                          //输出界面（已修改）
		{
			for (c = 1; c <= Column; c++) { cout << "  " << surface[r][c]; };
			cout << endl;
		};
	}                                                                                               //匹配while
	finish = clock();                                                                                //计算时间结束
	duration = (double)(finish - start) / CLOCKS_PER_SEC;                                                //时间变量
	if (num == 0)                                                                                      //所有
	{
		cout << "              You win!  Congratulations!!                 " << endl;
		cout << "                Your time is: " << duration << endl;
		if (Dif == 1)                                                                            //读取 简单扫雷 的存储文件
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("扫雷 简单.txt");
			for (i = 0; i<5; i++)                                                                    //文件中信息导入到数组里
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //本轮玩家信息
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //冒泡排序法
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
			ofstream outf("扫雷 简单.txt");
			for (i = 0; i<5; i++)                                                                   //将前五名玩家信息存储到文件中
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
		if (Dif == 2)                                                                            //读取 一般扫雷 的存储文件
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("扫雷 一般.txt");
			for (i = 0; i<5; i++)                                                                    //文件中信息导入到数组里
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //本轮玩家信息
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //冒泡排序法
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
			ofstream outf("扫雷 一般.txt");
			for (i = 0; i<5; i++)                                                                   //将前五名玩家信息存储到文件中 并输出
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
		if (Dif == 3)                                                                            //读取 困难扫雷 的存储文件
		{
			string Name;
			string name[6];
			double Time, rang;
			double times[6];
			int i = 0;
			ifstream inf("扫雷 困难.txt");
			for (i = 0; i<5; i++)                                                                    //文件中信息导入到数组里
			{
				inf >> Name; inf >> rang >> Time;
				name[i] = Name;
				times[i] = Time;
			}
			inf.close();
			name[5] = USer;                                                                   //本轮玩家信息
			times[5] = duration;
			double t1 = 0;
			string t2;
			for (int j = 0; j<5; j++)                                                               //冒泡排序法
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
			ofstream outf("扫雷 困难.txt");
			for (i = 0; i<5; i++)                                                                   //将前五名玩家信息存储到文件中
			{
				cout << name[i] << "    " << i + 1 << "   " << times[i] << endl;
				outf << name[i] << "    " << i + 1 << "   " << times[i] << endl;
			}
			outf.close();
		}
	}
}
void scale(int dif, char *User)    //选择难度
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
		<< "                         请输入用户名!                      " << endl;
	cin >> user;
	while (Continue == 1)
	{
		cout << "=======================*******************=======================" << endl
			<< "                          请选择难度！                        " << endl
			<< "                          简单——1                           " << endl
			<< "                          一般——2                           " << endl
			<< "                          困难——3                           " << endl;
		cin >> difficulty;
		scale(difficulty, user);
		cout << "继续游戏——1     结束游戏——0" << endl;
		cin >> Continue;
	}
	return 0;
}