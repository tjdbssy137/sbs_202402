#pragma once
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
	struct Node
	{
		T Data;
		Node* Parent;
		Node* Left;
		Node* Right;
	};
	Node* _root = nullptr;
private:// node�� �ܺο��� �������� �� ��. �ܺ�ȣ���� ����.
	// private�� public���� �Լ��� �з����� ��, �ڽ��� Ȯ���� ������ �־����.
	Node* CreateNode(T data)
	{
		Node* newNode = new Node();
		newNode->Parent = nullptr;
		newNode->Left = nullptr;
		newNode->Right = nullptr;
		newNode->Data = data;
		return newNode;
	}
	Node* GetNode(T data) {
		Node* current = _root;
		while (current != NULL)
		{
			if (current->Data < data)
			{
				current = current->Right;
			}
			else if (data < current->Data)
			{
				current = current->Left;
			}
			else if (current->Data == data)
			{
				return current;
			}
		}
		return nullptr;
	}
	void RemoveNode(Node* removeNode);
public:
	BinaryTree();
	~BinaryTree(); 
public:
	void AddData(T data);
	int GetData(T data);//��� ��ȸ������, ������ ���� �ٸ� ������ �¿�����.
	void RemoveData(T data);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	cout << "�����Ҵ�" << endl; // ���� �� ĭ�� �����.
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	cout << "�����Ҵ�����" << endl;
	if (_root)
	{
		delete _root;
		_root = nullptr;
	}
}

template <typename T>
void BinaryTree<T>::RemoveNode(BinaryTree<T>::Node* removeNode)
{
	if (removeNode->Parent->Left == removeNode)// ���� ���� ����Ű�� �ִ���?
	{
		//1. ���� ���� ��� ������� ��
		//2. ���� ������ ������� ��
		//3. �����ʸ� ������� ��
		//4. �Ѵ� ���� ��
		if (removeNode->Left != nullptr && removeNode->Right != nullptr)
		{
			//���� �� ����
			printf("Error\n");
			return;
		}
		else if (removeNode->Left != nullptr && removeNode->Right == nullptr)
		{
			//���� �θ� �ڱ�� �ø��� �ڱ� �ڽ��� �����
			//�� = �θ��� ����
			removeNode->Parent->Left = removeNode->Left;
			removeNode->Left->Parent = removeNode->Parent;
		}
		else if (removeNode->Left = nullptr && removeNode->Right != nullptr)
		{
			//������ �θ� �ڱ�� �ø��� �ڱ� �ڽ��� �����
			//�� = �θ��� ����
			removeNode->Parent->Left = removeNode->Right;
			removeNode->Right->Parent = removeNode->Parent;
		}
		else if (removeNode->Left == nullptr && removeNode->Right == nullptr)
		{
			//�θ��� ������ ����� �ڱ��ڽ��� �����.
			removeNode->Parent->Left = nullptr;
		}
	}
	else
	{
		if (removeNode->Left != nullptr && removeNode->Right != nullptr)
		{
			//���� �� ����
			printf("Error\n");
			return;
		}
		else if (removeNode->Left != nullptr && removeNode->Right == nullptr)
		{
			//���� �θ� �ڱ�� �ø��� �ڱ� �ڽ��� �����
			//�� = �θ��� ������
			removeNode->Parent->Right = removeNode->Left;
			removeNode->Left->Parent = removeNode->Parent;
		}
		else if (removeNode->Left = nullptr && removeNode->Right != nullptr)
		{
			//������ �θ� �ڱ�� �ø��� �ڱ� �ڽ��� �����
			//�� = �θ��� ������
			removeNode->Parent->Right = removeNode->Right;
			removeNode->Right->Parent = removeNode->Parent;
		}
		else if (removeNode->Left == nullptr && removeNode->Right == nullptr)
		{
			//�θ��� ������ ����� �ڱ��ڽ��� �����.
			removeNode->Parent->Left = nullptr;
		}
	}

	//�ڱ��ڽ��� �����
	delete removeNode;
	removeNode = nullptr;
}

template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// �����ڵ�
	// 1. _root�� null�̸�
	// 2. _root�� ���� �־��ְ� ����
	if (_root == nullptr)
	{
		Node* newNode = CreateNode(data);
		_root = newNode;
	}

	//���� ���� �ڸ��� ã�´�
	// 1. current�� _root�� �޾��ش�,.
	Node* current = _root;
	while (current != NULL)
	{
		//current->data�� �� ������
		if (current->Data < data)
		{	
			//�������� ��������� �����ʿ� �߰����ְ� ����.
			if (current->Right == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Right = newNode;
				newNode->Parent = current;
				return;
			}
			current = current->Right;
		}
		//current->data�� �� ũ��
		else if (data < current->Data)
		{
			// ������ ��������� ���ʿ� �߰����ְ� ����
			if (current->Left == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Left = newNode;
				newNode->Parent = current;
				return;
			}
			current = current->Left;
		}
		else
		{
			return;
		}
	}
}
template <typename T>
int BinaryTree<T>::GetData(T data)
{
	Node* findNode = this->GetNode(data);
	if (findNode)
	{
		return findNode->Data;
	}
	else
	{
		return NULL;
	}
}
template <typename T>
void BinaryTree<T>::RemoveData(T data)
{
	Node* currentNode = _root;
	Node* deletedNode = nullptr;
	Node* replaceNode = nullptr;

	// 1. ���� ��带 ã�´�
	deletedNode = this->GetNode(data);

	// 2. ���� ����� ��ü ��带 ã�´�.
	// ��ü ���� ���� ����� ������ ���� �������̴�.
	// **������ ������ = �� �� ���� ���� ���߿� ���� ū ��.
	// **�������� ���� = �� �� ���� ū �� �߿� ���� ���� ��.
	if(deletedNode->Left == nullptr)
	{
		// ������ ����ִ� ��쿣 �������� ���� ����
		if (deletedNode->Right == nullptr)
		{
			//�����ʵ� ���������, �� ��带 ����� �Լ��� �����Ѵ�.
			this->RemoveNode(deletedNode);
			return;
		}
		else
		{// ���� ����� ���� �������� ������ ã�´�.
			replaceNode = deletedNode->Right;
			while (replaceNode->Left != nullptr)
			{
				replaceNode = replaceNode->Left;
			}
		}
	}
	else
	{
		//���� ����� ������ ���� �������� ã�´�.
		replaceNode = deletedNode->Left;
		while (replaceNode->Right != nullptr)
		{
			replaceNode = replaceNode->Right;
		}
	}

	// 3. ���� ����� �����͸� ��ü �����ͷ� �ű��.
	deletedNode->Data = replaceNode->Data;
	// 4. ��ü�� ��带 �����.
	this->RemoveNode(replaceNode);
}