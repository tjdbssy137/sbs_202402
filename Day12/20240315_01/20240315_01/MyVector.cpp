#include "MyVector.h"
#include <iostream>
using namespace std;
//������� template�� ��� ������ ������ ��
//template�� �ִ� ���� �Լ� ���� ������ �� �ؾ���.

MyVector::MyVector()
{
	cout << "���� �Ҵ�" << endl;
	_arr = new int[_capacity];

}
void MyVector::push_back(T data)
{
	// 0. _size�� �ϳ� ���Ѵ�.
	// 1. _size�� capacity���� Ŀ����
	// 1-1. capacity *= 1.5;
	// 
	// ���� �����迭�� �������(newArr).
	// 2-2. newArr�� _arr ���� �������ְ� _arr�� delte�Ѵ�.
	// 2-3. _arr�� newArr�� �����Ѵ�.
	// 3. ������ �ε����� data�� �־��ش�.
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
		_arr = newArr;
	}
	_arr[_size - 1] = data;
	/*
	// 0. _size�� �ϳ� ���Ѵ�.
	// 1. arr == nullptr�̸�
	// 1-1. _arr = new int[_size] �Ѵ�.
	// 2. ���� arr != nullptr�̸�, ���� �����迭�� �������(newArr).
	// 2-2. newArr�� _arr ���� �������ְ� _arr�� delte�Ѵ�.
	// 2-3. _arr�� newArr�� �����Ѵ�.
	// 3. ������ �ε����� data�� �־��ش�.

	++_size; // �ڷᱸ���� �˰��򿡼��� ���������� �� ����.

	//_size++�� ���
	// int temp = _size;
	// _size = _size + 1;

	//++_size�� ���
	// _size = _size + 1;

	//�ڵ带 �ۼ��� �� �ڵ��� �������� ���� �ڵ彺Ÿ���� �ٲ���� ���� �ִ�.
	// ���� �ڵ�� �����ΰ�?
	// - ������
	// - ����������
	// - ȿ����(�ӵ�)

	// ���� ���� �ھ�
	// (��Ư�� ����ڵ��� ��� ����� ��)
	// (������ �� �ڵ�� �� �ۿ� �� ��)
	// => �̷� �� ���� ���� �ڵ�� ���� �� ����.

	// ������ ��.
	// (��ȹ�ڰ� ������ �����, �ƴϸ� ������� �ٲ�� �� ������ ������ ���ľ���)
	// �� ������ ������ �Ͼ
	// �׸��� ������ �����ϴ� �� �ٽ�
	// -> ���⼭�� ���� �ڵ�� '������', '����������'

	// ���� ����� ��ǰ�� � Ư���� ����°� << �̰� �����ΰ� �ľ��ؾ� ��.


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
		delete[] _arr; // ���� �迭 ���� �� [](���ȣ) ���
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
	cout << "���� �Ҵ� ����" << endl;
	delete[] _arr;
	_arr = nullptr;
}

