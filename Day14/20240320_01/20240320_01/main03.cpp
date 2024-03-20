#include "pch.h"

#include <queue>
#include <stack>

void main()
{
	// queue, stack
	// 큐, 스택은 주로 알고리즘을 위해서 사용하는 자료구조
	// 알고리즘이 아니면, 굳이!! 사용할 필요가 엇ㅂ음
	// 코드 짤 때 거의 안 사용
	// 취업할 때 코딩테스트 용으로 잠깐 씀
	// 아주 가끔 씀 -> 길 찾기 알고리즘 (코테로 치면 레벨3~4)
	
	//vector처럼 동적 배열 데이터
	// capacity, size가 있음
	// 편의성은 없지만, 데이터를 어떻게 넣고, 어떻게 빼는 지에 대해 강제성을 주는 자료구조
	

	// queue => 선입선출 자료구조
	// 먼저 입력된 것이 먼저 출력
	// Enqueue(data)
	// Dequeue()

	// stack => 후입선출
	// 나중에 입력된 것이 먼저 출력

	queue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i + 1);
	}


}