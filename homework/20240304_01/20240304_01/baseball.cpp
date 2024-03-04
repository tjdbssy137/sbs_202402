#include <iostream>
#include <vector>
using namespace std;
// ����
// ���� �߱�

// ��ǻ�Ͱ� 4���� ���ڸ� ���
// ù��° �ڸ����� 1~9
// �μ��׹�° �ڸ����� 0~9
// 1��°���� 4��° �ڸ��� ���ڴ� ���� ��ġ�� ����. -> 1223 �̷� �� �� ��.

// user : 1234
// computer : 5124
// ������ ���ڸ� �Է�
// �ڸ����� ������ ���� �� strike
// ���� ���� �� ������ ball
// 4�� �ڸ����� ������ �����ϱ� 1strike
// 23�� �ڸ����� �޶� ���� �����ϱ� 2ball

// ������ 9�� �Է��ϴ� ���� 4strike�� �� ����� ���� �й�

// �ʹ� ����� GotoXY ���

int _inputNumber = 0;
vector<int> _arrayNumber;
vector<int> _comNumber;
int _point[2] = {}; //[0] = ball, [1] = strike
int _chance = 9;

void ComputerNumber();
void InputGuessNumber();
void Separator();
void Result();
void ResetArrayNumber();

void main()
{
	srand(time(NULL));
	ComputerNumber();
	while (_chance > 0)
	{
		InputGuessNumber();
		Separator();
		Result();
		ResetArrayNumber();
		_chance--;
		cout << "���� ��ȸ�� .. " << _chance << endl;
	}
	if (_chance == 0)
	{
		cout << "���ӿ��� �й��ϼ̽��ϴ�.";
	}
}

void ComputerNumber()
{
	vector<int> _usedNumber;

	_comNumber.push_back(rand() % 8 + 1);
	_usedNumber.push_back(_comNumber.front());

	int i = 0;
	while (i < 4)
	{
		int number = rand() % 9;
		int flag = 0;
		for (int i = 0; i < _usedNumber.size(); i++)
		{
			if (_usedNumber.at(i) == number)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			_usedNumber.push_back(number);
			_comNumber.push_back(number);
			i++;
		}
	}
	cout << _comNumber[0] << _comNumber[1] << _comNumber[2] << _comNumber[3] << endl;
}

void InputGuessNumber()
{
	while (1)
	{
		cout << "���ڸ����� �Է����ּ��� : ";
		cin >> _inputNumber;
		if (999 < _inputNumber && _inputNumber < 9999)
		{
			break;
		}
	}
}

void Separator()
{
	int _multi = 1000;
	for (int i = 0; i < 4; i++)
	{
		_arrayNumber.push_back(_inputNumber / _multi);
		_inputNumber -= (_inputNumber / _multi) * _multi;
		_multi /= 10;
	}
	//cout << _arrayNumber[0] << _arrayNumber[1] << _arrayNumber[2] << _arrayNumber[3];
}

void Result()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (_arrayNumber.at(i) == _comNumber.at(j))
			{
				if (i == j)
				{
					_point[1]++;
				}
				else
				{
					_point[0]++;
				}
			}
		}
	}
	if (_point[1] == 4)
	{
		cout << "���ӿ��� �¸��ϼ̽��ϴ�.";
		exit(0);
	}
	else
	{
		cout << "ball : " << _point[0] << "\t strike : " << _point[1] << endl;
		_point[0] = 0;
		_point[1] = 0;
	}
}

void ResetArrayNumber()
{
	while (_arrayNumber.size())
	{
		_arrayNumber.pop_back();
	}
}