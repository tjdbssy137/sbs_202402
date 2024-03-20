#include "pch.h"
void main()
{
	// 랜덤에 대해서 배우겠습니다.
	// 그동안 썼던 랜덤

	srand(time(NULL));
	int arr[100] = {};
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 1000; i++)
	{
		int first = rand() % 100;
		int second = rand() % 100;

		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

	// random의 문제점 2가지
	// 1. 랜덤의 max값이 32627이다.
	//	=> 절대 아닙니다.(뭐가??)
	//	=> 리니지에서 제일 비싼 아이템 확률표
	//	=> 이거를 구현할 수 없음
	
	// 2. 아무리 시드를 섞었다고 하지만, 랜덤 분포가 그렇게 이쁘게 분포되지 않음
	// 이전 수의 영향을 받아서 랜덤 뽑히는 경우가 많음.
	//

	// rand() 를 쓴 이유
	// 쉬워서.


	//만든 RandomModule
	RandomModule* randomModule = new RandomModule();

	for (int i = 0; i < 1000; i++)
	{
		cout << randomModule->GetRandomInt(0, 32627) << endl;
	}

	// auto란,
	// 빌드를 누르면 변수값에 의해서 알아서 정해짐, runtime 도중에 잡히는 게 아님.
	
	// 그런데 auto만 사용하면 안 되는 이유!
	// 회사마다 저 auto를 금지 시키는 회사 존재
	// ex) 펄어비스
}
