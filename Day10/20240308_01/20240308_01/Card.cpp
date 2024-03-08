// ����� ���� �̸��� ���´�.
//�ƹ��� main���� �ٸ� ������ include �ص� ���ο� cpp���Ͽ� ���� �ʱ�ȭ ���°� �ȴ�.
#include "Card.h" // �׷��� ����.


void Card::Print()
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