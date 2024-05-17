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
	// 계산기 실습
	
	// 이론 배울 때
	// [What, How], Why
	
	// 함수 포인터를 왜 쓰는 가?
	// 굳이 기괴한 문법을 써가면서까지, 함수를 기억하고 그 변수를 사용해야하나..
	// myFunction(2, 3)을 호출하는 것보다
	// Add(2, 3);이 훨씬 더 가독성이 좋다.

	// 쓰는 곳중에 한 곳만 직관적으로 보이는 곳
	// 몬스터 AI (보스몬스터)
	//	-> void (&DoSomething)(void) 라는 변수를 만들어서 활용
	
	// update문에서
	//	- 플레이어가 내 주변에 있다 -> DoSomething = 공격한다로 변환
	//	- HP가 30 이하다 -> DoSomething = 휴식한다로 변환

	// AI 로직에서는 
	// 모든 몬스터는 DoSomething()만 실행하면, AI 로직이 완성

	// 결국 왜 쓰는가?
	// DoSomething 변수 하나로 행동에 곤한 모든 함수를 알아서 커버할 수 있다.

	cout << "---------------------------------------------" << endl;
	cout << "강사님이 작성한 코드" << endl;
	cout << "---------------------------------------------" << endl;
	
	int(*calculatorFunction)(int num1, int num2) = nullptr;
	int num1 = 0;
	int num2 = 0;

	cout << "첫번째 숫자 입력 : ";
	cin >> num1;
	cout << "두번째 숫자 입력 : ";
	cin >> num2;

	int oper = 0;

	cout << " 1. Add() \n 2. Minus() \n 3. Multiply() \n 4. Divide() \n";
	while (false == (oper < 5 && 0 < oper))
	{
		cout << "계산 방식 입력 : ";
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
	cout << "내가 작성한 코드" << endl;
	cout << "---------------------------------------------" << endl;
	
	int(*_addPointer)(int, int) = &Add;
	int(*_minusPointer)(int, int) = &Minus;
	int(*_multiplyPointer)(int, int) = &Multiply;
	int(*_dividePointer)(int, int) = &Divide;

	int _num1 = 0;
	int _num2 = 0;

	cout << "첫번째 숫자 입력 : ";
	cin >> _num1;
	cout << "두번째 숫자 입력 : ";
	cin >> _num2;

	int _choice = 0;

	cout << " 1. Add() \n 2. Minus() \n 3. Multiply() \n 4. Divide() \n";
	while (false == (_choice < 5 && 0 < _choice))
	{
		cout << "계산 방식 입력 : ";
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