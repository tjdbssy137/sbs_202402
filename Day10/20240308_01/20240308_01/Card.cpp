// 헤더와 같은 이름을 짓는다.
//아무리 main에서 다른 파일을 include 해도 새로운 cpp파일에 오면 초기화 상태가 된다.
#include "Card.h" // 그래서 선언.


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
		printf(" %d ", Index % 13 + 1);
		break;
	}
}

void Card::Swap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}