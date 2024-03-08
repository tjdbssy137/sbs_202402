#include <iostream>
using namespace std;

void main()
{
	// 포인터 - 3
	// 동적할당
	
	// 포인터 => 주소값
	int value = 0;
	int* ptr = &value;
	//ptr에 value의 주소값을 넣음.

	// 동적으로 런타임 중에 메모리를 생성할 수 있음
	
	new int();
	// new 키워드를 활용하면 int라는 변수가 생성
	// 새롭게 값이 만들어졌으면, 주소가 나올 것

	{
		int* myPtr = new int();
		// 이렇게 하면, 새롭게 동적할당된 int 메모리가 myPtr에 주소값을 저장 시킨다.
	}
	// 중괄호를 나가면 myPtr은 자동 삭제
	// 하지만 new int()는 삭제 안 됨. => 동적으로 만든 메모리이기 때문에.
	// myPtr은 정적메모리 이기에 삭제 안 됨
	// new int()는 동적메모리 이기에 삭제 안 됨
	// ==> 메모리 누수

	// 그래서 cpp에서는 메모리누수 막는 작업이 가장 중요!

	// 동적 메모리 삭제하는 방법!
	// delete 주소값;
	{
		// new 자료형();
		int* myPtr = new int();
		delete myPtr;
	}
	while (true)
	{
		// 동적메모리는 만들면 삭제해야 함
		// 항상 new 와 delete는 붙어다님.
		int* myPtr = new int(); // 이론상 1틱 당 4byte 할당
		delete myPtr;
	}
}