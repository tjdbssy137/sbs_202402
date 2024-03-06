#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
using namespace std;
//콘솔을 사용하는 방식을 완전히 잘 못 생각하고 있었어요.. 다시 짤 거니까 피드백은 다다음에 부탁드립니다.

int _inputNumber[10] = {};
vector<int> _inputPlayerNumber;
vector<int> _usedNumber;
vector<int> _comNumber;
int _point[2] = {}; //[0] = ball, [1] = strike
int _chance = 9;
int _setColor = 0;

void ComputerNumber();
void Result();
void PrintNumber();
void InputKeboard();
void ResetArray();
void PrintChooseNumber();

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
			PrintNumber();
			InputKeboard();
			system("cls");
			if (_inputPlayerNumber.size() == 4) break;
		}
		PrintChooseNumber();
		Result();
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
			if (_inputPlayerNumber.at(i) == _comNumber.at(j))
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
		ResetArray();
		for (int i = 0; i < 10; i++)
		{
			_inputNumber[i] = 0;
		}
	}
}

void PrintNumber()
{
	setcolor(15, 0);
	cout << "□□□■   ■■■■   ■■■■   ■□■□   ■■■■   ■■■■   ■■■■   ■■■■   ■■■■   □■■□ " << endl;
	cout << "□□□■   □□□■   □□□■   ■□■□   ■□□□   ■□□□   ■□□■   ■□□■   ■□□■   ■□□■ " << endl;
	cout << "□□□■   □□□■   □□□■   ■□■□   ■□□□   ■□□□   ■□□■   ■□□■   ■□□■   ■□□■ " << endl;
	cout << "□□□■   ■■■■   ■■■■   ■■■■   ■■■■   ■■■■   □□□■   ■■■■   ■■■■   ■□□■ " << endl;
	cout << "□□□■   ■□□□   □□□■   □□■□   □□□■   ■□□■   □□□■   ■□□■   □□□■   ■□□■ " << endl;
	cout << "□□□■   ■□□□   □□□■   □□■□   ■□□■   ■□□■   □□□■   ■□□■   □□□■   ■□□■ " << endl;
	cout << "□□□■   ■■■■   ■■■■   □□■□   ■■■■   ■■■■   □□□■   ■■■■   ■■■■   □■■□ " << endl;
}
void InputKeboard()
{
	int x = 0;
	char input = 0;
	while (1)
	{
		if (_kbhit())
		{
			input = _getch();
			gotoxy(x, 10); printf(" ");
			setcolor(15, 0);
			switch (input)
			{
			case '0':
				x = 64;
				_usedNumber.push_back(0);
				if (_inputNumber[0] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '1':
				x = 1;
				_usedNumber.push_back(1);
				if (_inputNumber[1] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '2':
				x = 8;
				_usedNumber.push_back(2);
				if (_inputNumber[2] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '3':
				x = 15;
				_usedNumber.push_back(3);
				if (_inputNumber[3] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '4':
				x = 22;
				_usedNumber.push_back(4);
				if (_inputNumber[4] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '5':
				x = 29;
				_usedNumber.push_back(5);
				if (_inputNumber[5] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '6':
				x = 36;
				_usedNumber.push_back(6);
				if (_inputNumber[6] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '7':
				x = 43;
				_usedNumber.push_back(7);
				if (_inputNumber[7] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '8':
				x = 50;
				_usedNumber.push_back(8);
				if (_inputNumber[8] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			case '9':
				x = 57;
				_usedNumber.push_back(9);
				if (_inputNumber[9] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("♠");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("♠");
				}
				break;
			default:
				break;
			}
			if (input == 'a')
			{
				int a = _usedNumber.back();
				_inputPlayerNumber.push_back(a);
				_inputNumber[a] = 1;
				break;
			}
		}
	}
}
void ResetArray()
{
	while (_inputPlayerNumber.size())
	{
		_inputPlayerNumber.pop_back();
	}
}
void PrintChooseNumber()
{
	cout << "내가 선택한 숫자는 ";
	for (int i = 0; i < 4; i++)
	{
		cout << _inputPlayerNumber.at(i);
	}
	cout << endl;
}