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
private:// node는 외부에서 가져가면 안 됨. 외부호출을 막음.
	// private과 public으로 함수를 분류했을 때, 자신의 확고한 이유가 있어야함.
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
	int GetData(T data);//얘는 조회용이지, 수정할 때는 다른 로직을 태워야함.
	void RemoveData(T data);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	cout << "동적할당" << endl; // 보통 이 칸을 비워둠.
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	cout << "동적할당해제" << endl;
	if (_root)
	{
		delete _root;
		_root = nullptr;
	}
}

template <typename T>
void BinaryTree<T>::RemoveNode(BinaryTree<T>::Node* removeNode)
{
	if (removeNode->Parent->Left == removeNode)// 같은 곳을 가르키고 있는지?
	{
		//1. 양쪽 갈래 모두 살아있을 때
		//2. 왼쪽 갈래만 살아있을 때
		//3. 오른쪽만 살아있을 때
		//4. 둘다 없을 때
		if (removeNode->Left != nullptr && removeNode->Right != nullptr)
		{
			//들어올 수 없음
			printf("Error\n");
			return;
		}
		else if (removeNode->Left != nullptr && removeNode->Right == nullptr)
		{
			//왼쪽 부모를 자기로 올리고 자기 자신을 지운다
			//나 = 부모의 왼쪽
			removeNode->Parent->Left = removeNode->Left;
			removeNode->Left->Parent = removeNode->Parent;
		}
		else if (removeNode->Left = nullptr && removeNode->Right != nullptr)
		{
			//오른쪽 부모를 자기로 올리고 자기 자신을 지운다
			//나 = 부모의 왼쪽
			removeNode->Parent->Left = removeNode->Right;
			removeNode->Right->Parent = removeNode->Parent;
		}
		else if (removeNode->Left == nullptr && removeNode->Right == nullptr)
		{
			//부모의 왼쪽을 지우고 자기자신을 지운다.
			removeNode->Parent->Left = nullptr;
		}
	}
	else
	{
		if (removeNode->Left != nullptr && removeNode->Right != nullptr)
		{
			//들어올 수 없음
			printf("Error\n");
			return;
		}
		else if (removeNode->Left != nullptr && removeNode->Right == nullptr)
		{
			//왼쪽 부모를 자기로 올리고 자기 자신을 지운다
			//나 = 부모의 오른쪽
			removeNode->Parent->Right = removeNode->Left;
			removeNode->Left->Parent = removeNode->Parent;
		}
		else if (removeNode->Left = nullptr && removeNode->Right != nullptr)
		{
			//오른쪽 부모를 자기로 올리고 자기 자신을 지운다
			//나 = 부모의 오른쪽
			removeNode->Parent->Right = removeNode->Right;
			removeNode->Right->Parent = removeNode->Parent;
		}
		else if (removeNode->Left == nullptr && removeNode->Right == nullptr)
		{
			//부모의 왼쪽을 지우고 자기자신을 지운다.
			removeNode->Parent->Left = nullptr;
		}
	}

	//자기자신을 지운다
	delete removeNode;
	removeNode = nullptr;
}

template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// 수도코드
	// 1. _root가 null이면
	// 2. _root에 값을 넣어주고 종료
	if (_root == nullptr)
	{
		Node* newNode = CreateNode(data);
		_root = newNode;
	}

	//내가 넣을 자리를 찾는다
	// 1. current를 _root로 받아준다,.
	Node* current = _root;
	while (current != NULL)
	{
		//current->data가 더 작으면
		if (current->Data < data)
		{	
			//오른쪽이 비어있으면 오른쪽에 추가해주고 종료.
			if (current->Right == nullptr)
			{
				Node* newNode = CreateNode(data);
				current->Right = newNode;
				newNode->Parent = current;
				return;
			}
			current = current->Right;
		}
		//current->data가 더 크면
		else if (data < current->Data)
		{
			// 왼쪽이 비어있으면 왼쪽에 추가해주고 종료
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

	// 1. 지울 노드를 찾는다
	deletedNode = this->GetNode(data);

	// 2. 지울 노드의 대체 노드를 찾는다.
	// 대체 노드는 지울 노드의 왼쪽의 가장 오른쪽이다.
	// **왼쪽의 오른쪽 = 내 거 보다 작은 것중에 가장 큰 것.
	// **오른쪽의 왼쪽 = 내 거 보다 큰 것 중에 가장 작은 것.
	if(deletedNode->Left == nullptr)
	{
		// 왼쪽이 비어있는 경우엔 오른쪽의 가장 왼쪽
		if (deletedNode->Right == nullptr)
		{
			//오른쪽도 비어있으면, 그 노드를 지우고 함수를 종료한다.
			this->RemoveNode(deletedNode);
			return;
		}
		else
		{// 지울 노드의 가장 오른쪽의 왼쪽을 찾는다.
			replaceNode = deletedNode->Right;
			while (replaceNode->Left != nullptr)
			{
				replaceNode = replaceNode->Left;
			}
		}
	}
	else
	{
		//지울 노드의 왼쪽의 가장 오른쪽을 찾는다.
		replaceNode = deletedNode->Left;
		while (replaceNode->Right != nullptr)
		{
			replaceNode = replaceNode->Right;
		}
	}

	// 3. 지울 노드의 데이터를 대체 데이터로 옮긴다.
	deletedNode->Data = replaceNode->Data;
	// 4. 대체된 노드를 지운다.
	this->RemoveNode(replaceNode);
}