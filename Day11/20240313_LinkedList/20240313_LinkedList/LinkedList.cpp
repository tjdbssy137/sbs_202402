#include "LinkedList.h"
#include <iostream>
using namespace std;

//숙제
// 1. 외우기 (1. LinkedList.h, 2. LinkedList.cpp)
// 2. prev를 만들기.

// 자료 구조 / 알고리즘에서 중요하게 다루는 것
// 시간 복잡도
// 어떠한 함수를 실행했을 때 걸리는 시간 기댓값
// 그 함수 안에서 for문을 얼마나 도는 지.


// 그 자료구조의 데이터가 n개라고 가정할 떄
// O(n) -> n번 순환한다.
// O(n) + O(n) = O(n)
// 최적화 수치가 같다.

// 실제로 컨텐츠쪽 프로그래밍 현업에서는 시간복잡도 자체를 모름.


LinkedList::LinkedList()
{
	cout << "동적할당" << endl;
}

void LinkedList::push_back(int data)
{
	//<마지막에 데이터를 넣는다>
	// 수도 코드 작성
	// 수도코드를 알면 이 자료구조의 장단점을 알 수 밖에 없음.
	
	// newNode를 만들어준다.
	// _root 값을 복사한다
	// current = _root;
	// --
	// _root가 NULL이 아니라면
	// current의 Next가 null이 될 때까지
	// current를 Next로 넘긴다.
	// newNode의 주소를 current Next에 대입 시킨다.
	// --
	// _root가 NULL이라면
	// _root에 newNode를 대입 시킨다.

	Node* newNode = new Node(); // 동적할당
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
	// 수도코드
	// deletedNode를 만든다.
	// currentNode를 만든다.
	// deletedNode를 가장 마지막으로 보낸다.
	// currentNode의 Next가 deletedNode가 나올 때까지 옆으로 넘긴다.
	// deletedNode를 지운다.
	// currentNode의 Next를 NULL로 처리해준다.
	if (_root != nullptr)
	{
		cout << "_root이 nullptr 입니다" << endl;
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
	// 수도코드
	// current를 생성한다
	// (index)번 만큼 Next로 이동한다
	// 그 값을 return한다.

	Node* current = _root;
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	return current->Data;
}

void LinkedList::remove_data(int data)
{
	// 데이터 값을 판별하여 그 노드를 삭제
	// 중복된 데이터가 있으면 앞의 인덱스 데이터를 삭제

	// 수도코드
	// currentNode와 deleteNode를 만든다
	// 원하는 데이터를 얻을 때까지 deleteNode를 넘긴다
	// currentNode->Next 가 deleteNode가 될 때까지 넘긴다.
	// currentNode->Next를 deleteNode->Next로 바꾼다
	// deleteNode를 삭제한다.
	// 
	// 그전 데이터와 그다음 데이터를 연결.

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
	endNode = nullptr;//웬만하면 하기.
}
void LinkedList::add_data(int data, int index)
{
	// 내가 원하는 인덱스에 데이터 넣기
	// currentNode를 만든다.
	// (index)번 currentNode의 위치를 옮기기
	// data를 갖고 있는 newNode 생성
	// newNode->Next를 currentNode->Next를 바꾼다
	// currentNode->Next를 newNode로 바꾼다.

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
	cout << "동적할당 해제" << endl;
}