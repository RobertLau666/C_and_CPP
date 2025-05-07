#include<iostream>
#include<string>
#include<time.h>
using namespace std;

#define NUM 1000
int j = 2;         //����Ϊȫ�ֱ���
int randNum[NUM];//��Ϊrand()������һ����ȱ�ݣ������ڳ����ж�����randNum��������������
				 //��ʹʹ�������Ӻ���srand(),���ڳ�������ʱ��Ƚ϶̣�Ҳ��̫���������ӡ����


class Poker
{
private:
	int poker[53];     //�˿�
	int pokerValue[53]; //�˿˴������ֵ
	string pokerName[53]; //�˿���

	int money;   //���Ǯ��  
	int bet;     //��ҵĶ�ע

	int pokerF[5];   //������е��� F:Farmer   L:Landlord
	int pokerL[5];   //ׯ�����е��� F:Farmer   L:Landlord
	int pokerNumF;   //������е�����
	int pokerNumL;   //ׯ�����е�����
public:
	Poker();           //���캯�������Ƴ�ʼ��
	void initPoker();  //ϴ��,��ÿ����Ϸ��ʼǰ����
	string getPokerF();  //���ַ�������ʽ������ҵ���
	string getPokerL();  //���ַ�������ʽ����ׯ�ҵ���
	int getSumF();       //��������Ƶĵ����������ж��Ƿ񳬹�21��
	int getSumL();       //����ׯ���Ƶĵ���
	void farmerAsk();           //���Ҫ��
	void landlordAsk();         //ׯ��Ҫ��
	void inputBet();            //��������ע
	void newGame();            //��ʼ����Ϸ
	void landlordProcess();        //����Ҳ�Ҫ��ʱ���д���

};

Poker::Poker()
{
	int i;
	poker[0] = 0;
	for (i = 1; i <= 13; i++)    //|
	{                         //|
		poker[i] = i;           //|�ù��캯�����Ƴ�ʼ��
		poker[i + 13] = i;        //|
		poker[i + 26] = i;        //|
		poker[i + 39] = i;        //|
	}//for����

	pokerValue[0] = 0;
	for (i = 1; i <= 52; i++)
	{
		if (poker[i] <= 10)  pokerValue[i] = poker[i];
		else              pokerValue[i] = 10;
	}//for����


	pokerName[0] = "";
	for (i = 0; i<4; i++)
	{
		pokerName[1 + 13 * i] = "A";
		pokerName[2 + 13 * i] = "2";
		pokerName[3 + 13 * i] = "3";
		pokerName[4 + 13 * i] = "4";
		pokerName[5 + 13 * i] = "5";
		pokerName[6 + 13 * i] = "6";
		pokerName[7 + 13 * i] = "7";
		pokerName[8 + 13 * i] = "8";
		pokerName[9 + 13 * i] = "9";
		pokerName[10 + 13 * i] = "10";
		pokerName[11 + 13 * i] = "J";
		pokerName[12 + 13 * i] = "Q";
		pokerName[13 + 13 * i] = "K";
	}//for����

	money = 200;  //��ҿ�ʼ����ϷʱǮ����200
	bet = 0;

	for (i = 0; i<5; i++)
	{
		pokerF[i] = 0;    //|��pokerOfFarmer��ʼ��
		pokerL[i] = 0;    //|��pokerOfLandlord��ʼ��
	}


	pokerNumF = 0;//������е�������ʼ��Ϊ0
	pokerNumL = 0;//ׯ�����е�������ʼ��Ϊ0

	srand((int)time(0));
	for (i = 0; i<NUM; i++)
	{
		randNum[i] = rand() * 51 / 32767 + 1;//�������������
	}

}//���캯��Poker()����
void Poker::initPoker()
{
	cout << "��һ����Ϸ��ʼ����ʼϴ��>>>>>" << endl;

	pokerF[0] = randNum[j++];  //����1-52�������
	pokerF[1] = randNum[j++];  //����1-52�������
	pokerL[0] = randNum[j++];  //����1-52�������
	pokerL[1] = randNum[j++];  //����1-52�������

	pokerNumF = 2;
	pokerNumL = 2;

	cout << "ϴ�����,�����Ϊ:" << getPokerF() << endl;
}//void Poker::initPoker()����

string Poker::getPokerF()//���ַ�������ʽ������ҵ���
{
	int i;
	string result = "";

	for (i = 0; i<pokerNumF; i++)
		result = result + pokerName[pokerF[i]] + " ";

	return result;
}//string Poker::getPokerF()����

string Poker::getPokerL()//���ַ�������ʽ����ׯ�ҵ���
{
	int i;
	string result = "";

	for (i = 0; i<pokerNumL; i++)
		result = result + pokerName[pokerL[i]] + " ";

	return result;
}//string Poker::getPokerL()����

int Poker::getSumF()   //������ҵ��ܵ���
{
	int result = 0;

	for (int i = 0; i<pokerNumF; i++)
		result = result + pokerValue[pokerF[i]];

	return result;
}

int Poker::getSumL()//����ׯ�ҵ��ܵ���
{

	int result = 0;

	for (int i = 0; i<pokerNumL; i++)
		result = result + pokerValue[pokerL[i]];

	return result;
}

void Poker::farmerAsk()
{
	if (pokerNumF >= 5)
	{
		cout << "��������ѹ�5�ţ�������Ҫ����" << endl;
		landlordProcess();
	}
	else
	{
		pokerF[pokerNumF++] = randNum[j++];   //����1-52�������
		cout << "�����Ϊ:" << getPokerF() << endl;
		if (getSumF()>21)
		{
			cout << "�������,������" << bet << "Ԫ" << endl;
			money = money - bet;
			if (money <= 0)
			{
				cout << "���Ѿ�����ˣ�����" << endl;
				cout << "��Ϸ����" << endl;
				exit(0);
			}
			inputBet();
			initPoker();
		}
		else if (getSumF() == 21)
		{
			landlordProcess();
		}
	}
}

void Poker::landlordAsk()
{
	if (pokerNumL >= 5)
	{
		if (getSumF()>getSumL())
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "��Ӯ��,��Ӯ��" << bet << "Ԫ" << endl;
			money = money + bet;
			inputBet();
			initPoker();
		}
		else if (getSumF() == getSumL())
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "ƽ��" << endl;
			inputBet();
			initPoker();
		}
		else if (getSumF()<getSumL())
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "������,������" << bet << "Ԫ" << endl;
			money = money - bet;
			if (money <= 0)
			{
				cout << "���Ѿ�����ˣ�����" << endl;
				cout << "��Ϸ����" << endl;
				exit(0);
			}
			inputBet();
			initPoker();
		}
	}
	else
	{
		pokerL[pokerNumL++] = randNum[j++];   //����1-52�������
		if (getSumL()>21)
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "ׯ�ҳ�����,��Ӯ��" << bet << "Ԫ" << endl;
			money = money + bet;
			inputBet();
			initPoker();
		}
		else    landlordProcess();
	}
}
void Poker::inputBet()
{
	cout << "��������" << money << "Ԫ,�������ע:";
	do
	{
		cin >> bet;
		if (bet>money)
			cout << "��������û��ô��Ǯ�����������������:";
	} while (bet>money);

}

void Poker::newGame()
{
	inputBet();
	initPoker();
	cout << "��õ�����Ϊ:" << getPokerF() << endl;
}

void Poker::landlordProcess()
{
	if (getSumL() >= 17)
	{
		if (getSumL()>getSumF())
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "ׯ�һ�ʤ��������" << bet << "Ԫ" << endl;
			money = money - bet;
			if (money <= 0)
			{
				cout << "���Ѿ�����ˣ�����" << endl;
				cout << "��Ϸ����" << endl;
				exit(0);
			}
			inputBet();
			initPoker();
		}
		else if (getSumF() == getSumL())
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "������Ϸƽ��" << endl;
			inputBet();
			initPoker();
		}
		else
		{
			cout << "ׯ�ҵ���Ϊ" << getPokerL() << endl;
			cout << "��Ӯ��,��Ӯ��" << bet << "Ԫ" << endl;
			money = money + bet;
			inputBet();
			initPoker();
		}
	}
	else
	{
		landlordAsk();
	}
}


int main()
{
	int choose = 1;
	Poker poker;
	cout << "****************** ��ӭ���ʮһ����Ϸ ******************" << endl << endl;
	poker.inputBet();
	poker.initPoker();                   //ϴ��

	while (choose == 1 || choose == 2 || choose == 3 || choose == 4)
	{
		cout << "1.Ҫ�� 2.��Ҫ�� 3.���¿�ʼ 4.�˳�  >>����������ѡ�����:";
		cin >> choose;
		if (choose == 1)            poker.farmerAsk();
		else if (choose == 2)      poker.landlordProcess();
		else if (choose == 3)      poker.newGame();
		else if (choose == 4)      exit(0);
	}

	return 0;
}//main��������