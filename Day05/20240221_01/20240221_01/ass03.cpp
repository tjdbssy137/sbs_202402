#include <iostream>
#include <time.h>
using namespace std;

int _count = 0;
void judge(int c, int m) {
	if (m > c || (m == 0 && c == 2))
	{
		cout << "승리했습니다." << endl;
		_count++;
	}
	else if ((m == 2 && c == 0) || (m < c))
	{
		cout << "패배했습니다." << endl;
	}else if(m == c)
	{
		cout << "비겼습니다." << endl;
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