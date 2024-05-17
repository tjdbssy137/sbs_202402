#include <iostream>
using namespace std;

// 계산기 객체라 생각하고
// 기능 / 변수를 나눠보겠다.
// 클래스다이어그램(구글링 해)
// 
// 기능(사용자가 어떻게 사용할 것인가?)
// - 숫자 2개를 입력한다. InputNumber1() InputNumber2()
// - 연산자를 입력한다. InputOperator()
// - 결과를 출력한다. PrintResult()

// 변수
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
		cout << "결과 : " << _result << endl;
	}
public: // 시용자에게 노출할 필요가 없는 함수
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

	void (Calculator::* calcFunction)(void) = nullptr; // 클래스 안에 있는 멤버함수 사용 시
};
void main()
{
	// 계산기를 클래스화해서 만듦
	// 함수포인터를 아직 클래스 멤버 함수로 해본적이 없음

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
	// 그럼 문제.
	// calc2, calc3 도 있을 수 있는데 그 중 어떤 객체의 Add함수를 호출 시킬 건지?
	// -> 멤버함수를 포인터로 쓸 때는 어떤 객체에서 쓸건지까지 확실하게 지정을 해주어야 함.

	// 함수포인터는 주소를 기억
	// calc 객체의 calcFunction여기에 저장된 주소로 가서 실행
	// *calcFunction
	(calc.*calcFunction)();
}