#include <iostream>
using namespace std;

void main() {
	//SWITCH ��
	// IF���� ���� �����ϰ� IF���� ��ü�� �� �ִ�.
	// IF������ ������ -> SWITCH���� �������� �� ����, ���� �̼������� �ӵ��鿡�� �� ���.
	// ��� switch ���� if������ �ٲ� �� ������, ��� if���� switch������ �ٲ� �� ����.
	// ���� ���� �뿡 ���� ����( main02.cpp, main03.cpp ���� )

	int hand;
	cout << "����(1)����(2)��(3) �Է� : ";
	cin >> hand;

	cout << "����� ";

	switch (hand) {
	case 1:
		cout << "������ �½��ϴ�." << endl;
		break;
	case 2:
		cout << "������ �½��ϴ�." << endl;
		break;
	case 3:
		cout << "���� �½��ϴ�." << endl;
		break;
	default :
		cout << "�߸� �̾ҽ��ϴ�." << endl;
		break;
	}
}