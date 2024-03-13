#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
	// 당분간 숙제는 외우는 것
	// 자료구조는 게임클라이언트에게 매우 중요.
	// 한 번 씩 외워보기.
	LinkedList link;

	link.push_back(10);
	link.push_back(20);
	link.push_back(20);
	link.push_back(30);
	link.pop_back();
	link.push_back(40);
	link.pop_back();
	link.remove_data(20);
	link.add_data(99, 1);
	link.push_back(50);

	for (int i = 0; i < link.size(); i++)
	{
		cout << "[" << i << "] = " << link.at(i) << endl;
	}
	return 0;
}