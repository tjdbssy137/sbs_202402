#include "BlackJack.h"
#include <iostream>

// 1) 블랙잭
// 
// 1. 플레이어가 1000원을 갖고 시작
// 2. 트럼프 카드 52장을 섞음
// 3. 배팅을 한다
// 4. 딜러카드 2장, 플레이어 카드 2장을 받는다
// [5]. 플레이어가 카드를 더 받을 지 선택한다
// 6. 플레이어의 카드 숫자 합이 21을 넘기면 패배 (j,q,k는 10으로 계산), 그리고 A는 11과 1 중에 원하는 것으로 계산
// 7. 플레이어의 카드 숫자 합이 21을 넘기지 않으면 [5]번을 반복 
//			-> 21을 넘기지 않는 한에서 카드 받기(카드 개수는 상관 없음)
// 8. 플레이어가 그만 받기를 선택하면
// 9. 딜러가 플레이어의 숫자합보다 높아질 때까지 카드를 받는다
// 10. 딜러가 패배하지 않고 (숫자합이 21초과), 플레이어의 숫자합보다 커지면 딜러가 승리
//			-> 딜러와 플레이어의 카드합이 같으면, 카드 수가 적은 편이 승리.
// 11. 플레이어가 파산하지 않았으면, 카드를 섞지 않고 그 다음 카드부터 계속 반복
// 12. 카드를 모두 사용하였으면, 그 다음판부터는 카드를 새로 셔플
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
			cout << "카드를 모두 소진하여, 다시 섞겠습니다." << endl;
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
	cout << "배팅하실 금액을 입력해주세요." << endl;
	cout << "현재 보유 금액 : " << _money << "원" << endl;
	cin >> _bettingMoney;
}
void BlackJack::ReceivePlayerCard()
{
	cout << "<Player의 차례입니다>" << endl;
	cout << "카드 두 장을 받습니다." << endl;
	int _size = _order;
	for (_order; _order < _size + 2; _order++)
	{
		_playerCard.push_back(_card[_order].Index);
		if (_card[_order].Index % 13 + 1 == 1)
		{
			int _choose = 0;
			_card[_order].Print();
			cout << "카드를 받았습니다. \n1을 더하고 싶을 경우엔 '0', 11을 더하고 싶을 경우엔 '1'을 선택해주세요." << endl;
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
		cout << "\nPlayer의 카드 합은 " << _playerCardSum  << "입니다." << endl;
		cout << "추가 카드를 계속 받으려면 '0' 아닐 경우 '1'을 선택해주세요." << endl;
		cin >> _input;
		if (_input == 0)
		{
			cout << "Player가 뽑은 카드는 ";
			_card[_order].Print();
			_playerCard.push_back(_card[_order].Index);
			if (_card[_order].Index % 13 + 1 == 1)
			{
				int _choose = 0;
				_card[_order].Print();
				cout << "카드를 받았습니다. \n1을 더하고 싶을 경우엔 '0', 11을 더하고 싶을 경우엔 '1'을 선택해주세요." << endl;
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
				cout << "\nPlayer의 카드 합은 " << _playerCardSum << "입니다." << endl;
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
	cout << "\n\n<Com의 차례입니다>" << endl;
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
			cout << "\nCom의 카드 합은 " << _computerCardSum << "입니다." << endl;
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
		cout << "Com의 승리입니다." << endl;
		_money -= _bettingMoney;
		break;
	case 1:
		cout << "Player의 승리입니다." << endl;
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
	cout << "동적할당 해제" << endl;
}