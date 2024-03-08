#include <iostream>
#include "MainGame.h"
using namespace std;

// 클래스 선언
class Card {
private: // 접근제어를 나만 할 수 있다.
	// 클래스는 기본이 private이다.
	int MyVariable;
public : // 접근제어를 아무나 할 수 있게 함.
	int Index;

	// 구조체 함수는 원래 안 됐다가, 나중에 문법적으로 허용이 됨
	// 클래스 함수는 원래부터 가능했다.
	// 그래서 클래스와 구조체의 차이점은 기본값이 private인지, public인지의 차이다.(c++ 한정)
	void Print()
	{
		printf("class print");
	}
};

struct CardStruct {
private:

public:
	// 구조체는 기본이 public 이고
	int Index;
};

void main()
{
	// class
	// 뉴비 절단기 2호

	// class = struct
	
	// 클래스 사용
	// 클래스는 구조체랑 동일하게 사용자 정의 자료형.

	Card card = {};
	card.Index = 0;

	CardStruct cardStruct = {};
	cardStruct.Index = 1;

	//C++만 특이하기에, 
	// 일반적인 클래스 특징은 짚고 넘어가자.
	// 클래스 - 많은 언어에서 클래스는 heap에 할당 됨.(동적 메모리라는 뜻) 
	// 구조체 - 많은 언어에서 구조체는 stack에 할당 됨.(정적 메모리라는 뜻)
	
	// [주로 heap은 데이터가 큰 것을 다룬다]
	// 클래스 자료형 -> 객체(= 자아가 있는)
	// 구조체 자료형 -> 데이터(= 자아가 없는)
	// 사실 구조체를 제외한 모든 내용을 클래스라고 생각하는 게 편함.
	// 
	// 클래스 - 많은 언어에서 클래스는 heap에 할당 됨.(동적 메모리라는 뜻) 
	// C++에서도 보통 클래스는 new를 사용.
	// 클래스를 당장은 이렇게 사용해주세요.
	// 소스파일 추가 -> 클래스 -> 클래스 이름 : MainGame -> 
	//

	MainGame* mainGame = new MainGame();
	delete mainGame;
	//MainGame_BlackJack* mainGame = new MainGame_BlackJack();
}