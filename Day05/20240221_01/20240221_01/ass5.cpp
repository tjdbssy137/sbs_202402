#include <iostream>
#include <time.h>
using namespace std;

int _count = 0;
int _count2 = 0;
int _myHand = 0;
int _com = 0;
int _mode = 0;

void judge(int c, int m) {
	if (m > c || (m == 0 && c == 2))
	{
		cout << "승리했습니다." << endl;
		_count++;
	}
	else if ((m == 2 && c == 0) || (m < c))
	{
		cout << "패배했습니다." << endl;
	}
	else if (m == c)
	{
		cout << "비겼습니다." << endl;
	}
}
void mode0() {
	cout << "승수 모드로 게임을 시작합니다." << endl;
	while (_count < 5)
	{
		_com = rand() % 3;
		cout << "가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> _myHand;
		judge(_com, _myHand);
	}
	cout << "게임 종료";
}
void mode1() {
	cout << "판수 모드로 게임을 시작합니다." << endl;
	while (_count2 < 10)
	{
		_com = rand() % 3;
		cout << _count2 + 1 << "번째 판 )) 가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> _myHand;
		judge(_com, _myHand);
		_count2++;
	}
	cout << "게임 종료";
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
		mode0();
		break;
	case 1:
		mode1();
		break;
	default:
		break;
	}
}