#include <iostream>
#include <vector>
using namespace std;
// 숙제
// 섞은 카드를 5장 뽑는데.(카드는 한 번만 섞음)
// 네 개는 오픈
// 한 장은 XX로 표현

//전광판
// ♤3 ◆4 ♥2 ♧A XX 
// 플레이어 현재 금액 : 1000원

// 배팅 유무 선택(금액 포함)
// 배팅시 - 하이, 로우, 세븐 중에서 선택
// 하이를 고를 시
// XX의 값이 7이상이면 포인트 획득 (건 돈의 2배)
// 로우를 고를 시
// XX의 값이 7이하면 포인트 획득 (건 돈의 2배)
// 세븐을 고를시
// XX의 값이 7이면 포인트 획득 (건 돈의 10배)

// 한 판을 하면 전광판이 한 장씩 밀림.
// ♤3 ◆4 ♥2 ♧A XX -> ◆4 ♥2 ♧A ◆7 XX (새로운 XX가 생성되고 맨 첫장이 사라짐, 중복 불가)  
// 52장을 다 쓰거나, 플레이어의 금액이 0원이 되면 게임 종료.
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
	RESULT_High,
	RESULT_Low,
	RESULT_Seven
};

// 변수
Card _card[52] = {};
Player _player = {};
vector<int> _displayBoard;// => vector<Card&> _displayBoard;로 해서 의미 없는 push&back없앨 수 있음
int _order = 0;
int _bettingMoney = 0;
int _cardEnd = 0;

// 함수
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

	while (false == ((_cardEnd == 1) || (_player.Money <= 0)))
	{
		
		PrintCards();
		ExpectCard();
		CalculateMoney();
	}
	cout << "게임 종료";
}

void Card::cPrint()
{
	switch (Index / 13)
	{
	case 0:
		cout << "♤";
		break;
	case 1:
		cout << "◆";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "♧";
		break;
	}
	switch (Index % 13 + 1)
	{
	case 1:
		cout << " A ";
		break;
	case 11:
		cout << " J ";
		break;
	case 12:
		cout << " Q ";
		break;
	case 13:
		cout << " K ";
		break;
	default:
		printf(" %d  ", Index % 13 + 1);
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
	cout << "===============================" << endl;
	for (_order; _displayBoard.size() <= 4; _order++)
	{
		if (_order == 52)
		{
			_cardEnd = 1;
			cout << "카드를 전부 사용하였습니다. 게임이 종료 됩니다." << endl;
			break;
		}
		if (_displayBoard.size() < 4)
		{
			_card[_order].cPrint();
			_displayBoard.push_back(0);
		}
		else
		{
			cout << "XX" << endl;
			_displayBoard.push_back(0);
			break;
		}
	}
	cout << "===============================" << endl;
}
void ExpectCard()
{
	cout << "하이(0) / 로우(1) / 세븐(2)" << endl;
	cout << "**하이는 2배, 로우는 2배, 세븐은 10배입니다.**" << endl;
	cin >> _player.Bet;
	cout << "배팅하실 금액을 입력해주세요." << endl;
	cout << "현재 보유 금액 : " << _player.Money << "원" << endl;
	cin >> _bettingMoney;
}
void CalculateMoney()
{
	if (7 < _card[_order].Index % 13 + 1)
	{
		if (RESULT_High == _player.Bet)
		{
			_player.Money += (_bettingMoney * 2);
			cout << "축하합니다. " << _bettingMoney * 2 << "원을 얻으셨습니다!" << endl;
		}
		else
		{
			_player.Money -= (_bettingMoney * 2);
			if (_player.Money < 0)
			{
				cout << _bettingMoney * 2 << "원을 잃으셨습니다! 현재 금액은 " << _player.Money << "로 파산하셨습니다." << endl;
			}
			else
			{
				cout << _bettingMoney * 2 << "원을 잃으셨습니다!" << endl;
			}
		}
	}
	else if (_card[_order].Index % 13 + 1 < 7)
	{
		if (RESULT_Low == _player.Bet)
		{
			_player.Money += (_bettingMoney * 2);
			cout << "축하합니다. " << _bettingMoney * 2 << "원을 얻으셨습니다!" << endl;
		}
		else
		{
			_player.Money -= (_bettingMoney * 2); 
			if (_player.Money < 0)
			{
				cout << _bettingMoney * 2 << "원을 잃으셨습니다! 현재 금액은 " << _player.Money << "로 파산하셨습니다." << endl;
			}
			else
			{
				cout << _bettingMoney * 2 << "원을 잃으셨습니다!" << endl;
			}
		}
	}
	else if (_card[_order].Index % 13 + 1 == 7)
	{
		if (RESULT_Seven == _player.Bet)
		{
			_player.Money += (_bettingMoney * 10);
			cout << "축하합니다. " << _bettingMoney * 10 << "원을 얻으셨습니다!" << endl;
		}
		else
		{
			_player.Money -= (_bettingMoney * 10);
			if (_player.Money < 0)
			{
				cout << _bettingMoney * 10 << "원을 잃으셨습니다! 현재 금액은 " << _player.Money << "로 파산하셨습니다." << endl;
			}
			else
			{
				cout << _bettingMoney * 10 << "원을 잃으셨습니다!" << endl;
			}
		}
	}
	// 정리
	_displayBoard.clear();
	_order -= 3;
}