#include <iostream>
using namespace std;
#define HAND_MAX 2
int _com[HAND_MAX] = {}, _my[HAND_MAX] = {};

string hand[3] = {"����", "����", "��"};

enum HAND {
	SCISSORS, //enum�� �빮�ڷ�, ������ ������ 0
	ROCK,
	PAPER,

	HAND_END
};

//�Լ� �̸��� �����
void PrintConclusion(int com, int my);
void ChooseFinal(int LC, int RC, int LMH, int RMH);
void ChooseComputerHands();
void ChooseMyHands();

void main()
{
	srand(time(NULL));
	ChooseComputerHands();
	ChooseMyHands();
	ChooseFinal(_com[0], _com[1], _my[0], _my[1]);
}

void PrintConclusion(int com, int my)
{
	cout << "��ǻ�ʹ� " << hand[com] << "�� �½��ϴ�." << endl;
	cout << "����� " << hand[my] << "�� �½��ϴ�." << endl;

	if (my == SCISSORS)
	{
		if (com == SCISSORS)
		{
			cout << "�����ϴ�.";
		}
		else if (com == ROCK)
		{
			cout << "����� �й��Դϴ�.";
		}
		else
		{
			cout << "����� �¸��Դϴ�.";
		}
	}
	else if (my == ROCK)
	{
		if (com == SCISSORS)
		{
			cout << "����� �¸��Դϴ�.";
		}
		else if (com == ROCK)
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
		if (com == SCISSORS)
		{
			cout << "����� �й��Դϴ�.";
		}
		else if (com == ROCK)
		{
			cout << "����� �¸��Դϴ�.";
		}
		else
		{
			cout << "�����ϴ�.";
		}
	}
}

void ChooseFinal(int LC, int RC, int LMH, int RMH)
{
	cout << "��ǻ�ʹ� " << hand[LC] << "�� " << hand[RC] << "�� �½��ϴ�." << endl;
	cout << "����� " << hand[LMH] << "�� " << hand[RMH] << "�� �½��ϴ�." << endl;

	int MyHand = 0;
	cout << "�� �� (�޼� 0, ������ 1) >>> ";
	cin >> MyHand;
	PrintConclusion(_com[rand() % HAND_MAX], _my[MyHand]);
}

void ChooseComputerHands()
{
	_com[0] = rand() % HAND_END;
	_com[1] = rand() % HAND_END;
}

void ChooseMyHands()
{
	cout << "����(0) ����(1) ��(2)" << endl;
	cout << "�޼տ� �� �� >>> ";
	cin >> _my[0];
	cout << "�����տ� �� �� >>> ";
	cin >> _my[1];
}