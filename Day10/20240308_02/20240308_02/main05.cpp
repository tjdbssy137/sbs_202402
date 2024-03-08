#include <iostream>
using namespace std;

void main()
{
	// 배열의 동적 할당
	// 배열은 포인터와 비슷.

	// 동적할당을 배열로도 할 수 있음
	// 이차원 포인터로 받는 것이 아니고
	// 그냥 똑같이 일차원 포인터로 배열 동적할당을 함.
	
	//new int[크기]
	int* arr = new int[10];
	int count = 20;
	int myArr[count]; // 안 됨

	// 런타임 도중에 메모리를 할당하는 거라, 그때 맞는 배열 크기를 적어도 문제가 되지 않음.
	int* myArr = new int[count];
	// 할당하는 법
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i + 1;
	}

	//삭제하는 법
	delete[] myArr;
}