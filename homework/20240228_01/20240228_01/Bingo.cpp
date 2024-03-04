#include <iostream>
using namespace std;
#define BINGO 3
#define BINGO_SIZE 5
#define BINGO_LENGTH 25

int MyBingoCount = 0, ComBingoCount = 0;
int _myBingo[BINGO_SIZE][BINGO_SIZE] = { };
int _comBingo[BINGO_SIZE][BINGO_SIZE] = { };
int _input = 0;
int _usedNumber[BINGO_LENGTH] = { 0, };

// 실습 (vs Computer)
// 5*5 빙고판
// 1~25까지 랜덤한 숫자가 적혀있음

// 내가 한 번 숫자를 입력하면
// 내 빙고판에서 숫자 하나 지워지고
// 상대 빙고판에서 숫자 하나 지워짐

// 그 다음에 상대가 랜덤으로 숫자를 하나 입력함
// 내 빙고판에서 숫자 하나 지워지고
// 상대 빙고판에서 숫자 하나 지워짐

// 세 줄이 빙고가 되면 해당 유저 승리

// +
// 함수 이름 더 직관적으로 짓기
// 한 줄 빙고 일 때마다 알림.(가능하다면)

void RandomBingo(int arr[][BINGO_SIZE]); //size값을 따로 보내줘야함. 2차원이기 때문에 행렬 둘 다.
void InputMyNumber();
void InputComNumber();
void RemoveNumber(int arr[][BINGO_SIZE]);
int Bingo(int arr[][BINGO_SIZE]);
void PrintBingo(int arr[][BINGO_SIZE]);

void main()
{
	srand(time(NULL));

	RandomBingo(_myBingo);
	RandomBingo(_comBingo);

	while (1)
	{
		cout << "<나의 빙고>" << endl;
		PrintBingo(_myBingo);
		cout << "<컴퓨터의 빙고>" << endl;
		PrintBingo(_comBingo);
		
		InputMyNumber();
		RemoveNumber(_myBingo);
		RemoveNumber(_comBingo);
		MyBingoCount = Bingo(_myBingo);
		ComBingoCount = Bingo(_comBingo);
		
		if (MyBingoCount == BINGO)
		{
			cout << "나의 승리" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == BINGO)
		{
			cout << "컴퓨터의 승리" << endl;
			PrintBingo(_comBingo);
			break;
		}
		
		InputComNumber();
		RemoveNumber(_myBingo);
		RemoveNumber(_comBingo);
		MyBingoCount = Bingo(_myBingo);
		ComBingoCount = Bingo(_comBingo);

		if (MyBingoCount == BINGO)
		{
			cout << "나의 승리" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == BINGO)
		{
			cout << "컴퓨터의 승리" << endl;
			PrintBingo(_comBingo);
			break;
		}
	}
}
void RandomBingo(int arr[][BINGO_SIZE])
{
	int saveNumber[BINGO_LENGTH] = { 0, };
	for (int i = 0; i < BINGO_LENGTH; i++)
	{
		saveNumber[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int firstIndex = rand() % BINGO_LENGTH;
		int secondIndex = rand() % BINGO_LENGTH;

		int temp = saveNumber[firstIndex];
		saveNumber[firstIndex] = saveNumber[secondIndex];
		saveNumber[secondIndex] = temp;
	}
	int k = 0;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			arr[i][j] = saveNumber[k];
			k++;
		}
	}
}
void InputMyNumber()
{
	cout << "지울 숫자를 입력하세요 : ";
	cin >> _input;
	if (_usedNumber[_input - 1] == NULL)
	{
		_usedNumber[_input - 1] = _input;
	}
}
void InputComNumber()
{
	cout << "컴퓨터의 선택 : ";
	while (1)
	{
		_input = rand() % BINGO_LENGTH + 1;
		if (_usedNumber[_input - 1] == NULL)
		{
			_usedNumber[_input - 1] = _input;
			cout << _input;
			break;
		}
	}
	printf("\n\n");
}
void RemoveNumber(int arr[][BINGO_SIZE])
{
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (_input == arr[i][j])
			{
				arr[i][j] = 0;
			}
		}
	}
}
int Bingo(int arr[][BINGO_SIZE])
{
	int elementCount = 0;
	int lineCount = 0;

	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				elementCount++;
			}
			else
			{
				elementCount = 0;
			}
			if (elementCount == BINGO_SIZE)
			{
				lineCount++;
				elementCount = 0;
			}
		}
	}
	
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (arr[j][i] == 0)
			{
				elementCount++;
			}
			else
			{
				elementCount = 0;
			}
			if (elementCount == BINGO_SIZE)
			{
				lineCount++;
				elementCount = 0;
			}
		}
	}
	
	/*
	가로 빙고
	00 11 22 33 44
	04 13 22 31 40
	*/	
	if (arr[0][0] == 0 && arr[1][1] == 0 && arr[2][2] == 0 && arr[3][3] == 0 && arr[4][4] == 0)
	{
		lineCount++;
	}
	if (arr[0][4] == 0 && arr[1][3] == 0 && arr[2][2] == 0 && arr[3][1] == 0 && arr[4][0] == 0)
	{
		lineCount++;
	}

	if (BINGO == lineCount)
	{
		return 3;
	}
}
void PrintBingo(int arr[][BINGO_SIZE])
{
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				printf("%2c ", 'X');
			}
			else
			{
				printf("%2d ", arr[i][j]);
			}
			//cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}