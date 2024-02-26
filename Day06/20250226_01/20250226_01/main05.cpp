#include <iostream>
using namespace std;

#define MY_NUMBER = //매크로
#define ARRAY_SIZE 100 //매크로
#define ADD(a, b) a + b //매크로
#define ADD_AND_PRINT(a, b) printf("ADD start : %d, %d\n", a, b); \
                            printf("ADD Result : %d\n", a + b);
// "\" <- 연장해서 다음 줄까지 쓰겠다는 뜻


void main()
{
	//매크로
	//c++에만 존재하는 문법
	// 사용법
	// 대문자로 쓰는 게 기본.

	int a MY_NUMBER 3; //MY_NUMBER이 = 의 역할을 수행
	
	int b = ADD(5, 12);
	cout << "b = " << b << endl;

	int arr[ARRAY_SIZE] = {  };
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = i + 1;
	}
	cout << a;
}