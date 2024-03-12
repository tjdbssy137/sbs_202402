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
	srand(time(NULL));
	while (0 < _money)
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
{//���� Ʋ���� ��.->srand(time(NULL));�� �� �Ἥ ����.
	_playerCard.push_back(_card[_order].Index);
	_order++;
	_computerCard.push_back(_card[_order].Index);
	_order++;
}

void CardGame::Betting()
{
	cout << "���� ���� �ݾ� : " << _money << endl;
	cout << "�ǵ��� �ż��� : ";
	cin >> _betMoney;
}

int CardGame::CardPedigree(vector<int> arr)
{
	int _first = arr[0];
	int _second = arr[1];
	cout << _first << ", " << _second << endl;
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

	_first = _first % 10 + 1;
	_second = _second % 10 + 1;

	cout << _first << ", " << _second << endl;
	if (_first == _second) // �嶯, cardGame���� com�� player ���� ũ�� �Ǻ� �ʿ�. -> �ʹ� ���ŷӴ�
	{
		return 3;
	}
	else if ((_first == 1 && _second == 2) || (_first == 2 && _second == 1))//�˸�(1,2)
	{
		return 4;
	}
	else if ((_first == 1 && _second == 4) || (_first == 4 && _second == 1))//����(1, 4)
	{
		return 5;
	}
	else if ((_first == 1 && _second == 9) || (_first == 9 && _second == 1))//����(1, 9)
	{
		return 6;
	}
	else if ((_first == 10 && _second == 1) || (_first == 1 && _second == 10))//���(10, 1)
	{
		return 7;
	}
	else if ((_first == 10 && _second == 4) || (_first == 4 && _second == 10))//���(10, 4)
	{
		return 8;
	}
	else if ((_first == 4 && _second == 6) || (_first == 6 && _second == 4))//����(4, 6)
	{
		return 9;
	}
	else if ((_first + _second == 9 && _first < 9 && _second < 9)
		|| (_first + _second == 19))//����(�� �� �� 9, 19)
	{
		return 10;
	}
	else if (_first + _second == 0)//����(�� �� �� 10)
	{
		return 12;
	}
	else //8��~1��
	{
		return 11;
	}
	//Ư�� ���� ����.
}

void CardGame::Result()
{
	cout << "Player�� ���� ī��� ";
	_card[0].Print();
	//cout << _card[0].Index << " " << _playerCard[0] << endl;
	cout << ", ";
	_card[2].Print();
	//cout << _card[2].Index << " " << _playerCard[1] << endl;
	cout << "�Դϴ�." << endl;
	
	cout << "Computer�� ���� ī��� ";
	_card[1].Print();
	//cout << _card[1].Index << " " << _computerCard[0] << endl;
	cout << ", ";
	//cout << _card[3].Index << " " << _computerCard[1] << endl;
	_card[3].Print();
	cout << "�Դϴ�." << endl;

	int _playerScore = CardPedigree(_playerCard);
	int _computerScore = CardPedigree(_computerCard);
	//cout << "_playerScore : " << _playerScore << endl;
	//cout << "_computerScore : " << _computerScore << endl;
	if (_playerScore < _computerScore)
	{
		cout << "Player�� �¸��Դϴ�." << endl;
		_money += _betMoney * 2;
	}
	else
	{
		cout << "Player�� �й��Դϴ�." << endl;
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