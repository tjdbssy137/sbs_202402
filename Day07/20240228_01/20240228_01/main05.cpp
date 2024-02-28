#include <iostream>
using namespace std;

void main()
{
	// pointer
	int value1 = 1;

	// pointer == 주소값
	// 포인터 기본
	// 자료형의 하나 ( 주소값을 포함한 자료형 )
	// 포인터는 자료형 뒤에 *을 붙임으로써 사용 할 수 있게 됨.
	int* myPtr = nullptr; // NULL == nullptr
	cout << "myPtr : " << myPtr << endl;
	myPtr = &value1; // &연산자 : 해당 변수의 주소값을 가져옴.
	cout << "myPtr : " << myPtr << endl; // 주소
	cout << "myPtr value : " << *myPtr << endl; // 값 // 해당 주소값의 값을 가져옴
	cout << "&(*myPtr) : " << &(*myPtr) << endl;
	cout << "*(&(*myPtr)) : " << *(&(*myPtr)) << endl;
	cout << "&myPtr(myPtr의 주소) : " << &myPtr << endl; // 주소
	cout << "myPtr(myPtr가 참조하고 있는 값의 주소) : " << myPtr << endl; // 주소

	// 실습 (vs Computer)
	// 5*5 빙고판
	// 1~25까지 랜덤한 숫자가 적혀있음
	
	// 내가 한 번 숫자를 입력하면
	// 내 빙고판에서 숫자 하나 지워지고
	// 상대 빙고판에서 숫자 하나 지워짐
	
	// 그 다음에 상대가 랜덤으로 숫자를 하나 입력함
	// 내 빙고판에서 숫자 하나 지워지고
	// 상대 빙고판에서 숫자 하나 지워짐

	// 세 줄이 빙고가 되면 해당 유저 승리


	// 실습2
	// gotozy()사용해서 캐릭터 만들기
}