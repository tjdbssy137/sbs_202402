#include <iostream>
using namespace std;

int a = 0;
int b = 0;

void Run()
{

}

void Run1(int argument1, int argument2)
{
	cout << "argument1 : " << argument1 << endl;
	cout << "argument2 : " << argument2 << endl;
}

int Add(int num1, int num2)
{
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
	return num1 + num2;
}
void main()
{
	// �Լ� ������
	// - �Լ� ������ : ���̵� ����
	
	// �Լ������Ͷ�?

	// - ������ : �ּҸ� ����Ű�� �ڷ���
	//		- �ּҸ� ������ �� �ִ� ������ ����. C, C++������ ���.
	// - �Լ� ������ : �Լ��� �ּҸ� ����Ű�� �ڷ���
	
	// - �ڷ�����ó�� �Լ��� �޸𸮸� ������.
	// int���� 4byte �޸𸮸� ����
	// �Լ��� ���� 4byte ���� (��� �Լ�) [�ּҸ� ���]

	// ��, �Լ��� �ּҸ� ����ߴٰ� ���߿� �� ���� �ְڴ�.
	//		-> �Լ� ������(�ٸ� ������ �ݹ�function�̶�� ��)
	
	// - �Լ� ������(�ݹ�) : �Լ��� �ּҸ� ����ߴٰ� ���߿� ����ϴ� ���.

	// ����
	// int ������ : int*
	// �Լ������� : �Լ���ȯ�� ���ӽ����̽�::*������(�Ű�����)

	cout << "Run()'s address : " << &Run << endl;
	
	void* myPointer = &Run; // void ������ ������ �ּҶ�� �����̵� ���� �� ����
	//int* myPointer = (int*) &Run; // ����ȯ �ؼ� ������ ��.

	cout << "myPointer : " << myPointer << endl;

	void(*myFunction)(void) = &Run; // == void* myPointer = &Run;

	// ����
	cout << "----------------" << endl;
	myFunction();


	// ���� 1. �Ű������� �ִ� �Լ�

	void(*myRun1)(int, int) = &Run1;
	myRun1(10, 1);

	// ����2. ��ȯ�ڷ����� �ִ� �Լ� 

	int(*myAdd)(int, int) = &Add; // == int(*myAdd)(int a, int b) = &Add;
	int addValue = myAdd(5, 6);
	cout << "addValue : " << addValue << endl;

	// �ǽ�
	// ���⸦ ����ǵ�
	// 1. ���� �ΰ��� �Է� �޴´�
	// 2.2 (+ - / *) �� �ϳ��� �� �� �̶Ƿ� �Է�
	// 3. ���� + (Add) - (Minus) * (Multiply) / (Divide)
	// 4. 2���� �����ϸ�, �Լ� �����ͷ� ���� �Լ��� �ϳ� �޵��� �Ѵ�
}