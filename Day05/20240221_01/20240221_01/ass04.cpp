#include <iostream>
#include <time.h>
using namespace std;

void judge(int c, int m) {
	if (m > c || (m == 0 && c == 2))
	{
		cout << "승리했습니다." << endl;
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
void main() {
	srand(time(NULL));
	int _count = 0;
	while (_count < 10)
	{
		int _com = rand() % 3;
		int _myHand = 0;
		cout << _count+1 << "번째 판 )) 가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> _myHand;
		judge(_com, _myHand);
		_count++;
	}
}