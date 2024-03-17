#pragma once
#include <iostream>
using namespace std;

template <typename T>
class myVector
{
private: //����
	T* _arr = nullptr;
	int _size = 0;
	int _capacity = 2;

public: //������, �Ҹ���
	myVector()
	{
		cout << "������" << endl;
		_arr = new T[_capacity];
	}
	~myVector()
	{
		cout << "�Ҹ���" << endl;
		delete[] _arr;
		_arr = nullptr;
 	}
public: //��Ÿ �Լ�
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
	// ��ȯ�ڷ��� T, �Լ��� [] (�Ű����� index)
	T& operator[](int index); // &�� ���� ���۷������°� ��. ���� �� ��ü�� ��ȯ�� ��.
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
	// _capacity ���� üũ
	// ������ �ִٸ�
	// where ������ �����͸� �ڷ� �� ĭ �а�
	// where �ε����� data�� �ִ´�
	// 
	// ������ ���ٸ�
	// ���Ӱ� �迭�� ������ش�
	// ���� �� �ִ´�.
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