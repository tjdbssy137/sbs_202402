#include <iostream>
using namespace std;

int _com[2] = {}, _my[2] = {};

string hand[3] = {"가위", "바위", "보"};

enum HAND {
	_scissors = 1,
	_rock,
	_paper
};

void Conclusion(int com, int my)
{
	cout << "컴퓨터는 " << hand[com - 1] << "를 냈습니다." << endl;
	cout << "당신은 " << hand[my - 1] << "를 냈습니다." << endl;

	if (my == _scissors)
	{
		if (com == _scissors)
		{
			cout << "비겼습니다.";
		}
		else if (com == _rock)
		{
			cout << "당신의 패배입니다.";
		}
		else
		{
			cout << "당신의 승리입니다.";
		}
	}
	else if (my == _rock)
	{
		if (com == _scissors)
		{
			cout << "당신의 승리입니다.";
		}
		else if (com == _rock)
		{
			cout << "비겼습니다.";
		}
		else
		{
			cout << "당신의 패배입니다.";
		}
	}
	else
	{
		if (com == _scissors)
		{
			cout << "당신의 패배입니다.";
		}
		else if (com == _rock)
		{
			cout << "당신의 승리입니다.";
		}
		else
		{
			cout << "비겼습니다.";
		}
	}
}

void Choose(int LC, int RC, int LMH, int RMH)
{
	cout << "컴퓨터는 " << hand[LC - 1] << "와 " << hand[RC - 1] << "를 냈습니다." << endl;
	cout << "당신은 " << hand[LMH - 1] << "와 " << hand[RMH - 1] << "를 냈습니다." << endl;

	int MyHand = 0;
	cout << "낼 손 (왼손 1, 오른손 2) >>> ";
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
	cout << "가위(1) 바위(2) 보(3)" << endl;
	cout << "왼손에 낼 손 >>> ";
	cin >> _my[0];
	cout << "오른손에 낼 손 >>> ";
	cin >> _my[1];
}
void main()
{
	srand(time(NULL));
	Computer();
	MyHand();
	Choose(_com[0], _com[1], _my[0], _my[1]);
}