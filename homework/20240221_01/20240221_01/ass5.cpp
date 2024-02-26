#include <iostream>
#include <time.h>
using namespace std;

int _count1 = 0;
int _count2 = 0;
int _myHand = 0;
int _com = 0;
int _mode = 0;

int mode0 = 5, mode1 = 10;
enum Hand
{
	_scissors, // 0
	_rock, // 1
	_paper // 2
};

void judge(int c, int m) {
	int _answer;

	if (c == _rock)
	{
		if (m == _rock)
		{
			_answer = 2;
		}
		else if(m == _scissors)
		{
			_answer = 1;
		}
		else
		{
			_answer = 0;
		}
	}
	else if (c == _scissors)
	{
		if (m == _rock)
		{
			_answer = 0;
		}
		else if (m == _scissors)
		{
			_answer = 2;
		}
		else
		{
			_answer = 1;
		}
	}
	else
	{
		if (m == _rock)
		{
			_answer = 1;
		}
		else if (m == _scissors)
		{
			_answer = 0;
		}
		else
		{
			_answer = 2;
		}
	}

	switch (_answer)
	{
	case 0:
		cout << "승리했습니다." << endl;
		_count1++;
		break;
	case 1:
		cout << "패배했습니다." << endl;
		break;
	default:
		cout << "비겼습니다." << endl;
		break;
	}
}

void game() 
{
	while (1)
	{
		cout << "가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> _myHand;
		if (0 <= _myHand && _myHand < 3) break;
	}
	_com = rand() % 3;
	judge(_com, _myHand);
}

void main() {
	srand(time(NULL));
	while (1) 
	{
		cout << "모드를 입력하세요( 0 : 승수, 1 : 판수 ) >> ";
		cin >> _mode;
		cout << endl;
		if (_mode == 0 || _mode == 1) break;
	}

	switch (_mode)
	{
	case 0:
		cout << "승수 모드로 게임을 시작합니다." << endl;
		while (_count1 < mode0)
		{
			game();
		}
		break;
	case 1:
		cout << "판수 모드로 게임을 시작합니다." << endl;
		while (_count2 < mode1)
		{
			cout << _count2 + 1 << "번째 판 ))";
			game();
			_count2++;
		}
		break;
	default:
		break;
	}
}