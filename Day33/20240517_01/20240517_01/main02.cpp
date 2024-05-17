#include <iostream>
using namespace std;

enum Operator
{
	None,
	Add1,
	Minus1,
	Multiply1,
	Divide1
};

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Minus(int num1, int num2)
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
	// ���� �ǽ�
	
	// �̷� ��� ��
	// [What, How], Why
	
	// �Լ� �����͸� �� ���� ��?
	// ���� �Ⱬ�� ������ �ᰡ�鼭����, �Լ��� ����ϰ� �� ������ ����ؾ��ϳ�..
	// myFunction(2, 3)�� ȣ���ϴ� �ͺ���
	// Add(2, 3);�� �ξ� �� �������� ����.

	// ���� ���߿� �� ���� ���������� ���̴� ��
	// ���� AI (��������)
	//	-> void (&DoSomething)(void) ��� ������ ���� Ȱ��
	
	// update������
	//	- �÷��̾ �� �ֺ��� �ִ� -> DoSomething = �����Ѵٷ� ��ȯ
	//	- HP�� 30 ���ϴ� -> DoSomething = �޽��Ѵٷ� ��ȯ

	// AI ���������� 
	// ��� ���ʹ� DoSomething()�� �����ϸ�, AI ������ �ϼ�

	// �ᱹ �� ���°�?
	// DoSomething ���� �ϳ��� �ൿ�� ���� ��� �Լ��� �˾Ƽ� Ŀ���� �� �ִ�.

	cout << "---------------------------------------------" << endl;
	cout << "������� �ۼ��� �ڵ�" << endl;
	cout << "---------------------------------------------" << endl;
	
	int(*calculatorFunction)(int num1, int num2) = nullptr;
	int num1 = 0;
	int num2 = 0;

	cout << "ù��° ���� �Է� : ";
	cin >> num1;
	cout << "�ι�° ���� �Է� : ";
	cin >> num2;

	int oper = 0;

	cout << " 1. Add() \n 2. Minus() \n 3. Multiply() \n 4. Divide() \n";
	while (false == (oper < 5 && 0 < oper))
	{
		cout << "��� ��� �Է� : ";
		cin >> oper;
	}

	switch (oper)
	{
	case Operator::Add1:
		calculatorFunction = &Add;
		break;
	case Operator::Minus1:
		calculatorFunction = &Minus;
		break;
	case Operator::Multiply1:
		calculatorFunction = &Multiply;
		break;
	case  Operator::Divide1:
		calculatorFunction = &Divide;
		break;
	default:
		break;
	}

	if (calculatorFunction != nullptr)
	{
		cout << calculatorFunction(num1, num2) << endl;
	}
	
	cout << "---------------------------------------------" << endl;
	cout << "���� �ۼ��� �ڵ�" << endl;
	cout << "---------------------------------------------" << endl;
	
	int(*_addPointer)(int, int) = &Add;
	int(*_minusPointer)(int, int) = &Minus;
	int(*_multiplyPointer)(int, int) = &Multiply;
	int(*_dividePointer)(int, int) = &Divide;

	int _num1 = 0;
	int _num2 = 0;

	cout << "ù��° ���� �Է� : ";
	cin >> _num1;
	cout << "�ι�° ���� �Է� : ";
	cin >> _num2;

	int _choice = 0;

	cout << " 1. Add() \n 2. Minus() \n 3. Multiply() \n 4. Divide() \n";
	while (false == (_choice < 5 && 0 < _choice))
	{
		cout << "��� ��� �Է� : ";
		cin >> _choice;
	}

	switch (_choice)
	{
	case 1:
		cout << "Add(" << _num1 << ", " << _num2 << ") : " << _addPointer(_num1, _num2) << endl;
		break;
	case 2:
		cout << "Minus(" << _num1 << ", " << _num2 << ") : " << _minusPointer(_num1, _num2) << endl;
		break;
	case 3:
		cout << "Multiply(" << _num1 << ", " << _num2 << ") : " << _multiplyPointer(_num1, _num2) << endl;
		break;
	case 4:
		cout << "Divide(" << _num1 << ", " << _num2 << ") : " << _dividePointer(_num1, _num2) << endl;
		break;
	default:
		break;
	}
}