#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}
int Subtract(int num1, int num2)
{
	return num1 - num2;
}
int Multiply(int num1, int num2)
{
	return num1 * num2;
}
int Divide(int num1, int num2)
{
	return num1 / num2;
}

void main()
{
	//�Լ�
	// �Լ��� ����
	// ��ȯ�ڷ��� �Լ���(�Ű�����(��)){}
	// void		 PrintHand(int Hand){}
	//�Լ������� �̸��� ����, �Ű������� �Լ��� �ɼ��� �� �� �ִ�.
	
	// ��ȯ�� return Value

	// �ǽ�
	// ���⿡ ���̴� �Լ��� ����
	// Add
	// Subtract
	// Multiply
	// Divide
	
	cout << "Add(2, 4) : " << Add(2, 4) << endl;
	cout << "Subtract(11, 123) : " << Subtract(11, 123) << endl;
	cout << "Multiply(19, 19) : " << Multiply(19, 19) << endl;
	cout << "Divide(6, 3) : " << Divide(6, 3) << endl;
	
	// Ȥ�� 
	// int temp = Add(2, 4);
	// cout << << "Add(2, 4) : " << temp;
}