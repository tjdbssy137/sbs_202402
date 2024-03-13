#pragma once
struct Node
{
	int Data; // 자기자신 데이터
	Node* Next; // 다음 데이터를 가르키는 포인터
};

class LinkedList
{
private:
	// 멤버 변수 적는 곳
	Node* _root = nullptr; // 동적할당 >> nullptr 형태일 수도 있어서. 즉, 데이터가 없을 수도 있기 때문이다,

public:
	LinkedList();
	~LinkedList();
	// 함수별로 구분 짓는 느낌으로도 퍼블릭을 사용.
	// 몬스터랑 상호작용하는 부분을 구현해놓는 public, 생성자 소멸자를 정의해놓은 public..
public:
	// list 마지막에 데이터를 넣는다.
	void push_back(int data);
	void pop_back();
	int at(int index);
	// MS에서 C++ 관련 만든 함수들은
	// 다 snake case라고
	// 소문자로 쓰고 띄어쓰기를 _로 함.

	// C#에서는 함수를 모두 대문자로 시작하고 띄어쓰기 마다 대문자로 강세를 줌.

	// 통일 되게 맞춰주기만 하면 됨.

	void remove_data(int data);
	// 데이터 값을 판별하여 그 노드를 삭제
	// 중복된 데이터가 있으면 앞의 인덱스 데이터를 삭제
	void add_data(int data, int index);
	// 내가 원하는 인덱스에 데이터 넣기

	int size();
};

