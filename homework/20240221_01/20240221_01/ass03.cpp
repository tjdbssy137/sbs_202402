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
			cout << "�����ϴ�." << endl;
		}
		else if (m == _scissors)
		{
			cout << "�й��߽��ϴ�." << endl;
		}
		else
		{
			cout << "�¸��߽��ϴ�." << endl;
		}
	}
	else if (c == _scissors)
	{
		if (m == _rock)
		{
			cout << "�¸��߽��ϴ�." << endl;
		}
		else if (m == _scissors)
		{
			cout << "�����ϴ�." << endl;
		}
		else
		{
			cout << "�й��߽��ϴ�." << endl;
		}
	}
	else if (c == _paper)
	{
		if (m == _rock)
		{
			cout << "�й��߽��ϴ�." << endl;
		}
		else if (m == _scissors)
		{
			cout << "�¸��߽��ϴ�." << endl;
		}
		else
		{
			cout << "�����ϴ�." << endl;
		}
	}
}
void main() {
	srand(time(NULL));
	
	while (_count < 5)
	{
		int _com = rand() % 3;
		int _myHand = 0;
		cout << "����(0)����(1)��(2)�� �Է��ϼ��� >> ";
		cin >> _myHand;
		judge(_com, _myHand);
	}
}