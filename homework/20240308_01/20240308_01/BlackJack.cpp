#include "BlackJack.h"
#include <iostream>

// 1) ����
// 
// 1. �÷��̾ 1000���� ���� ����
// 2. Ʈ���� ī�� 52���� ����
// 3. ������ �Ѵ�
// 4. ����ī�� 2��, �÷��̾� ī�� 2���� �޴´�
// [5]. �÷��̾ ī�带 �� ���� �� �����Ѵ�
// 6. �÷��̾��� ī�� ���� ���� 21�� �ѱ�� �й� (j,q,k�� 10���� ���), �׸��� A�� 11�� 1 �߿� ���ϴ� ������ ���
// 7. �÷��̾��� ī�� ���� ���� 21�� �ѱ��� ������ [5]���� �ݺ� 
//			-> 21�� �ѱ��� �ʴ� �ѿ��� ī�� �ޱ�(ī�� ������ ��� ����)
// 8. �÷��̾ �׸� �ޱ⸦ �����ϸ�
// 9. ������ �÷��̾��� �����պ��� ������ ������ ī�带 �޴´�
// 10. ������ �й����� �ʰ� (�������� 21�ʰ�), �÷��̾��� �����պ��� Ŀ���� ������ �¸�
//			-> ������ �÷��̾��� ī������ ������, ī�� ���� ���� ���� �¸�.
// 11. �÷��̾ �Ļ����� �ʾ�����, ī�带 ���� �ʰ� �� ���� ī����� ��� �ݺ�
// 12. ī�带 ��� ����Ͽ�����, �� �����Ǻ��ʹ� ī�带 ���� ����
int _money = 1000;

BlackJack::BlackJack()
{
	srand(time(NULL));
	CardSetting();
	while (false == (_money <= 0))
	{
		cout << "==============================" << endl;
		Organize();
		if (_order + 1 == CARD_MAX)
		{
			cout << "ī�带 ��� �����Ͽ�, �ٽ� ���ڽ��ϴ�." << endl;
			_order = 0;
			CardSetting();
		}
		BettingMoney();
		ReceivePlayerCard();
		if (_playerCardSum <= CARD_SUM)
		{
			ReceiveComputerCard();
			Result();
		}
	}
}
void BlackJack::CardSetting()
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
void BlackJack::BettingMoney()
{
	cout << "�����Ͻ� �ݾ��� �Է����ּ���." << endl;
	cout << "���� ���� �ݾ� : " << _money << "��" << endl;
	cin >> _bettingMoney;
}
void BlackJack::ReceivePlayerCard()
{
	cout << "<Player�� �����Դϴ�>" << endl;
	cout << "ī�� �� ���� �޽��ϴ�." << endl;
	int _size = _order;
	for (_order; _order < _size + 2; _order++)
	{
		_playerCard.push_back(_card[_order].Index);
		if (_card[_order].Index % 13 + 1 == 1)
		{
			int _choose = 0;
			_card[_order].Print();
			cout << "ī�带 �޾ҽ��ϴ�. \n1�� ���ϰ� ���� ��쿣 '0', 11�� ���ϰ� ���� ��쿣 '1'�� �������ּ���." << endl;
			cin >> _choose;
			if (_choose == 0)
			{
				_playerCardSum += 1;
			}
			else if (_choose == 1)
			{
				_playerCardSum += 11;
			}
		}
		else if ((11 <= _card[_order].Index % 13 + 1) && (_card[_order].Index % 13 + 1 <= 13))
		{
			_playerCardSum += 10;
		}
		else
		{
			_playerCardSum += _card[_order].Index % 13 + 1;
		}
	}
	int _input = 0;
	for (_order; _order < CARD_MAX; _order++)
	{
		cout << "\nPlayer�� ī�� ���� " << _playerCardSum  << "�Դϴ�." << endl;
		cout << "�߰� ī�带 ��� �������� '0' �ƴ� ��� '1'�� �������ּ���." << endl;
		cin >> _input;
		if (_input == 0)
		{
			cout << "Player�� ���� ī��� ";
			_card[_order].Print();
			_playerCard.push_back(_card[_order].Index);
			if (_card[_order].Index % 13 + 1 == 1)
			{
				int _choose = 0;
				_card[_order].Print();
				cout << "ī�带 �޾ҽ��ϴ�. \n1�� ���ϰ� ���� ��쿣 '0', 11�� ���ϰ� ���� ��쿣 '1'�� �������ּ���." << endl;
				cin >> _choose;
				if (_choose == 0)
				{
					_playerCardSum += 1;
				}
				else if (_choose == 1)
				{
					_playerCardSum += 11;
				}
			}
			else if ((11 <= _card[_order].Index % 13 + 1) && (_card[_order].Index % 13 + 1 <= 13))
			{
				_playerCardSum += 10;
			}
			else 
			{
				_playerCardSum += _card[_order].Index % 13 + 1;
			}


			if (CARD_SUM < _playerCardSum)
			{
				cout << "\nPlayer�� ī�� ���� " << _playerCardSum << "�Դϴ�." << endl;
				Result();
				break;
			}
		}
		else if(_input == 1)
		{
			break;
		}
	}
}
void BlackJack::ReceiveComputerCard()
{
	cout << "\n\n<Com�� �����Դϴ�>" << endl;
	int _size = _order; 
	for (_order; _order < _size + 2; _order++)
	{
		_computerCard.push_back(_card[_order].Index);
		if (_card[_order].Index % 13 + 1 == 1)
		{
			_computerCardSum += 11;
		}
		else if ((11 <= _card[_order].Index % 13 + 1) && (_card[_order].Index % 13 + 1 <= 13))
		{
			_computerCardSum += 10;
		}
		else
		{
			_computerCardSum += _card[_order].Index % 13 + 1;
		}
	}
	
	for (_order; _order < CARD_MAX; _order++)
	{
		_computerCard.push_back(_card[_order].Index);
		if (_card[_order].Index % 13 + 1 == 1)
		{
			if (_computerCardSum + 11 <= CARD_SUM)
			{
				_computerCardSum += 11;
			}
			else
			{
				_computerCardSum += 1;
			}
		}
		else if ((11 <= _card[_order].Index % 13 + 1) && (_card[_order].Index % 13 + 1 <= 13))
		{
			_computerCardSum += 10;
		}
		else
		{
			_computerCardSum += _card[_order].Index % 13 + 1;
		}

		if (CARD_SUM <= _computerCardSum)
		{
			cout << "\nCom�� ī�� ���� " << _computerCardSum << "�Դϴ�." << endl;
			break;
		}
	}
}
void BlackJack::Result()
{
	cout << endl;
	int _result = 0;
	if (_playerCardSum <= CARD_SUM && _computerCardSum <= CARD_SUM)
	{
		_playerCardSum < _computerCardSum ? _result = 0 : _result = 1;
	}
	else if (_playerCardSum == _computerCardSum)
	{
		_playerCard.size() < _computerCard.size() ? _result = 1 : _result = 0;
	}
	else if (CARD_SUM < _playerCardSum)
	{
		_result = 0;
	}
	else if (CARD_SUM < _computerCardSum)
	{
		_result = 1;
	}

	switch (_result)
	{
	case 0:
		cout << "Com�� �¸��Դϴ�." << endl;
		_money -= _bettingMoney;
		break;
	case 1:
		cout << "Player�� �¸��Դϴ�." << endl;
		_money += _bettingMoney * 2;
		break;
	}
	cout << endl;
}

void BlackJack::Organize()
{
	_playerCard.clear();
	_computerCard.clear();
	_playerCardSum = 0;
	_computerCardSum = 0;
}
BlackJack::~BlackJack()
{
	cout << "�����Ҵ� ����" << endl;
}