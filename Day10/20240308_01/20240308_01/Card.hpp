//헤더파일임과 동시에 CPP파일이기도함. 하지만 본질은 헤더 파일.
#pragma once

// Main 에서 Test2.hpp의 함수를 불러오고
// Test2.hpp의 함수에서는 Card.hpp를 불러오고
// Card.hpp에서는 Test2.hpp의 함수가 필요하면!
// => 문제가 발생
// 구현부가 두 번 겹치면 재정의 에러가 남.

// 항상 프로그램의 시작은 main이 있는 cpp부터 시작.
// main02.cpp
// #include "test2.hpp" => pragma once, #include "Card.hpp" (Function 구현) Function2 구현, Function3 구현
// #include "Card.hpp" => pragma once로 인해, 이미 한 번 읽은 파일은 무시

// Function1호출
// => Card.hpp에 있음
// => Card.hpp 에서는 실행하려고 보니까
//			Function3을 호출해야함.
//			Function3을 찾기 위해 include를 뒤지게 됨
//			"Test2.hpp"를 읽으려고 하니, pragma once로 인해 한 번 읽었던 파일을 무시하게 됨.
//			그래서 결과적으로 그 어디에도 찾을 수 없기에 빌드를 하면, 식별자를 찾을 수 없다고 함.

// 그래서 결론 
// 가이드.
// .h 와 .cpp에 대해 많은 걸 알고 커버할 수 있다 하는 게 아니라면 .hpp를 사용하지 않기
// 그말은 즉슨, 헤더에서 구현을 하지 말라는 말.
// 헤더는 전방선언이나 자료형 선언만.

struct Card {
	int Index;
	void Print();
	void Swap(Card &another);
};
void Card::Print()
{
	//cout << Index;
}
void Card::Swap(Card &another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}