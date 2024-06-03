#include <iostream>
#include "PriorityQueue.h"
using namespace std;

void main()
{
	PriorityQueue<int> q;
	q.Push(20);
	q.Push(100);
	q.Push(50);
	q.Push(35);
	q.Push(150);
	q.Push(1);

	while (false == q.Enmpty())
	{
		cout << q.Peek() << endl;
		q.Pop();
	}
}