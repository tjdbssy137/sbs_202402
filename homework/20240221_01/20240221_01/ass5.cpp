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
		cout << "�¸��߽��ϴ�." << endl;
		_count++;
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
void mode0() {
	cout << "�¼� ���� ������ �����մϴ�." << endl;
	while (_count < 5)
	{
		_com = rand() % 3;
		cout << "����(0)����(1)��(2)�� �Է��ϼ��� >> ";
		cin >> _myHand;
		judge(_com, _myHand);
	}
	cout << "���� ����";
}
void mode1() {
	cout << "�Ǽ� ���� ������ �����մϴ�." << endl;
	while (_count2 < 10)
	{
		_com = rand() % 3;
		cout << _count2 + 1 << "��° �� )) ����(0)����(1)��(2)�� �Է��ϼ��� >> ";
		cin >> _myHand;
		judge(_com, _myHand);
		_count2++;
	}
	cout << "���� ����";
}
void main() {
	srand(time(NULL));
	while (1) 
	{
		cout << "��带 �Է��ϼ���( 0 : �¼�, 1 : �Ǽ� ) >> ";
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