#include <iostream>
using namespace std;

struct Card {
	int Index;
	
	void Print();
	void Swap(Card& another);
};

Card _card[52] = {};

void main()
{
	// 카드 게임
	// ♣A ~ ♠K를 활용해서 여러가지 카드 게임 만들기
	// 카드는 총 52장.

	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
		// 임의의 약속
		//0 ~ 12 스페이스 A ~ 스페이스 K (13으로 나누었을 때 0)
		//13 ~ 25 다이아 A ~ 다이아 K (13으로 나누었을 때 1)
		//26 ~ 38 하트 A ~ 하트 K (13으로 나누었을 때 2)
		//39 ~ 51 클러버 A ~ 클러버 K (13으로 나누었을 때 3)
	}

	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % 52;
		int dst = rand() % 52;

		_card[src].Swap(_card[dst]);
	}

	for (int i = 0; i < 52; i++)
	{
		_card[i].Print();
		cout << endl;
	}
}

void Card::Print()
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
}

void Card::Swap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}