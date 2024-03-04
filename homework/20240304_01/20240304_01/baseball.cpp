#include <iostream>
#include <vector>
using namespace std;
// 숙제
// 숫자 야구

// 컴퓨터가 4개의 숫자를 기억
// 첫번째 자리수는 1~9
// 두세네번째 자리수는 0~9
// 1번째부터 4번째 자리의 숫자는 서로 겹치지 않음. -> 1223 이런 거 안 됨.

// user : 1234
// computer : 5124
// 유저가 숫자를 입력
// 자릿수와 값까지 같은 게 strike
// 값만 같은 게 있으면 ball
// 4가 자릿수와 값까지 같으니까 1strike
// 23이 자릿수는 달라도 값이 같으니까 2ball

// 유저가 9번 입력하는 동안 4strike를 못 만들면 유저 패배

// 너무 쉬우면 GotoXY 사용

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
		cout << "남은 기회는 .. " << _chance << endl;
	}
	if (_chance == 0)
	{
		cout << "게임에서 패배하셨습니다.";
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
		cout << "네자리수를 입력해주세요 : ";
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
		cout << "게임에서 승리하셨습니다.";
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