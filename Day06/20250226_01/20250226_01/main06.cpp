#include <iostream>
using namespace std;

void main() 
{
	// �ݺ��� ��ȭ
	// for, do while, while

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)
		{
			continue;
			//Ȧ�� �� �� �Ʒ��� �������� �ʴ´�.
		}
		cout << i << endl;
		if (i == 10)
		{
			break;
			// exit(0); // main�� ����.
		}
	}
	printf("break�� Ż��!\n");
}