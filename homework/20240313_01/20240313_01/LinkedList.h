#pragma once
struct Node {
	int Data;
	Node* Prev;
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
	int size();
	int at(int index);
	void remove_data(int data);
	void add_data(int data, int index);
	void test();
};

