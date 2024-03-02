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

// �ǽ� (vs Computer)
// 5*5 ������
// 1~25���� ������ ���ڰ� ��������

// ���� �� �� ���ڸ� �Է��ϸ�
// �� �����ǿ��� ���� �ϳ� ��������
// ��� �����ǿ��� ���� �ϳ� ������

// �� ������ ��밡 �������� ���ڸ� �ϳ� �Է���
// �� �����ǿ��� ���� �ϳ� ��������
// ��� �����ǿ��� ���� �ϳ� ������

// �� ���� ���� �Ǹ� �ش� ���� �¸�

void RandomBingo(int arr[][BINGO_SIZE]);
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
		cout << "<���� ����>" << endl;
		PrintBingo(_myBingo);
		cout << "<��ǻ���� ����>" << endl;
		PrintBingo(_comBingo);
		
		InputMyNumber();
		RemoveNumber(_myBingo);
		RemoveNumber(_comBingo);
		MyBingoCount = Bingo(_myBingo);
		ComBingoCount = Bingo(_comBingo);
		
		if (MyBingoCount == 3)
		{
			cout << "���� �¸�" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == 3)
		{
			cout << "��ǻ���� �¸�" << endl;
			PrintBingo(_comBingo);
			break;
		}
		
		InputComNumber();
		RemoveNumber(_myBingo);
		RemoveNumber(_comBingo);
		MyBingoCount = Bingo(_myBingo);
		ComBingoCount = Bingo(_comBingo);

		if (MyBingoCount == 3)
		{
			cout << "���� �¸�" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == 3)
		{
			cout << "��ǻ���� �¸�" << endl;
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
		int firstIndex = rand() % 25;
		int secondIndex = rand() % 25;

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
	cout << "���� ���ڸ� �Է��ϼ��� : ";
	cin >> _input;
	if (_usedNumber[_input - 1] == NULL)
	{
		_usedNumber[_input - 1] = _input;
	}
}
void InputComNumber()
{
	cout << "��ǻ���� ���� : ";
	while (1)
	{
		_input = rand() % 25 + 1;
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
			if (elementCount == 5)
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
			if (elementCount == 5)
			{
				lineCount++;
				elementCount = 0;
			}
		}
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
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}