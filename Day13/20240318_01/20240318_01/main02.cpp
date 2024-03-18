#include <iostream>
#include "MyVector.h"
using namespace std;

void main()
{
	MyVector<int> arr = {};
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr[1] = 60;
	arr.insert(2, 80);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << endl;
	}
}