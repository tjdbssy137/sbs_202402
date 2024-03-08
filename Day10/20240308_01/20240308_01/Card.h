//#pragma once
// 이 파일을 한 번만 선언하게 만들겠다. 라는 코드.
// 이 코드를 사용하지 않으면, 재정의 관련 error가 뜰 수 있다.

//__CARD2_H__라는 매크로가 선언되어 있지 않으면
#ifndef __CARD_H__
#define __CARD_H__
struct Card {
	int Index;
	void Print();
	void Swap(Card &another);
};

//변수선언을 헤더에서 하러면 extern 키워드를 붙여야 한다.
// main이 있는 .cpp파일에서 한 번 더 선언을 해주어야 한다.
extern int _a; //다른 파일에서도 _a라는 변수를 사용하겠다는 뜻.
// main 함수에서 선언 예시 >> int _a;
int _b;// include를 하더라도 다른 파일에서 사용 불가.

//__CARD2_H__를 선언 한다.
#endif // !__CARD2_H__
// 이렇게 하므로서, 헤더파일은 무조건 한 번만 include된다. 라는 효과를 얻을 수 있음.

//하지만 
#ifndef __CARD_H__
#define __CARD_H__
#endif // !__CARD_H__
//를 쓰는 건 번거로움
// =>> #pragma once 이게 그 해결 책!!
// #pragma once만 맨 위에 쓰면 한 번만 include됨.


/*
#ifdef __CARD2_H__ // 선언이 되어 있으면 아래 main문 실행
void main() {

}
#endif // __CARD2_H__

*/