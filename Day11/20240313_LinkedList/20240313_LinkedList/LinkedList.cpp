#include "LinkedList.h"
#include <iostream>
using namespace std;

//����
// 1. �ܿ�� (1. LinkedList.h, 2. LinkedList.cpp)
// 2. prev�� �����.

// �ڷ� ���� / �˰��򿡼� �߿��ϰ� �ٷ�� ��
// �ð� ���⵵
// ��� �Լ��� �������� �� �ɸ��� �ð� ���
// �� �Լ� �ȿ��� for���� �󸶳� ���� ��.


// �� �ڷᱸ���� �����Ͱ� n����� ������ ��
// O(n) -> n�� ��ȯ�Ѵ�.
// O(n) + O(n) = O(n)
// ����ȭ ��ġ�� ����.

// ������ �������� ���α׷��� ���������� �ð����⵵ ��ü�� ��.


LinkedList::LinkedList()
{
	cout << "�����Ҵ�" << endl;
}

void LinkedList::push_back(int data)
{
	//<�������� �����͸� �ִ´�>
	// ���� �ڵ� �ۼ�
	// �����ڵ带 �˸� �� �ڷᱸ���� ������� �� �� �ۿ� ����.
	
	// newNode�� ������ش�.
	// _root ���� �����Ѵ�
	// current = _root;
	// --
	// _root�� NULL�� �ƴ϶��
	// current�� Next�� null�� �� ������
	// current�� Next�� �ѱ��.
	// newNode�� �ּҸ� current Next�� ���� ��Ų��.
	// --
	// _root�� NULL�̶��
	// _root�� newNode�� ���� ��Ų��.

	Node* newNode = new Node(); // �����Ҵ�
	newNode->Data = data;
	newNode->Next = NULL;

	Node* current = _root;
	if (_root != nullptr)
	{
		while (current->Next != NULL)
		{
			current = current->Next;
		}
		//current->Next = nullptr;
		current->Next = newNode;
	}
	else
	{
		_root = newNode;
	}
}

void LinkedList::pop_back()
{
	// �����ڵ�
	// deletedNode�� �����.
	// currentNode�� �����.
	// deletedNode�� ���� ���������� ������.
	// currentNode�� Next�� deletedNode�� ���� ������ ������ �ѱ��.
	// deletedNode�� �����.
	// currentNode�� Next�� NULL�� ó�����ش�.
	if (_root != nullptr)
	{
		cout << "_root�� nullptr �Դϴ�" << endl;
		return;
	}

	Node* currentNode = _root;
	Node* deletedNode = _root;

	while (deletedNode->Next != nullptr)
	{
		deletedNode = deletedNode->Next;
	}
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}

	if (deletedNode != NULL)
	{
		delete deletedNode;
		deletedNode = nullptr;
	}
	currentNode->Next = nullptr;
}

int LinkedList::at(int index)
{
	// �����ڵ�
	// current�� �����Ѵ�
	// (index)�� ��ŭ Next�� �̵��Ѵ�
	// �� ���� return�Ѵ�.

	Node* current = _root;
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	return current->Data;
}

void LinkedList::remove_data(int data)
{
	// ������ ���� �Ǻ��Ͽ� �� ��带 ����
	// �ߺ��� �����Ͱ� ������ ���� �ε��� �����͸� ����

	// �����ڵ�
	// currentNode�� deleteNode�� �����
	// ���ϴ� �����͸� ���� ������ deleteNode�� �ѱ��
	// currentNode->Next �� deleteNode�� �� ������ �ѱ��.
	// currentNode->Next�� deleteNode->Next�� �ٲ۴�
	// deleteNode�� �����Ѵ�.
	// 
	// ���� �����Ϳ� �״��� �����͸� ����.

	Node* currentNode = _root;
	Node* endNode = _root;

	while (endNode->Data != data)
	{
		endNode = endNode->Next;
	}
	while (currentNode->Next != endNode)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = endNode->Next;
	delete endNode;
	endNode = nullptr;//�����ϸ� �ϱ�.
}
void LinkedList::add_data(int data, int index)
{
	// ���� ���ϴ� �ε����� ������ �ֱ�
	// currentNode�� �����.
	// (index)�� currentNode�� ��ġ�� �ű��
	// data�� ���� �ִ� newNode ����
	// newNode->Next�� currentNode->Next�� �ٲ۴�
	// currentNode->Next�� newNode�� �ٲ۴�.

	Node* newNode = new Node();
	newNode->Data = data;
	Node* currentNode = _root;

	for (int i = 0; i < index-1; i++)
	{
		currentNode = currentNode->Next;
	}
	newNode->Next = currentNode->Next;
	currentNode->Next = newNode;
}
int LinkedList::size()
{
	int count = 0;
	Node* currentNode = _root;
	while (currentNode->Next != NULL)
	{
		count++;
		currentNode = currentNode->Next;
	}
	return count;
}
LinkedList::~LinkedList()
{
	cout << "�����Ҵ� ����" << endl;
}