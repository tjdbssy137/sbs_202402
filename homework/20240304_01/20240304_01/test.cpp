#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
using namespace std;

int _inputNumber[10] = {};
vector<int> _inputPlayerNumber;
vector<int> _usedNumber;
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

void PrintNumber()
{
	setcolor(15,0);
	cout << "¡à¡à¡à¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡à¡á¡à   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡à¡á¡á¡à " << endl;
	cout << "¡à¡à¡à¡á   ¡à¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡á¡à   ¡á¡à¡à¡à   ¡á¡à¡à¡à   ¡á¡à¡à¡á   ¡á¡à¡à¡á   ¡á¡à¡à¡á   ¡á¡à¡à¡á " << endl;
	cout << "¡à¡à¡à¡á   ¡à¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡á¡à   ¡á¡à¡à¡à   ¡á¡à¡à¡à   ¡á¡à¡à¡á   ¡á¡à¡à¡á   ¡á¡à¡à¡á   ¡á¡à¡à¡á " << endl;
	cout << "¡à¡à¡à¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡à¡à¡à¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡á¡à¡à¡á " << endl;
	cout << "¡à¡à¡à¡á   ¡á¡à¡à¡à   ¡à¡à¡à¡á   ¡à¡à¡á¡à   ¡à¡à¡à¡á   ¡á¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡à¡á " << endl;
	cout << "¡à¡à¡à¡á   ¡á¡à¡à¡à   ¡à¡à¡à¡á   ¡à¡à¡á¡à   ¡á¡à¡à¡á   ¡á¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡à¡á   ¡à¡à¡à¡á   ¡á¡à¡à¡á " << endl;
	cout << "¡à¡à¡à¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡à¡à¡á¡à   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡à¡à¡à¡á   ¡á¡á¡á¡á   ¡á¡á¡á¡á   ¡à¡á¡á¡à " << endl;
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
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '1':
				x = 1;
				_usedNumber.push_back(1);
				if (_inputNumber[1] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15,0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '2':
				x = 8;
				_usedNumber.push_back(2);
				if (_inputNumber[2] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '3':
				x = 15;
				_usedNumber.push_back(3);
				if (_inputNumber[3] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '4':
				x = 22;
				_usedNumber.push_back(4);
				if (_inputNumber[4] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '5':
				x = 29;
				_usedNumber.push_back(5);
				if (_inputNumber[5] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '6':
				x = 36;
				_usedNumber.push_back(6);
				if (_inputNumber[6] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '7':
				x = 43;
				_usedNumber.push_back(7);
				if (_inputNumber[7] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '8':
				x = 50;
				_usedNumber.push_back(8);
				if (_inputNumber[8] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
				}
				break;
			case '9':
				x = 57;
				_usedNumber.push_back(9);
				if (_inputNumber[9] == 1)
				{
					setcolor(10, 0);  gotoxy(x, 10); printf("¢¼");
				}
				else
				{
					setcolor(15, 0);  gotoxy(x, 10); printf("¢¼");
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
void main()
{
	for (int i = 0; i < 3; i++)
	{
		PrintNumber();
		InputKeboard();
		system("cls");
	}
	
}