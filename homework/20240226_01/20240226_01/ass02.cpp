#include <iostream>
using namespace std;

int _com[2] = {}, _my[2] = {};

string hand[3] = {"����", "����", "��"};

enum HAND {
	_scissors = 1,
	_rock,
	_paper
};

void Conclusion(int com, int my)
{
	cout << "��ǻ�ʹ� " << hand[com - 1] << "�� �½��ϴ�." << endl;
	cout << "����� " << hand[my - 1] << "�� �½��ϴ�." << endl;

	if (my == _scissors)
	{
		if (com == _scissors)
		{
			cout << "�����ϴ�.";
		}
		else if (com == _rock)
		{
			cout << "����� �й��Դϴ�.";
		}
		else
		{
			cout << "����� �¸��Դϴ�.";
		}
	}
	else if (my == _rock)
	{
		if (com == _scissors)
		{
			cout << "����� �¸��Դϴ�.";
		}
		else if (com == _rock)
		{
			cout << "�����ϴ�.";
		}
		else
		{
			cout << "����� �й��Դϴ�.";
		}
	}
	else
	{
		if (com == _scissors)
		{
			cout << "����� �й��Դϴ�.";
		}
		else if (com == _rock)
		{
			cout << "����� �¸��Դϴ�.";
		}
		else
		{
			cout << "�����ϴ�.";
		}
	}
}

void Choose(int LC, int RC, int LMH, int RMH)
{
	cout << "��ǻ�ʹ� " << hand[LC - 1] << "�� " << hand[RC - 1] << "�� �½��ϴ�." << endl;
	cout << "����� " << hand[LMH - 1] << "�� " << hand[RMH - 1] << "�� �½��ϴ�." << endl;

	int MyHand = 0;
	cout << "�� �� (�޼� 1, ������ 2) >>> ";
	cin >> MyHand;
	Conclusion(_com[rand() % 2], _my[MyHand - 1]);
}

void Computer()
{
	_com[0] = rand() % 3 + 1;
	_com[1] = rand() % 3 + 1;
}

void MyHand()
{
	cout << "����(1) ����(2) ��(3)" << endl;
	cout << "�޼տ� �� �� >>> ";
	cin >> _my[0];
	cout << "�����տ� �� �� >>> ";
	cin >> _my[1];
}
void main()
{
	srand(time(NULL));
	Computer();
	MyHand();
	Choose(_com[0], _com[1], _my[0], _my[1]);
}