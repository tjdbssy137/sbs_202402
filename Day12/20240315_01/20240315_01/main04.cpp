#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	// <vector�� Linked List�� ����>
	// Linked List : �ּҰ��� �� �ڴ�δ�.
	//		-> ���� : �߰� �߰�/������ ����.
	//		-> ���� : �ܼ� ��ȸ�� ������.
	// vector : �ּҰ��� ����Ǿ� �ִ�.
	//		-> ���� : �ܼ� ��ȸ�� ���� ������.
	//		-> ���� : Ư�̻��� �߻� �� ���� �� �ִ�.
	//				(capacity ������ ��)
	
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