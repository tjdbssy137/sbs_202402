#include <iostream>
#include <Windows.h>
using namespace std;

int _myBingo[5 * 5] = {};
int _comBingo[5 * 5] = {};
// index0 ~ index4 => 1��
// ...
// index20 ~ index24 => 5��

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
	���� ��
	- 1. �� ������ 5X5�� �����
		- 1���� 25�� ���ڰ� �������� ����.
	- 2. ��ǻ�� ������ 5X5�� �����
		- 1���� 25�� ���ڰ� �������� ����.
	- 3. �������� ����Ѵ�.
	- 4. �÷��̿� ��ǻ�Ͱ� ���ڸ� �Է��Ѵ�.
	- 5. �Է��� ���ڰ� Xǥ�ð� �ȴ�.
		- myBingo[] = {1~25}
		- �̹� ����� ���ڴ� -1�� ǥ�� �� ����� �� X�� ǥ��.
	- 6. 3 ~ 5 ���� �ݺ�
	- 7. 3���� �Ǹ� �ش� ���� �¸�.
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
			printf("�¸��߽��ϴ�.");
			break; // ���� ����� �ݺ��� ����.
			return; // return�� �����ϰ� �ִ� �Լ��� ����
			exit(1); // program ����
		}
		if (_bingoCount[0] == 3)
		{
			printf("�й��߽��ϴ�.");
			break; // ���� ����� �ݺ��� ����.
			return; // return�� �����ϰ� �ִ� �Լ��� ����
			exit(1); // program ����
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
	cout << "�� ���� ��" << endl;
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
	cout << "\n��ǻ�� ���� ��" << endl;
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
	cout << "\n���� ���� ���� : ";
	do
	{
		cin >> _removeNumber[0];
	} while (false == (1 <= _removeNumber[0] && _removeNumber[1] <= 25));
	_removeNumber[1] = rand() % 25 + 1;
	printf("���� ���� ���� : %d\n", _removeNumber[0]);
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
	printf("��ǻ�Ͱ� ���� ���� : %d\n", _removeNumber[1]);
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
	// 0, 1, 2, 3, 4�� -1 �̸� ����
	// ...
	// 20, 21, 22, 23, 24�� -1 �̸� ����
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
	//�����Ƽ� ����..
	// �밢�� �߰�
}