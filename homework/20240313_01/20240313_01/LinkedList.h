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
public: // LinkedList.cpp를 제외한 외부 파일에서도 호출이 가능.
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
private:
	Node* create_node(int data); // LinkedList.cpp를 제외한 외부 파일에서 호출이 불가능.
};

