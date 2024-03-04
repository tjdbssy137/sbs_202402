#include <iostream>
#include <Windows.h>
using namespace std;

int _myBingo[5 * 5] = {};
int _comBingo[5 * 5] = {};
// index0 ~ index4 => 1줄
// ...
// index20 ~ index24 => 5줄

int _removeNumber[2] = {};
// 0 = player, 1 = computer 

int _bingoCount[2] = {};
int _usedNumber[5 * 5] = {};

void GenerateMyBingo();
void GenerateComBingo();
void PrintBingo();
void InputRemoveNumber();
void RemoveBingoNumber();
void CheckBingoCount();

void main()
{
	/*
	빙고 룰
	- 1. 내 빙고판 5X5를 만든다
		- 1부터 25의 숫자가 랜덤으로 들어간다.
	- 2. 컴퓨터 빙고판 5X5를 만든다
		- 1부터 25의 숫자가 랜덤으로 들어간다.
	- 3. 빙고판을 출력한다.
	- 4. 플레이와 컴퓨터가 숫자를 입력한다.
	- 5. 입력한 숫자가 X표시가 된다.
		- myBingo[] = {1~25}
		- 이미 사용한 숫자는 -1로 표기 후 출력할 때 X로 표시.
	- 6. 3 ~ 5 과정 반복
	- 7. 3빙고가 되면 해당 유저 승리.
	*/
	srand(time(NULL));

	GenerateMyBingo();
	GenerateComBingo();

	while (true)
	{
		system("cls");
		PrintBingo();
		InputRemoveNumber();
		RemoveBingoNumber();
		CheckBingoCount();

		if (_bingoCount[0] == 3)
		{
			printf("승리했습니다.");
			break; // 가장 가까운 반복문 종료.
			return; // return을 실행하고 있는 함수를 종료
			exit(1); // program 종료
		}
		if (_bingoCount[0] == 3)
		{
			printf("패배했습니다.");
			break; // 가장 가까운 반복문 종료.
			return; // return을 실행하고 있는 함수를 종료
			exit(1); // program 종료
		}
	}
}

void GenerateMyBingo()
{
	for (int i = 0; i < 25; i++)
	{
		_myBingo[i] = i + 1;
	}
	for (int i = 0; i < 1000; i++)
	{
		int First = rand() % 25;
		int Second = rand() % 25;

		int temp = _myBingo[First];
		_myBingo[First] = _myBingo[Second];
		_myBingo[Second] = temp;
	}
}
void GenerateComBingo()
{
	for (int i = 0; i < 25; i++)
	{
		_comBingo[i] = i + 1;
	}
	for (int i = 0; i < 1000; i++)
	{
		int First = rand() % 25;
		int Second = rand() % 25;

		int temp = _comBingo[First];
		_comBingo[First] = _comBingo[Second];
		_comBingo[Second] = temp;
	}
}
void PrintBingo()
{
	cout << "내 빙고 판" << endl;
	int count = 0;
	for (int i = 0; i < 25; i++)
	{
		if (_myBingo[i] == -1)
		{
			printf("%2c ", 'X');
		}
		else
		{
			printf("%2d ", _myBingo[i]);
		}
		
		if (count % 5 == 4)
		{
			cout << endl;
		}
		count++;
	}

	count = 0;
	cout << "\n컴퓨터 빙고 판" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (_comBingo[i] == -1)
		{
			printf("%2c ", 'X');
		}
		else
		{
			printf("%2d ", _comBingo[i]);
		}

		if (count % 5 == 4)
		{
			cout << endl;
		}
		count++;
	}
}

void InputRemoveNumber()
{
	cout << "\n내가 지울 숫자 : ";
	do
	{
		cin >> _removeNumber[0];
	} while (false == (1 <= _removeNumber[0] && _removeNumber[1] <= 25));
	_removeNumber[1] = rand() % 25 + 1;
	printf("내가 지울 숫자 : %d\n", _removeNumber[0]);
	_usedNumber[_removeNumber[0]] = _removeNumber[0];

	while (1)
	{
		_removeNumber[1] = rand() % 25 + 1;
		if (_usedNumber[_removeNumber[1]] == 0)
		{
			_usedNumber[_removeNumber[1]] = _removeNumber[1];
			break;
		}
	}
	printf("컴퓨터가 지울 숫자 : %d\n", _removeNumber[1]);
	system("pause");
}

void RemoveBingoNumber()
{
	//player's Bingo
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_myBingo[i] == _removeNumber[j])
			{
				_myBingo[i] = -1;
			}
		}
	}

	//computer's Bingo
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_comBingo[i] == _removeNumber[j])
			{
				_comBingo[i] = -1;
			}
		}
	}
}

void CheckBingoCount()
{
	// 0, 1, 2, 3, 4가 -1 이면 빙고
	// ...
	// 20, 21, 22, 23, 24가 -1 이면 빙고
	_bingoCount[0] = 0;
	_bingoCount[1] = 0;
	if (_myBingo[0] == -1 && _myBingo[1] == -1 && _myBingo[2] == -1 && _myBingo[3] == -1 && _myBingo[4] == -1)
	{
		_bingoCount[0]++;
	}
	if (_myBingo[5] == -1 && _myBingo[6] == -1 && _myBingo[7] == -1 && _myBingo[8] == -1 && _myBingo[9] == -1)
	{
		_bingoCount[0]++;
	}
	if (_myBingo[10] == -1 && _myBingo[11] == -1 && _myBingo[12] == -1 && _myBingo[13] == -1 && _myBingo[14] == -1)
	{
		_bingoCount[0]++;
	}
	if (_myBingo[15] == -1 && _myBingo[16] == -1 && _myBingo[17] == -1 && _myBingo[18] == -1 && _myBingo[19] == -1)
	{
		_bingoCount[0]++;
	}
	if (_myBingo[20] == -1 && _myBingo[21] == -1 && _myBingo[22] == -1 && _myBingo[23] == -1 && _myBingo[24] == -1)
	{
		_bingoCount[0]++;
	}
	

	if (_myBingo[0] == -1 && _myBingo[5] == -1 && _myBingo[10] == -1 && _myBingo[15] == -1 && _myBingo[20] == -1)
	{
		_bingoCount[0]++;
	}
	if (_myBingo[1] == -1 && _myBingo[6] == -1 && _myBingo[11] == -1 && _myBingo[16] == -1 && _myBingo[21] == -1)
	{
		_bingoCount[0]++;
	}
	//귀찮아서 포기..
	// 대각선 추가
}