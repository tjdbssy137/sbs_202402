#include <iostream>
using namespace std;

void main()
{
	// ����
	int a = 3;
	int b = 5;

	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}