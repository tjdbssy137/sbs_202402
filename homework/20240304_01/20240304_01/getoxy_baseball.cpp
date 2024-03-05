#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
using namespace std;

vector<int> _inputNumber;
vector<int> _arrayNumber;
vector<int> _comNumber;
int _point[2] = {}; //[0] = ball, [1] = strike
int _chance = 9;
int _setColor = 0;

void ComputerNumber();
void Result();
void ResetArrayNumber();
void InputKeboard();

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void main()
{
	srand(time(NULL));
	ComputerNumber();
	while (_chance > 0)
	{
		while (1)
		{
			InputKeboard();
			if (_inputNumber.size() == 4) break;
		}
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
	//cout << _comNumber[0] << _comNumber[1] << _comNumber[2] << _comNumber[3] << endl;
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


void PrintNumber()
{
	cout << "□□□■   ■■■■   ■■■■   ■□■□   ■■■■   ■■■■   ■■■■   ■■■■   ■■■■   □■■□ " << endl;
	cout << "□□□■   □□□■   □□□■   ■□■□   ■□□□   ■□□□   ■□□■   ■□□■   ■□□■   ■□□■ " << endl;
	cout << "□□□■   □□□■   □□□■   ■□■□   ■□□□   ■□□□   ■□□■   ■□□■   ■□□■   ■□□■ " << endl;
	cout << "□□□■   ■■■■   ■■■■   ■■■■   ■■■■   ■■■■   □□□■   ■■■■   ■■■■   ■□□■ " << endl;
	cout << "□□□■   ■□□□   □□□■   □□■□   □□□■   ■□□■   □□□■   ■□□■   □□□■   ■□□■ " << endl;
	cout << "□□□■   ■□□□   □□□■   □□■□   ■□□■   ■□□■   □□□■   ■□□■   □□□■   ■□□■ " << endl;
	cout << "□□□■   ■■■■   ■■■■   □□■□   ■■■■   ■■■■   □□□■   ■■■■   ■■■■   □■■□ " << endl;
	cout << endl;

	SetPrintColor();
}

void SetPrintColor()
{
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_inputNumber.at(i) == j)
			{
				setcolor(10, 0); cout << "■■■■   ";
			}
			else
			{
				setcolor(0, 0); cout << "■■■■   ";
			}
		}
	}
	cout << endl;
}
void InputKeboard()
{
	PrintNumber();
	int x = 0;
	while (true)
	{
		char input = 0;
		if (_kbhit())
		{
			input = _getch();

			gotoxy(x, 10); printf(" ");
			switch (input)
			{
			case '0':
				x = 19;
				if (input == 13)
				{
					_inputNumber.push_back(0);
				}
				break;
			case '1':
				x = 1;
				if (input == 13)
				{
					_inputNumber.push_back(1);
				}
				break;
			case '2':
				x = 3;
				if (input == 13)
				{
					_inputNumber.push_back(2);
				}
				break;
			case '3':
				x = 5;
				if (input == 13)
				{
					_inputNumber.push_back(3);
				}
				break;
			case '4':
				x = 7;
				if (input == 13)
				{
					_inputNumber.push_back(4);
				}
				break;
			case '5':
				x = 9;
				if (input == 13)
				{
					_inputNumber.push_back(5);
				}
				break;
			case '6':
				x = 11;
				if (input == 13)
				{
					_setColor = 10;
					_inputNumber.push_back(6);
				}
				break;
			case '7':
				x = 13;
				if (input == 13)
				{
					_inputNumber.push_back(7);
				}
				break;
			case '8':
				x = 15;
				if (input == 13)
				{
					_inputNumber.push_back(8);
				}
				break;
			case '9':
				x = 17;
				if (input == 13)
				{
					_inputNumber.push_back(9);
				}
				break;
			default:
				break;
			}
			gotoxy(x, 10); printf("♠");
		}
		
	}
}