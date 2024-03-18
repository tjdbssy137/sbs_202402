#include <iostream>
#include "BinaryTree.h"
using namespace std;

void main()
{
	BinaryTree<int> bt = {};
	bt.AddData(100);
	bt.AddData(200);
	bt.AddData(50);
	bt.AddData(250);

	cout << "bt.GetData(50) : " << bt.GetData(50) << endl;
}