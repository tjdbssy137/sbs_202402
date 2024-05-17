#include <iostream>
using namespace std;

// ���� ��ü�� �����ϰ�
// ��� / ������ �������ڴ�.
// Ŭ�������̾�׷�(���۸� ��)
// 
// ���(����ڰ� ��� ����� ���ΰ�?)
// - ���� 2���� �Է��Ѵ�. InputNumber1() InputNumber2()
// - �����ڸ� �Է��Ѵ�. InputOperator()
// - ����� ����Ѵ�. PrintResult()

// ����
// - int _num1;
// - int _num1;
// - int _operator;
// - int _result;
class Calculator
{
public:
	Calculator() {}
	~Calculator() {}
public:
	void InputNumber1()
	{
		cin >> _num1;
	}
	void InputNumber2()
	{
		cin >> _num2;
	}
	void InputOperator()
	{
		cin >> _operator;
	}
	void PrintResult()
	{
		Calculate();
		cout << "��� : " << _result << endl;
	}
public: // �ÿ��ڿ��� ������ �ʿ䰡 ���� �Լ�
	void Add()
	{
		_result = _num1 + _num2;
	}
	void Subtract()
	{
		_result = _num1 - _num2;
	}
	void Multiply()
	{
		_result = _num1 * _num2;
	}
	void Divide()
	{
		_result = _num1 / _num2;
	}

	void Calculate()
	{
		switch (_operator)
		{
		case 0:
			calcFunction = &Calculator::Add;
			break;
		case 1:
			calcFunction = &Calculator::Subtract;
			break;
		case 2:
			calcFunction = &Calculator::Multiply;
			break;
		case  3:
			calcFunction = &Calculator::Divide;
			break;
		default:
			break;
		}
	
		((*this).*calcFunction)();
	}

private:
	int _num1 = 0;
	int _num2 = 0;
	int _operator = 0;
	int _result = 0;

	void (Calculator::* calcFunction)(void) = nullptr; // Ŭ���� �ȿ� �ִ� ����Լ� ��� ��
};
void main()
{
	// ���⸦ Ŭ����ȭ�ؼ� ����
	// �Լ������͸� ���� Ŭ���� ��� �Լ��� �غ����� ����

	Calculator calc;
	cout << "Input first number : ";
	calc.InputNumber1();
	cout << "Input second number : ";
	calc.InputNumber2();
	cout << " 0. Add() \n 1. Minus() \n 2. Multiply() \n 3. Divide() \n";
	cout << "Input Operator : ";
	calc.InputOperator();
	calc.PrintResult();

	void (Calculator::* calcFunction)(void) = nullptr;
	calcFunction = &(Calculator::Add);
	// �׷� ����.
	// calc2, calc3 �� ���� �� �ִµ� �� �� � ��ü�� Add�Լ��� ȣ�� ��ų ����?
	// -> ����Լ��� �����ͷ� �� ���� � ��ü���� ���������� Ȯ���ϰ� ������ ���־�� ��.

	// �Լ������ʹ� �ּҸ� ���
	// calc ��ü�� calcFunction���⿡ ����� �ּҷ� ���� ����
	// *calcFunction
	(calc.*calcFunction)();
}