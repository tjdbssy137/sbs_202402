#include <iostream>
#include <time.h>
using namespace std;

void judge(int c, int m) {
	if (m > c || (m == 0 && c == 2))
	{
		cout << "�¸��߽��ϴ�." << endl;
	}
	else if ((m == 2 && c == 0) || (m < c))
	{
		cout << "�й��߽��ϴ�." << endl;
	}
	else if (m == c)
	{
		cout << "�����ϴ�." << endl;
	}
}
void main() {
	srand(time(NULL));
	int _count = 0;
	while (_count < 10)
	{
		int _com = rand() % 3;
		int _myHand = 0;
		cout << _count+1 << "��° �� )) ����(0)����(1)��(2)�� �Է��ϼ��� >> ";
		cin >> _myHand;
		judge(_com, _myHand);
		_count++;
	}
}