#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyVector {
private:
	T* _arr = nullptr;
	int _size = 0;
	int _capacity = 2;
public:
	MyVector()
	{
		cout << "동적할당" << endl;
		_arr = new T[_capacity];
	}
	~MyVector()
	{
		cout << "동적할당해제" << endl;
		delete[] _arr;
		_arr = nullptr;
	}
public:
	void push_back(T data);
	T at(int index);
	T& operator[](int index);
	int size();
	int capacity();
	void insert(int where, T data);
};
template <typename T>
void MyVector<T>::push_back(T data)
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
T MyVector<T>::at(int index)
{
	return _arr[index];
}

template <typename T>
T& MyVector<T>::operator[](int index)
{
	return _arr[index];
}

template <typename T>
int MyVector<T>::size()
{
	return _size;
}

template <typename T>
int MyVector<T>::capacity()
{
	return _capacity;
}

template <typename T>
void MyVector<T>::insert(int where, T data)
{
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