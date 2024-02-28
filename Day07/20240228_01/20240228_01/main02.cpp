#include <iostream>
using namespace std;
#define HAND_MAX 2
#define KIND_OF_HAND 3

//enum ����
enum eRSP 
{
	RSP_SCISSOR,
	RSP_ROCK,
	RSP_PAPER,

	RSP_END // array�� for���� ����� �� ������� ����ϱ� ���ϴ�.
};

enum eHandName
{
	HAND_LEFT,
	HAND_RIGHT,

	HAND_END // array�� for���� ����� �� ������� ����ϱ� ���ϴ�.
};

// �Լ� ���� ����
void chooseMyHand();
void chooseComHand();
void PrintHands();
void ChooseFinalMyHands();
void ChooseFinalComHand();
void PrintResult();
void PrintHand(int);

// 0�� 1 �ܿ��� ��� define�̳� ����� �������ִ� ���� ����.
int _myHand[HAND_MAX] = {};
int _comHand[HAND_MAX] = {};
int _myFinalHand = 0;
int _comFinalHand = 0;
string _KindOfHand[KIND_OF_HAND] = {"����", "����", "��"};

void main()
{
	srand(time(NULL));
	chooseMyHand();
	chooseComHand();
	PrintHands();
	ChooseFinalMyHands();
	ChooseFinalComHand();
	PrintResult();

	// ���������� �ϳ� ����
	// �Լ� �޳��� ��� ���

	// ���������� �ϳ� ���� �����ڵ�
	// 1. ���� �� �� �� ���� ���Ѵ�.
	// chooseMyHand()
	// 2. ���(��ǻ��)�� �� �� �ΰ��� ���Ѵ�.
	// -> �̶� ��밡 �� ���� rand() % 3
	// chooseComHand()
	// 3. ���� �� �Ͱ� ��밡 �� ���� �����ش�
	// PrintHands()
	// 4. ���� ���������� �� ���� ����
	// ChooseFinalMyHands()
	// 5. ��밡 ���������� �� ���� ����
	// ChooseFinalComHand()
	// 6. ���� �񱳸� �Ѵ�.
	// PrintResult()

	// �����ڵ� ���Ǵ����� �Լ��� ¥�� ���� ����.
	// -> ������ ���鿡�� ��.
}

void chooseMyHand()
{
	// �� �� �ΰ��� �����ش�.
	cout << "���� ���� �����ּ��� ����(0) ����(1) ��(2) >> ";
	cin >> _myHand[HAND_LEFT];
	cout << "������ ���� �����ּ��� ����(0) ����(1) ��(2) >> ";
	cin >> _myHand[HAND_RIGHT];
}
void chooseComHand()
{
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END;
	}
}
void PrintHands()
{
	cout << "���� �� ���� " << endl;
	PrintHand(_myHand[HAND_LEFT]);
	PrintHand(_myHand[HAND_RIGHT]);
	cout << "�̰�," << endl;
	cout << "��ǻ�Ͱ� �� ���� " << endl;
	PrintHand(_comHand[HAND_LEFT]);
	PrintHand(_comHand[HAND_RIGHT]);
	cout << "�̴�." << endl;

	//cout << "���� �� ���� " << _KindOfHand[_myHand[HAND_LEFT]] << "�� " << _KindOfHand[_myHand[HAND_RIGHT]] << endl;
	//cout << "��ǻ�Ͱ� �� ���� " << _KindOfHand[_comHand[HAND_LEFT]] << "�� " << _KindOfHand[_comHand[HAND_RIGHT]] << endl;
}
void ChooseFinalMyHands()
{
	while (1)
	{
		cout << "���� ������ �޼�(0) ������(1) >> ";
		cin >> _myFinalHand;
		if ((_myFinalHand == 0) || (_myFinalHand == 1)) break;
	}
	switch (_myFinalHand)
	{
	case HAND_LEFT:
		_myFinalHand = _myHand[HAND_LEFT];
		break;
	case HAND_RIGHT:
		_myFinalHand = _myHand[HAND_RIGHT];
		break;
	}
}
void ChooseFinalComHand()
{
	_comFinalHand = rand() % HAND_MAX;
	switch (_comFinalHand)
	{
	case HAND_LEFT:
		_comFinalHand = _comHand[HAND_LEFT];
		break;
	case HAND_RIGHT:
		_comFinalHand = _comHand[HAND_RIGHT];
		break;
	}
}
void PrintResult()
{
	cout << "���� ���������� ������ ����  >> " << _KindOfHand[_myFinalHand] << endl;
	cout << "��ǻ�Ͱ� ���������� ������ ���� >> " << _KindOfHand[_comFinalHand] << endl;

	if (_KindOfHand[_myFinalHand] == _KindOfHand[_comFinalHand])
	{
		cout << "�����ϴ�.";
	}
	else if (_KindOfHand[_myFinalHand] == _KindOfHand[0]) // ����
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[1]) // ����
		{
			cout << "�й��Ͽ����ϴ�";
		}
		else if(_KindOfHand[_comFinalHand] == _KindOfHand[2])// ��
		{
			cout << "�¸��Ͽ����ϴ�.";
		}
	} else if(_KindOfHand[_myFinalHand] == _KindOfHand[1]) // ����
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[0]) // ����
		{
			cout << "�¸��Ͽ����ϴ�.";
		}
		else if (_KindOfHand[_comFinalHand] == _KindOfHand[2]) // ��
		{
			cout << "�й��Ͽ����ϴ�";
		}
	}
	else // ��
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[0]) // ����
		{
			cout << "�й��Ͽ����ϴ�";
		}
		else if (_KindOfHand[_comFinalHand] == _KindOfHand[1]) // ����
		{
			cout << "�¸��Ͽ����ϴ�.";
		}
	}
}
void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_SCISSOR:
		cout << "����" << endl;
		break;
	case RSP_ROCK:
		cout << "����" << endl;
		break;
	case RSP_PAPER:
		cout << "��" << endl;
		break;
	default:
		cout << "�ƹ��͵� �ƴ�" << endl;
		break;
	}
};