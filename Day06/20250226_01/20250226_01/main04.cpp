#include <iostream>
using namespace std;

void main()
{
	// 셔플, swap
	int a = 3;
	int b = 5;

	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	// 실습
	// 로또생성기
	// 1) 1 ~ 45까지 적힌 array를 만든다
	// 2) array를 섞는다
	// 3) 그중 7개를 뽑는다

	// A, B 스왑을 100000번 하면 셔플이다
	int arr[100] = {};
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		// 이해 안 되면 일단 외우기
		// A, B를 100000번 swap할건데
		// A, B를 고르는 기준이
		// Random index
		
		int firstIndex = rand() % 100; //arr범위 안에서 랜덤
		int SecondIndex = rand() % 100;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[SecondIndex];
		arr[SecondIndex] = temp;
		//아무리 해도 숫자가 중복되는 일은 없음.
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// homework
	// 1) 가위바위보 하나 빼기(배열사용)
	// 2) 로또생성기
	// 3) 21일 숙제 심화버전
}