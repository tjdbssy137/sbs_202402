#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	cout << "동적 데이터 할당" << endl;
}
LinkedList::~LinkedList()
{
	cout << "동적 데이터 해제" << endl;
}
void LinkedList::push_back(int data)
{
	Node *newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	Node *current = _root;
	if (_root == NULL)
	{
		_root = newNode;
	}
	else// 이거 없으면 안 됨.
	{
		while (current->Next != NULL)
		{
			current = current->Next;
		}
		current->Next = newNode;
	}
}
void LinkedList::pop_back()
{
	Node* currentNode = _root;
	Node* deleteNode = _root;
	while (deleteNode->Next != NULL)
	{
		deleteNode = deleteNode->Next;
	}
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = nullptr;
	delete deleteNode;
	deleteNode = nullptr;
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

int LinkedList::size()
{
	Node* current = _root;
	int count = 0;
	while (current->Next != NULL)
	{
		current = current->Next;
		count++;
	}
	return count;
}
void LinkedList::remove_data(int data)
{
	Node* currentNode = _root;
	Node* deleteNode = _root;
	while (deleteNode->Data != data)
	{
		deleteNode = deleteNode->Next;
	}
	while (currentNode->Next != deleteNode)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = deleteNode->Next;

	delete deleteNode;
	deleteNode = nullptr;
}
void LinkedList::add_data(int data, int index)
{
	Node* currentNode = _root;
	Node* newNode = new Node();
	newNode->Data = data;
	newNode->Next = nullptr;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}
	newNode->Next = currentNode->Next;
	currentNode->Next = newNode;
}