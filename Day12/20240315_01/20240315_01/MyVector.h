#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyVector
{
private:
	T* _arr = nullptr;
	int _size = 0;
	int _capacity = 2;
public:
	MyVector()
	{
		cout << "동적 할당" << endl;
		_arr = new int[_capacity];
	}
	~MyVector()
	{
		cout << "동적 할당 해제" << endl;
		delete[] _arr;
		_arr = nullptr;
	}
public:
	void push_back(T data);
	T at(int index)
	{
		return _arr[index];
	}
	int size()
	{
		return _size;
	}
	int capacity()
	{
		return _capacity;
	}
	// 반환자료형 T, 함수명 [] (매개변수 index)
	T& operator[](int index); // &를 통해 레퍼런스형태가 됨. 변수 그 자체가 반환이 됨.
	void insert(int where, T data);
};

template <typename T> // 가급적이면 외부에서 선언해주는 것이 좋다.
void push_back(T data)
{
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
		// 집주소와 내용을 세탁. 집이라는 껍질만 남겨두는 과정.
		_arr = newArr; // _arr과 newArr이 같은 값을 공유하고 있기 때문에 newArr은 delete[]하면 안 됨.
	}
	_arr[_size - 1] = data;
}

template <typename T> // 가급적이면 외부에서 선언해주는 것이 좋다.
T& MyVector<T>::operator[](int index)
{
	return _arr[index];
}

template <typename T>
void MyVector<T>::insert(int where, T data)
{
	// ++ size
	// _capacity 값을 체크
	// 여유가 있다면
	// where 이후의 데이터를 뒤로 한 칸 밀고
	// where 인덱스에 data를 넣는다
	// 
	// 여유가 없다면
	// 새롭게 배열을 만들어준다
	// 값을 잘 넣는다.

	++_size;
	if (_size <= _capacity)
	{
		for (int i = _size - 1; i >= where; i--) // 위험한 이유 강의로 다시 확인
		{
			_arr[i] = _arr[i - 1];
		}
	}
	else
	{
		_capacity *= 1.5;
		T* newArr = new T[_capacity];
		for (int i = 0; i < where; i++)
		{
			newArr[i] = _arr[i];
		}
		for (int i = _size - 1; i >= where; i--) // 위험한 이유 강의로 다시 확인
		{
			newArr[i] = _arr[i - 1];
		}
		_arr = newArr;
	}
	_arr[where] = data;
}