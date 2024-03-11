#include "CardGame.h"
// 2) ����
// 
// 1. �÷��̾ 1000���� ���� �����Ѵ�
// 2. ȭ��ī�� 20���� ���´�
// 3. ������ �Ѵ�. (�÷��̾ ������ �� �ְ� ���� ������ ��)
// 4. �÷��̾� 1��, ������� 1���� �ش�
// 5. ������ �Ѵ�(0�� ����)
// 6. �÷��̾����� 1�� ������µ� 1���� �ش�
// 7. ������ �� ���� ���� �¸�(������ ���ͳ� ����), (���� ����� ������ ���� ����)
// 8. �÷��̾ 0���� �Ǹ� ���� ����
// 9. ���� 20���� ���Ӱ� ���´�.

CardGame::CardGame()
{
	while (0 <= _money)
	{
		CardSetting();
		ReceiveCard();
		Betting();
		ReceiveCard();
		Result();
	}
}
void CardGame::CardSetting()
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		_card[i].Index = i;
	}
	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % CARD_MAX;
		int dst = rand() % CARD_MAX;

		_card[src].Swap(_card[dst]);
	}
}
void CardGame::ReceiveCard()
{
	_playerCard.push_back(_card[_order++].Index);
	_computerCard.push_back(_card[_order++].Index);
}
void CardGame::Betting()
{
	cout << "�ǵ��� �ż���." << endl;
	cin >> _betMoney;
}

int CardGame::CardPedigree(vector<int> _cards)
{
	int _first = _cards[0];
	int _second = _cards[1];

	if ((_first == 2 && _second == 7) || (_first == 7 && _second == 2))//���ȱ���
	{
		return 0;
	}
	else if ((_first == 0 && _second == 7) || (_first == 7 && _second == 0))//���ȱ���
	{
		return 1;
	}
	else if ((_first == 0 && _second == 2) || (_first == 2 && _second == 0))//�ϻﱤ��
	{
		return 2;
	}
	else if (abs(_first - _second) == 10) // �嶯, cardGame���� com�� player ���� ũ�� �Ǻ� �ʿ�.
	{
		return 3;
	}

	if (9 < _first)
	{
		_first -= 10;
	}
	if (9 < _second)
	{
		_second -= 10;
	}

	if ((_first == 0 && _second == 1) || (_first == 1 && _second == 0))//�˸�(1,2)
	{
		return 4;
	}
	else if ((_first == 0 && _second == 3) || (_first == 3 && _second == 0))//����(1, 4)
	{
		return 5;
	}
	else if ((_first == 0 && _second == 8) || (_first == 8 && _second == 0))//����(1, 9)
	{
		return 6;
	}
	else if ((_first == 0 && _second == 9) || (_first == 9 && _second == 0))//���(10, 1)
	{
		return 7;
	}
	else if ((_first == 9 && _second == 3) || (_first == 3 && _second == 9))//���(10, 4)
	{
		return 8;
	}
	else if ((_first == 5 && _second == 3) || (_first == 3 && _second == 5))//����(4, 6)
	{
		return 9;
	}
	else if ((_first + _second == 9 && _first < 8 && _second < 8)
		|| (_first + _second == 17))//����(�� �� �� 9, 19)
	{
		return 10;
	}
	else if (_first + _second == 8)//����(�� �� �� 10)
	{
		return 12;
	}
	else //8��~1��
	{
		return 11;
	}
}

void CardGame::Result()
{
	cout << "Player�� ���� ī��� ";
	_card[_playerCard[0]].Print();
	cout << ", ";
	_card[_playerCard[1]].Print();
	cout << "�Դϴ�." << endl;
	
	cout << "Computer�� ���� ī��� ";
	_card[_computerCard[0]].Print();
	cout << ", ";
	_card[_computerCard[1]].Print();
	cout << "�Դϴ�." << endl;

	int _playerScore = CardPedigree(_playerCard);
	int _computerScore = CardPedigree(_computerCard);
	if (_playerScore < _computerScore)
	{
		cout << "Player�� �¸��Դϴ�.";
		_money += _betMoney * 2;
	}
	else
	{
		cout << "Player�� �й��Դϴ�.";
		_money -= _betMoney;
	}
	_order = 0;
	_playerCard.clear();
	_computerCard.clear();
}
CardGame::~CardGame()
{
	cout << "�����Ҵ� ����" << endl;
}