#include <iostream>
#include <vector>
using namespace std;
// ����
// ���� ī�带 5�� �̴µ�.(ī��� �� ���� ����)
// �� ���� ����
// �� ���� XX�� ǥ��

//������
// ��3 ��4 ��2 ��A XX 
// �÷��̾� ���� �ݾ� : 1000��

// ���� ���� ����(�ݾ� ����)
// ���ý� - ����, �ο�, ���� �߿��� ����
// ���̸� �� ��
// XX�� ���� 7�̻��̸� ����Ʈ ȹ�� (�� ���� 2��)
// �ο츦 �� ��
// XX�� ���� 7���ϸ� ����Ʈ ȹ�� (�� ���� 2��)
// ������ ����
// XX�� ���� 7�̸� ����Ʈ ȹ�� (�� ���� 10��)

// �� ���� �ϸ� �������� �� �徿 �и�.
// ��3 ��4 ��2 ��A XX -> ��4 ��2 ��A ��7 XX (���ο� XX�� �����ǰ� �� ù���� �����, �ߺ� �Ұ�)  
// 52���� �� ���ų�, �÷��̾��� �ݾ��� 0���� �Ǹ� ���� ����.
struct Card {
	int Index;
	void cPrint();
	void cSwap(Card& another);
};

struct Player {
	int Bet = 0;
	int Money = 1000;
};

enum RESULT{
	_High,
	_Low,
	_Seven,

	_ResultEnd
};

// ����
Card _card[52] = {};
Player _player = {};
vector<int> _displayBoard;
int _order = 0;
int _battingMoney = 0;


// �Լ�
void PrintCards();
void ExpectCard();
void CalculateMoney();

void main()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
	}

	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % 52;
		int dst = rand() % 52;

		_card[src].cSwap(_card[dst]);
	}

	while ((_displayBoard.size() < 52) || (0 < _player.Money))
	{
		PrintCards();
		ExpectCard();
		CalculateMoney();
	}

	for (int i = 0; i < 52; i++)
	{
		_card[i].cPrint();
		cout << endl;
	}
}

void Card::cPrint()
{
	switch (Index / 13)
	{
	case 0:
		cout << "��";
		break;
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	}
	switch (Index % 13 + 1)
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		printf("%d", Index % 13 + 1);
		break;
	}
	cout << " ";
}
void Card::cSwap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}
void PrintCards()
{
	int temp = _order;
	for (_order; _displayBoard.size() <= 4; _order++)
	{
		if (_order == 52)
		{
			break;
		}
		if (_displayBoard.size() < 4)
		{
			_card[_order].cPrint();
		}
		else
		{
			cout << "XX" << endl;
			break;
		}
	}
	cout << endl;
}
void ExpectCard()
{
	cout << "����(0) / �ο�(1) / ����(2)" << endl;
	cout << "**���̴� 2��, �ο�� 2��, ������ 10���Դϴ�.**" << endl;
	cin >> _player.Bet;
	cout << "�����Ͻ� �ݾ��� �Է����ּ���." << endl;
	cout << "���� ���� �ݾ� : " << _player.Money << "��" << endl;
	cin >> _battingMoney;
}
void CalculateMoney()
{
	if (_card[_order].Index < 7)
	{
		if (_High == _player.Bet)
		{
			_player.Money += (_battingMoney * 2);
			cout << "�����մϴ�. " << _battingMoney * 2 << "���� �����̽��ϴ�!" << endl;
		}
		else
		{
			_player.Money -= (_battingMoney * 2);
			if (_player.Money < 0)
			{
				cout << _battingMoney * 2 << "���� �����̽��ϴ�! ���� �ݾ��� " << _player.Money << "�� �Ļ��ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << _battingMoney * 2 << "���� �����̽��ϴ�!" << endl;
			}
		}
	}
	else if (7 < _card[_order].Index)
	{
		if (_Low == _player.Bet)
		{
			_player.Money += (_battingMoney * 2);
			cout << "�����մϴ�. " << _battingMoney * 2 << "���� �����̽��ϴ�!" << endl;
		}
		else
		{
			_player.Money -= (_battingMoney * 2); 
			if (_player.Money < 0)
			{
				cout << _battingMoney * 2 << "���� �����̽��ϴ�! ���� �ݾ��� " << _player.Money << "�� �Ļ��ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << _battingMoney * 2 << "���� �����̽��ϴ�!" << endl;
			}
		}
	}
	else
	{
		if (_Seven == _player.Bet)
		{
			_player.Money += (_battingMoney * 10);
			cout << "�����մϴ�. " << _battingMoney * 10 << "���� �����̽��ϴ�!" << endl;
		}
		else
		{
			_player.Money -= (_battingMoney * 10);
			if (_player.Money < 0)
			{
				cout << _battingMoney * 10 << "���� �����̽��ϴ�! ���� �ݾ��� " << _player.Money << "�� �Ļ��ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << _battingMoney * 10 << "���� �����̽��ϴ�!" << endl;
			}
		}
	}
	_displayBoard.erase(_displayBoard.begin());
}