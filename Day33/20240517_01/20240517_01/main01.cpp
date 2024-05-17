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
	// 함수 포인터
	// - 함수 포인터 : 난이도 높음
	
	// 함수포인터란?

	// - 포인터 : 주소를 가르키는 자료형
	//		- 주소를 조작할 수 있는 유일한 수단. C, C++에서만 사용.
	// - 함수 포인터 : 함수의 주소를 가르키는 자료형
	
	// - 자료형들처럼 함수도 메모리를 차지함.
	// int형은 4byte 메모리를 차지
	// 함수도 전부 4byte 차지 (모든 함수) [주소를 기억]

	// 즉, 함수의 주소를 기억했다가 나중에 쓸 수도 있겠다.
	//		-> 함수 포인터(다른 언어에서는 콜백function이라고 함)
	
	// - 함수 포인터(콜백) : 함수의 주소를 기억했다가 나중에 사용하는 기법.

	// 사용법
	// int 포인터 : int*
	// 함수포인터 : 함수반환형 네임스페이스::*변수명(매개변수)

	cout << "Run()'s address : " << &Run << endl;
	
	void* myPointer = &Run; // void 포인터 형식은 주소라면 무엇이든 담을 수 있음
	//int* myPointer = (int*) &Run; // 형변환 해서 담으면 됨.

	cout << "myPointer : " << myPointer << endl;

	void(*myFunction)(void) = &Run; // == void* myPointer = &Run;

	// 사용법
	cout << "----------------" << endl;
	myFunction();


	// 응용 1. 매개변수가 있는 함수

	void(*myRun1)(int, int) = &Run1;
	myRun1(10, 1);

	// 응용2. 반환자료형이 있는 함수 

	int(*myAdd)(int, int) = &Add; // == int(*myAdd)(int a, int b) = &Add;
	int addValue = myAdd(5, 6);
	cout << "addValue : " << addValue << endl;

	// 실습
	// 계산기를 만들건데
	// 1. 숫자 두개를 입력 받는다
	// 2.2 (+ - / *) 중 하나를 할 수 이또록 입력
	// 3. 각각 + (Add) - (Minus) * (Multiply) / (Divide)
	// 4. 2번을 실행하면, 함수 포인터로 만든 함수를 하나 받도록 한다
}