#include <iostream>
#include <time.h>
using namespace std;
// ������ ����
// 1. ��ǻ�� �� ���� ���� ���ڸ� �̾Ƽ�(0~99)
// 2. ���� ���ڰ� ���� ���� �¸�
void main() 
{
	srand(time(NULL));
	
	int _com1, _com2, _com3;
	_com1 = rand() % 100;
	_com2 = rand() % 100;
	_com3 = rand() % 100;

	int big = 0;
	if (big <= _com1) big = _com1;
	if (big <= _com2) big = _com2;
	if (big <= _com3) big = _com3;

	cout << "_com1 : " << _com1 << "\t_com2 : " << _com2 << "\t_com3 : " << _com3 << endl;
	if (big == _com1)
	{
		cout << "_com1�� �¸�";
	}
	else if (big == _com2)
	{
		cout << "_com2�� �¸�";
	}
	else
	{
		cout << "_com3�� �¸�";
	}
}