#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
	// 당분간 숙제는 외우는 것
	// 자료구조는 게임클라이언트에게 매우 중요.
	// 한 번 씩 외워보기.
	LinkedList link;

	link.push_back(10);
	link.push_back(20);
	link.push_back(20);
	link.push_back(30);
	link.pop_back();
	link.push_back(40);
	link.pop_back();
	link.remove_data(20);
	link.add_data(99, 1);
	link.push_back(50);

	for (int i = 0; i < link.size(); i++)
	{
		cout << "[" << i << "] = " << link.at(i) << endl;
	}
	return 0;

	//자료구조 / 알고리즘 에서 중요하게 다루는게 있습니다.
	//시간복잡도
	//시간복잡도가 무엇이냐??
	// 어떠한 함수를 실행했을떄
	// 걸리는 시간 기댓값
	// (그 함수안에서 포문 얼마나 도냐?)
	// 시간복잡도가

	//그 자료구조의 데이터가 N개라고 가정할때
	//O(n) => n번 순환한다.
	//O(n) + O(n) => O(n)
	//최적화 수치가 같다.
	//코어 엔진단,, 

	// 실제로 컨텐츠쪽 프로그래밍 현업에서는 시간복잡도자체를
	// 사람들이 몰라요.

	//LinkedList는 기본적으로
	// 대부분의 함수가 O(n)이다.
	// 이게 추가 / 삭제 에서는 O(n)이 되게 좋게보이지만
	// 조회에서 O(n)이 걸리는건 아주아주 큰 단점!!


	int arr[10] = {};
	// 5번째인덱스 어떻게 접근할까?
	// arr[5]하면됨
	// 이게 내부적으로 어떤 일을하냐?
	// arr 포인터에 + 5를한게 끝입니다
	// 이건 시간복잡도 O(1)
}