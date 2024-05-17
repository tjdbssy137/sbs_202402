#include <iostream>
#include <functional>
using namespace std;

void Run1()
{
	cout << "Run1()" << endl;
}

void Run2(int a)
{
	cout << "Run2() " << a << endl;
}

int Run3(int a)
{
	return a*2;
}

class TestObject 
{
public:
	void DoSomething();
};
void main()
{
	// C++20 문법 사용하는 방법
	// visual studio 2019, 2017 << 여기서는 안 됨

	// 함수포인터 문법
	// 반환자료형 네임스페이스::*변수명(매개변수) = 값;
	
	// function<반환자료형(매개변수)> 변수명 = 값;
	function<void()> myFunction = &Run1;
	myFunction();

	function<void(int)> myFunction2 = &Run2;
	myFunction2(3);

	function<int(int)> myFunction3 = &Run3;
	cout << "Run3() " << myFunction3(3) << endl;

	// 클래스 함수
	function<void(TestObject&)> myFunction4 = &TestObject::DoSomething;
	TestObject t1;
	//TestObject t2;
	//TestObject t3;
	myFunction4(t1);
	
	// 더 알고 싶으면 function, bind, mem_fn을 검색
	// 실제로 적용할 클래스 함수 코드
	function<void()> myFunction5 = nullptr;
	// bind(바인딩 시킬 함수, 실행시킬 object);
	myFunction5 = bind(&TestObject::DoSomething, &t1);
	myFunction5();
}