#include <iostream>
using namespace std;

int  MyFunction(int _In_ inTest, int* _Out_ outTest)
{
	*outTest = 100;
	printf("In : %d\n", inTest);
	return 0;
}

void main()
{
	int a = 0;
	int b = 1;
	::MyFunction(a, &b);

}