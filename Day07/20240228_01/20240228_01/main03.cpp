#include <iostream>
using namespace std;

enum eRSP
{
	RSP_SCISSOR,
	RSP_ROCK,
	RSP_PAPER,

	RSP_END // array�� for���� ����� �� ������� ����ϱ� ���ϴ�.
};

// �Ű�����, �ƱԸ�Ʈ, �Ķ����
void PrintHand(int hand);

void main()
{
	// �Լ��� �뵵
	// ���뼺
	// ���� ������ִ� �Լ�
	PrintHand(1);
}

void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_SCISSOR:
		cout << "����" << endl;
		break;
	case RSP_ROCK:
		cout << "����" << endl;
		break;
	case RSP_PAPER:
		cout << "��" << endl;
		break;
	default:
		cout << "�ƹ��͵� �ƴ�" << endl;
		break;
	}
};