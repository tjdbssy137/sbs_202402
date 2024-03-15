#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	cout << "동적할당" << endl;
}
LinkedList::~LinkedList()
{
	cout << "동적할당 해제" << endl;
}
void LinkedList::push_back(int data)
{
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;
	newNode->Prev = nullptr;

	Node* current = _root;

	if (_root != nullptr)
	{
		while (current->Next != NULL)
		{
			current = current->Next;
		}
		current->Next = newNode;
		newNode->Prev = current;
	}
	else
	{
		_root = newNode;
	}
}
void LinkedList::pop_back()
{
	Node* currentNode = _root;
	Node* deletedNode = _root;

	if (_root != nullptr)
	{
		cout << "_root이 nullptr 입니다" << endl;
		return;
	}

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
int LinkedList::size()
{
	int count = 0;
	Node* current = _root;
	while (current->Next != nullptr)
	{
		current = current->Next;
		count++;
	}
	return count;
}
int LinkedList::at(int index)
{
	Node* current = _root;
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	return current->Data;
}
void LinkedList::remove_data(int data)
{
	Node* currentNode = _root;
	Node* deletedNode = _root;

	while (deletedNode->Data != data)
	{
		deletedNode = deletedNode->Next;
	}
	while (currentNode->Next != deletedNode)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = deletedNode->Next;
	deletedNode->Next->Prev = currentNode;

	delete deletedNode;
	deletedNode = nullptr;
}
void LinkedList::add_data(int data, int index)
{
	Node* newNode = create_node(data);
	Node* currentNode = _root;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = newNode;
	newNode->Next = currentNode->Next->Next;
	newNode->Prev = currentNode;
}
void LinkedList::test()
{
	Node* currentNode = _root;

	while (currentNode->Next != nullptr)
	{
		currentNode = currentNode->Next;
	}
	cout << "Test()" << endl;
	while (currentNode->Prev != nullptr)
	{
		cout << currentNode->Data << " ";
		currentNode = currentNode->Prev;
	}
	cout << currentNode->Data << " "; // 맨처음값

}

Node* LinkedList::create_node(int data)
{
	Node * newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;
	newNode->Prev = nullptr;

	return newNode;
}