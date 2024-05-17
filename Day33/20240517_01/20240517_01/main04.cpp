#include <iostream>
using namespace std;

void Function01()
{

}

class TestObject
{
public:
	void operator()(int a) {cout << "a : " << a << endl; }
};
void main()
{
	// 함수 포인터 더 할 것은? -> NO
	// Callable 관련된 게 안 끝남.
	// Callable이란?
	//	-> () 연산자를 사용하는 게 Callable이라고 함.
	Function01(); // callable
	// 함수는 callable이지만
	// callable은 함수가 아님.
	
	TestObject obj;
	obj(3); // 얘는 함수가 아님. Callable이긴 함. ()을 쓰니깐.
	// -> obj.operator()(3);

	// 아래의 내용은 상식 정도로..
	// C++20에 새롭게 나온 Callable 호출 방법
	// 시대마다 언어가 발전해 나가면서 쓸 수 있는 문법들이 추가 됨.

	// 
}