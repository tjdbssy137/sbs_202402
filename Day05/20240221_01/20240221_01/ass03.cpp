#include <iostream>
#include <time.h>
using namespace std;

int _count = 0;
void judge(int c, int m) {
	if (m > c || (m == 0 && c == 2))
	{
		cout << "�¸��߽��ϴ�." << endl;
		_count++;
	}
	else if ((m == 2 && c == 0) || (m < c))
	{
		cout << "�й��߽��ϴ�." << endl;
	}else if(m == c)
	{
		cout << "�����ϴ�." << endl;
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