#include <iostream>
#include <time.h>
using namespace std;

int _count = 0;

enum Hand
{
	_scissors, // 0
	_rock, // 1
	_paper // 2
};
void judge(int c, int m) {
	if (c == _rock)
	{
		if (m == _rock)
		{
			cout << "비겼습니다." << endl;
		}
		else if (m == _scissors)
		{
			cout << "패배했습니다." << endl;
		}
		else
		{
			cout << "승리했습니다." << endl;
		}
	}
	else if (c == _scissors)
	{
		if (m == _rock)
		{
			cout << "승리했습니다." << endl;
		}
		else if (m == _scissors)
		{
			cout << "비겼습니다." << endl;
		}
		else
		{
			cout << "패배했습니다." << endl;
		}
	}
	else if (c == _paper)
	{
		if (m == _rock)
		{
			cout << "패배했습니다." << endl;
		}
		else if (m == _scissors)
		{
			cout << "승리했습니다." << endl;
		}
		else
		{
			cout << "비겼습니다." << endl;
		}
	}
}
void main() {
	srand(time(NULL));
	
	while (_count < 5)
	{
		int _com = rand() % 3;
		int _myHand = 0;
		cout << "가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> _myHand;
		judge(_com, _myHand);
	}
}