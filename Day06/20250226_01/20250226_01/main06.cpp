#include <iostream>
using namespace std;

void main() 
{
	// 반복문 심화
	// for, do while, while

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)
		{
			continue;
			//홀수 일 때 아래를 실행하지 않는다.
		}
		cout << i << endl;
		if (i == 10)
		{
			break;
			// exit(0); // main이 끝남.
		}
	}
	printf("break는 탈출!\n");
}