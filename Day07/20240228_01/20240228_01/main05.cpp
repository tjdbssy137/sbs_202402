#include <iostream>
using namespace std;

void main()
{
	// pointer
	int value1 = 1;

	// pointer == �ּҰ�
	// ������ �⺻
	// �ڷ����� �ϳ� ( �ּҰ��� ������ �ڷ��� )
	// �����ʹ� �ڷ��� �ڿ� *�� �������ν� ��� �� �� �ְ� ��.
	int* myPtr = nullptr; // NULL == nullptr
	cout << "myPtr : " << myPtr << endl;
	myPtr = &value1; // &������ : �ش� ������ �ּҰ��� ������.
	cout << "myPtr : " << myPtr << endl; // �ּ�
	cout << "myPtr value : " << *myPtr << endl; // �� // �ش� �ּҰ��� ���� ������
	cout << "&(*myPtr) : " << &(*myPtr) << endl;
	cout << "*(&(*myPtr)) : " << *(&(*myPtr)) << endl;
	cout << "&myPtr(myPtr�� �ּ�) : " << &myPtr << endl; // �ּ�
	cout << "myPtr(myPtr�� �����ϰ� �ִ� ���� �ּ�) : " << myPtr << endl; // �ּ�

	// �ǽ� (vs Computer)
	// 5*5 ������
	// 1~25���� ������ ���ڰ� ��������
	
	// ���� �� �� ���ڸ� �Է��ϸ�
	// �� �����ǿ��� ���� �ϳ� ��������
	// ��� �����ǿ��� ���� �ϳ� ������
	
	// �� ������ ��밡 �������� ���ڸ� �ϳ� �Է���
	// �� �����ǿ��� ���� �ϳ� ��������
	// ��� �����ǿ��� ���� �ϳ� ������

	// �� ���� ���� �Ǹ� �ش� ���� �¸�


	// �ǽ�2
	// gotozy()����ؼ� ĳ���� �����
}