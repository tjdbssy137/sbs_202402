#pragma once
#include <iostream>
using namespace std;

template <typename T>
class myVector
{
private: //변수
	T* _arr = nullptr;
	int _size = 0;
	int _capacity = 2;

public: //생성자, 소멸자
	myVector()
	{
		cout << "생성자" << endl;
		_arr = new T[_capacity];
	}
	~myVector()
	{
		cout << "소멸자" << endl;
		delete[] _arr;
		_arr = nullptr;
 	}
public: //기타 함수
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

template <typename T>
void myVector<T>::push_back(T data)
{
	++_size;
	if (_capacity < _size)
	{
		_capacity *= 1.5;

		T* newArr = new T[_capacity];

		for (int i = 0; i < _size - 1; i++)
		{
			newArr[i] = _arr[i];
		}
		delete[] _arr;
		_arr = newArr;
	}
	_arr[_size - 1] = data;
}

template <typename T>
T& myVector<T>::operator[](int index)
{
	return _arr[index];
}

template <typename T>
void myVector<T>::insert(int where, T data)
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
		for (int i = _size - 1; i >= where; i--)
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
		for (int i = _size - 1; i >= where; i--)
		{
			newArr[i] = _arr[i - 1];
		}
		delete[] _arr;
		_arr = newArr;
	}
	_arr[where] = data;
}