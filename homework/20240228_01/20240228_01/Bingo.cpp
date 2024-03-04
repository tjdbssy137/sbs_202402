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

// +
// �Լ� �̸� �� ���������� ����
// �� �� ���� �� ������ �˸�.(�����ϴٸ�)

void RandomBingo(int arr[][BINGO_SIZE]); //size���� ���� ���������. 2�����̱� ������ ��� �� ��.
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
		
		if (MyBingoCount == BINGO)
		{
			cout << "���� �¸�" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == BINGO)
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

		if (MyBingoCount == BINGO)
		{
			cout << "���� �¸�" << endl;
			PrintBingo(_myBingo);
			break;
		}
		else if (ComBingoCount == BINGO)
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
	���� ����
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