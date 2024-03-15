#include "MyVector.h"
#include <iostream>
using namespace std;
//헤더에서 template을 썼기 때문에 오류가 뜸
//template이 있는 곳에 함수 선언 구현을 다 해야함.

MyVector::MyVector()
{
	cout << "동적 할당" << endl;
	_arr = new int[_capacity];

}
void MyVector::push_back(T data)
{
	// 0. _size를 하나 더한다.
	// 1. _size가 capacity보다 커지면
	// 1-1. capacity *= 1.5;
	// 
	// 새로 동적배열을 만들어줌(newArr).
	// 2-2. newArr에 _arr 값을 복사해주고 _arr을 delte한다.
	// 2-3. _arr에 newArr을 대입한다.
	// 3. 마지막 인덱스에 data를 넣어준다.
	++_size;
	if (_capacity < _size)
	{
		if (_capacity < _size)
		_capacity *= 1.5;
		T* newArr = new T[_capacity];
		
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr; // 동적 배열 해제 시 [](대괄호) 사용
		_arr = newArr;
	}
	_arr[_size - 1] = data;
	/*
	// 0. _size를 하나 더한다.
	// 1. arr == nullptr이면
	// 1-1. _arr = new int[_size] 한다.
	// 2. 만약 arr != nullptr이면, 새로 동적배열을 만들어줌(newArr).
	// 2-2. newArr에 _arr 값을 복사해주고 _arr을 delte한다.
	// 2-3. _arr에 newArr을 대입한다.
	// 3. 마지막 인덱스에 data를 넣어준다.

	++_size; // 자료구조나 알고리즘에서는 전위연산이 더 좋음.

	//_size++의 경우
	// int temp = _size;
	// _size = _size + 1;

	//++_size의 경우
	// _size = _size + 1;

	//코드를 작성할 때 코드의 목적성에 따라서 코드스타일을 바꿔야할 때가 있다.
	// 좋은 코드란 무엇인가?
	// - 가독성
	// - 유지보수성
	// - 효율성(속도)

	// 엔진 완전 코어
	// (불특정 사용자들이 계속 사용할 것)
	// (실제로 이 코드는 나 밖에 안 봄)
	// => 이럴 때 가장 좋은 코드는 빠른 게 좋음.

	// 컨텐츠 쪽.
	// (기획자가 감놔라 배놔라, 아니면 사장님이 바꿔라 할 때마다 수정을 거쳐야함)
	// 할 때마다 수정이 일어남
	// 그리고 빠르게 대응하는 게 핵심
	// -> 여기서의 좋은 코드는 '가독성', '유지보수성'

	// 내가 만드는 제품이 어떤 특성을 지녔는가 << 이걸 스스로가 파악해야 함.


	if (_arr == nullptr)
	{
		_arr = new int[_size];
		_arr[_size - 1] = data;
	}
	else
	{
		int* newArr = new int[_size];
		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr; // 동적 배열 해제 시 [](대괄호) 사용
		_arr = newArr;
		_arr[_size - 1] = data;
	}
	*/
}
T MyVector::at(int index)
{
	return _arr[index];
}
MyVector::~MyVector()
{
	cout << "동적 할당 해제" << endl;
	delete[] _arr;
	_arr = nullptr;
}

