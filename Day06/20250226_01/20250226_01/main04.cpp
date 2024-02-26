#include <iostream>
using namespace std;

void main()
{
	// ¼ÅÇÃ
	int a = 3;
	int b = 5;

	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}