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
	// ī�� ����
	// ��A ~ ��K�� Ȱ���ؼ� �������� ī�� ���� �����
	// ī��� �� 52��.

	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		_card[i].Index = i;
		// ������ ���
		//0 ~ 12 �����̽� A ~ �����̽� K (13���� �������� �� 0)
		//13 ~ 25 ���̾� A ~ ���̾� K (13���� �������� �� 1)
		//26 ~ 38 ��Ʈ A ~ ��Ʈ K (13���� �������� �� 2)
		//39 ~ 51 Ŭ���� A ~ Ŭ���� K (13���� �������� �� 3)
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
}

void Card::Swap(Card& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}