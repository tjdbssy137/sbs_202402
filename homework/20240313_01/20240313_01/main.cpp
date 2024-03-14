#include <iostream>
#include "LinkedList.h"
using namespace std;

void main()
{
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

	for (int i = 0; i <= link.size(); i++)
	{
		cout << "[" << i << "] = " << link.at(i) << endl;
	}
	link.test();
}