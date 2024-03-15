#pragma once
struct Node {
	int Data;
	Node* Next;
};
class LinkedList
{
private:
	Node* _root = nullptr;
public:
	LinkedList();
	~LinkedList();
public:
	void push_back(int data);
	void pop_back();
	int at(int index);
	int size();
	void remove_data(int data);
	void add_data(int data, int index);
};

