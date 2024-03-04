#include <iostream>
using namespace std;

void main()
{
	// 포인터 - 2
	// &와 *의 사용법

	// 포인터 = 배열
	// 엄밀하게 말하자면 조금 다름.
	
	int arr[5] = {};
	arr[0] = 1;
	arr[4] = 4;
	cout << arr << endl;

	int* ptr = arr; // 배열 행세 가능하게 됨.
	cout << ptr << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) << " ";
	}

	int arr2[10][10] = { {1, 7}, };
	int(*ptr2)[10] = arr2;
	cout << "\n{0, 0} : " << *(*ptr2 + 0) 
		<< "\n{0, 1} : " << *((*ptr2 + 0) + 1) << endl;
	
	int value = 3;
	int* ptr3 = &value; // ptr3은 value의 주소값을 갖는다. (ptr3의 주소는 따로 있다)
	int* ptr3_1 = &value; // ptr3_1은 value의 주소값을 갖는다. (ptr3과 ptr3_1의 주소는 다르다)
	int** ptr4 = &ptr3; // ptr4는 ptr3의 주소값을 갖는다.
	// 마지막 별 기준으로 앞의 자료형을 가르키는 주소값.
	// ptr4 = ptr3 = value 같은 값. 무엇 하나를 수정해도 다 같이 변함.
}