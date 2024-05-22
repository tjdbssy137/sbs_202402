#include <iostream>
using namespace std;

void main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << i * 4 + j % 4 << endl;
		}
	}
}