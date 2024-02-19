#include <iostream>
#include <time.h>
using namespace std;
//cout�� cin�� std::�� ������� �ʰ� ��� ����.

// ������
// ��Ģ���� => ������
// +, -, *, /, %(������)

// �����ڳ����� � ���� ���� �̷������ ���� ���� ����� �޶�����.
// *, /�� �׻� ���� ����
// +, -�� �׻� �Ŀ� ����

// �⺻���� ��Ģ������ �����ϰ��� �׻� �켱���� ������ �����ش�.
// => () �Ұ�ȣ�� �̿�.


// �Լ� 
// => ������ main ���� �ۼ�. C�� CPP�� ������ �Ʒ��� �ڵ带 �б� ������.
//��ȯŸ�� �Լ���() // �Լ����� �빮�ڷ� ����
//{
//		������ �ڵ�
//}

int _myHand = 0;
int _comHand = 0;

void PrintGameStartScene() 
{
	printf(" _____________________________________\n");
	printf("|                                     |\n");
	printf("|    Rock Scissor Paper Game Start    |\n");
	printf("|_____________________________________|\n");
}

void ChooseMyHand() 
{
	cout << "����(0)����(1)��(2) �Է� >> ";
	cin >> _myHand;
}

void ChooseComHand() 
{
	_comHand = rand() % 3;
}

void PrintHand(int _hand) 
{
	switch (_hand) {
	case 0:
		cout << "����";
		break;
	case 1:
		cout << "����";
		break;
	case 2:
		cout << "��";
		break;
	default:
		cout << "�߸�";
		break;
	}
	cout << " �Դϴ�." << endl;
}

void PrintGameResult() 
{
	if (_myHand == _comHand)
		printf("�����ϴ�");
	else if (_myHand == 2 && _comHand == 0)
		printf("�й��߽��ϴ�");
	else if (_myHand > _comHand || (_myHand == 0 && _comHand == 2))
		printf("�¸��߽��ϴ�");
	else
		printf("�й��߽��ϴ�");
}

void main()
{
	srand(time(NULL));//�ѹ��� ����ǰ� �� main���� ����

	//���� �ڵ�
	// 1. ���ӽ���ȭ�������
	// 2. ���� � ���� ���� �� ���
	// 3. ������ � ���� ���� �� ����
	// 4. ���� ���� �Ͱ� ������ ���� ���� ���
	// 5. ���и� ���
	PrintGameStartScene();
	ChooseMyHand();
	ChooseComHand();
	cout << "_myHand�� �� ���� ";
	PrintHand(_myHand);
	cout << "_comHand�� �� ���� ";
	PrintHand(_comHand);
	PrintGameResult();
}