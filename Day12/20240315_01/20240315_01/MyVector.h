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
		cout << "���� �Ҵ�" << endl;
		_arr = new int[_capacity];
	}
	~MyVector()
	{
		cout << "���� �Ҵ� ����" << endl;
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
	// ��ȯ�ڷ��� T, �Լ��� [] (�Ű����� index)
	T& operator[](int index); // &�� ���� ���۷������°� ��. ���� �� ��ü�� ��ȯ�� ��.
	void insert(int where, T data);
};

template <typename T> // �������̸� �ܺο��� �������ִ� ���� ����.
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
		delete[] _arr; // ���� �迭 ���� �� [](���ȣ) ���
		// ���ּҿ� ������ ��Ź. ���̶�� ������ ���ܵδ� ����.
		_arr = newArr; // _arr�� newArr�� ���� ���� �����ϰ� �ֱ� ������ newArr�� delete[]�ϸ� �� ��.
	}
	_arr[_size - 1] = data;
}

template <typename T> // �������̸� �ܺο��� �������ִ� ���� ����.
T& MyVector<T>::operator[](int index)
{
	return _arr[index];
}

template <typename T>
void MyVector<T>::insert(int where, T data)
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
		for (int i = _size - 1; i >= where; i--) // ������ ���� ���Ƿ� �ٽ� Ȯ��
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
		for (int i = _size - 1; i >= where; i--) // ������ ���� ���Ƿ� �ٽ� Ȯ��
		{
			newArr[i] = _arr[i - 1];
		}
		_arr = newArr;
	}
	_arr[where] = data;
}