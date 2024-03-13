#pragma once
struct Node
{
	int Data; // �ڱ��ڽ� ������
	Node* Next; // ���� �����͸� ����Ű�� ������
};

class LinkedList
{
private:
	// ��� ���� ���� ��
	Node* _root = nullptr; // �����Ҵ� >> nullptr ������ ���� �־. ��, �����Ͱ� ���� ���� �ֱ� �����̴�,

public:
	LinkedList();
	~LinkedList();
	// �Լ����� ���� ���� �������ε� �ۺ��� ���.
	// ���Ͷ� ��ȣ�ۿ��ϴ� �κ��� �����س��� public, ������ �Ҹ��ڸ� �����س��� public..
public:
	// list �������� �����͸� �ִ´�.
	void push_back(int data);
	void pop_back();
	int at(int index);
	// MS���� C++ ���� ���� �Լ�����
	// �� snake case���
	// �ҹ��ڷ� ���� ���⸦ _�� ��.

	// C#������ �Լ��� ��� �빮�ڷ� �����ϰ� ���� ���� �빮�ڷ� ������ ��.

	// ���� �ǰ� �����ֱ⸸ �ϸ� ��.

	void remove_data(int data);
	// ������ ���� �Ǻ��Ͽ� �� ��带 ����
	// �ߺ��� �����Ͱ� ������ ���� �ε��� �����͸� ����
	void add_data(int data, int index);
	// ���� ���ϴ� �ε����� ������ �ֱ�

	int size();
};

