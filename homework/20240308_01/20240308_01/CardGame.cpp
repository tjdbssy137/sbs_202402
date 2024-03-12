#include "CardGame.h"
// 2) 섯다
// 
// 1. 플레이어가 1000원을 갖고 시작한다
// 2. 화투카드 20장을 섞는다
// 3. 배팅을 한다. (플레이어만 배팅할 수 있고 상대는 무조건 콜)
// 4. 플레이어 1장, 상대한테 1장을 준다
// 5. 배팅을 한다(0원 가능)
// 6. 플레이어한테 1장 상대한태도 1장을 준다
// 7. 족보가 더 높은 쪽이 승리(족보는 인터넷 참고), (게임 재시작 족보는 제외 가능)
// 8. 플레이어가 0원이 되면 게임 종료
// 9. 매판 20장을 새롭게 섞는다.

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
{//값이 틀리게 들어감.->srand(time(NULL));을 안 써서 였음.
	_playerCard.push_back(_card[_order].Index);
	_order++;
	_computerCard.push_back(_card[_order].Index);
	_order++;
}

void CardGame::Betting()
{
	cout << "현재 보유 금액 : " << _money << endl;
	cout << "판돈을 거세요 : ";
	cin >> _betMoney;
}

int CardGame::CardPedigree(vector<int> arr)
{
	int _first = arr[0];
	int _second = arr[1];
	cout << _first << ", " << _second << endl;
	if ((_first == 2 && _second == 7) || (_first == 7 && _second == 2))//삼팔광땡
	{
		return 0;
	}
	else if ((_first == 0 && _second == 7) || (_first == 7 && _second == 0))//일팔광땡
	{
		return 1;
	}
	else if ((_first == 0 && _second == 2) || (_first == 2 && _second == 0))//일삼광땡
	{
		return 2;
	}

	_first = _first % 10 + 1;
	_second = _second % 10 + 1;

	cout << _first << ", " << _second << endl;
	if (_first == _second) // 장땡, cardGame에서 com과 player 숫자 크기 판별 필요. -> 너무 번거롭다
	{
		return 3;
	}
	else if ((_first == 1 && _second == 2) || (_first == 2 && _second == 1))//알리(1,2)
	{
		return 4;
	}
	else if ((_first == 1 && _second == 4) || (_first == 4 && _second == 1))//독사(1, 4)
	{
		return 5;
	}
	else if ((_first == 1 && _second == 9) || (_first == 9 && _second == 1))//구삥(1, 9)
	{
		return 6;
	}
	else if ((_first == 10 && _second == 1) || (_first == 1 && _second == 10))//장삥(10, 1)
	{
		return 7;
	}
	else if ((_first == 10 && _second == 4) || (_first == 4 && _second == 10))//장사(10, 4)
	{
		return 8;
	}
	else if ((_first == 4 && _second == 6) || (_first == 6 && _second == 4))//세륙(4, 6)
	{
		return 9;
	}
	else if ((_first + _second == 9 && _first < 9 && _second < 9)
		|| (_first + _second == 19))//갑오(두 개 합 9, 19)
	{
		return 10;
	}
	else if (_first + _second == 0)//망통(두 개 합 10)
	{
		return 12;
	}
	else //8끗~1끗
	{
		return 11;
	}
	//특별 족보 없음.
}

void CardGame::Result()
{
	cout << "Player가 가진 카드는 ";
	_card[0].Print();
	//cout << _card[0].Index << " " << _playerCard[0] << endl;
	cout << ", ";
	_card[2].Print();
	//cout << _card[2].Index << " " << _playerCard[1] << endl;
	cout << "입니다." << endl;
	
	cout << "Computer가 가진 카드는 ";
	_card[1].Print();
	//cout << _card[1].Index << " " << _computerCard[0] << endl;
	cout << ", ";
	//cout << _card[3].Index << " " << _computerCard[1] << endl;
	_card[3].Print();
	cout << "입니다." << endl;

	int _playerScore = CardPedigree(_playerCard);
	int _computerScore = CardPedigree(_computerCard);
	//cout << "_playerScore : " << _playerScore << endl;
	//cout << "_computerScore : " << _computerScore << endl;
	if (_playerScore < _computerScore)
	{
		cout << "Player의 승리입니다." << endl;
		_money += _betMoney * 2;
	}
	else
	{
		cout << "Player의 패배입니다." << endl;
		_money -= _betMoney;
	}
	_order = 0;
	_playerCard.clear();
	_computerCard.clear();
}
CardGame::~CardGame()
{
	cout << "동적할당 해제" << endl;
}