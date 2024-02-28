#include <iostream>
using namespace std;
#define HAND_MAX 2
int _com[HAND_MAX] = {}, _my[HAND_MAX] = {};

string hand[3] = {"가위", "바위", "보"};

enum HAND {
	SCISSORS, //enum은 대문자로, 시작은 가급적 0
	ROCK,
	PAPER,

	HAND_END
};

//함수 이름은 동사로
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
	cout << "컴퓨터는 " << hand[com] << "를 냈습니다." << endl;
	cout << "당신은 " << hand[my] << "를 냈습니다." << endl;

	if (my == SCISSORS)
	{
		if (com == SCISSORS)
		{
			cout << "비겼습니다.";
		}
		else if (com == ROCK)
		{
			cout << "당신의 패배입니다.";
		}
		else
		{
			cout << "당신의 승리입니다.";
		}
	}
	else if (my == ROCK)
	{
		if (com == SCISSORS)
		{
			cout << "당신의 승리입니다.";
		}
		else if (com == ROCK)
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
		if (com == SCISSORS)
		{
			cout << "당신의 패배입니다.";
		}
		else if (com == ROCK)
		{
			cout << "당신의 승리입니다.";
		}
		else
		{
			cout << "비겼습니다.";
		}
	}
}

void ChooseFinal(int LC, int RC, int LMH, int RMH)
{
	cout << "컴퓨터는 " << hand[LC] << "와 " << hand[RC] << "를 냈습니다." << endl;
	cout << "당신은 " << hand[LMH] << "와 " << hand[RMH] << "를 냈습니다." << endl;

	int MyHand = 0;
	cout << "낼 손 (왼손 0, 오른손 1) >>> ";
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
	cout << "가위(0) 바위(1) 보(2)" << endl;
	cout << "왼손에 낼 손 >>> ";
	cin >> _my[0];
	cout << "오른손에 낼 손 >>> ";
	cin >> _my[1];
}