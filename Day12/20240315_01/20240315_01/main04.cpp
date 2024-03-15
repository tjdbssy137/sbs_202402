#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	// <vector와 Linked List의 차이>
	// Linked List : 주소값이 지 멋대로다.
	//		-> 장점 : 중간 추가/삭제가 쉽다.
	//		-> 단점 : 단순 조회가 느리다.
	// vector : 주소값이 연결되어 있다.
	//		-> 장점 : 단순 조회가 아주 빠르다.
	//		-> 단점 : 특이사항 발생 시 느릴 수 있다.
	//				(capacity 오버될 때)
	
	MyVector<int> vec = {};
	
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec[0] = 60;
	cout << "\nvec[0] : " << vec[0] << endl;
	cout << endl;

	vec.insert(1, 5);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	return 0;
}