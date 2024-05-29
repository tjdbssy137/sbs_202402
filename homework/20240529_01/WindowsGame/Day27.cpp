#include "pch.h"

void Comment1() 
{
	// 1. Flipbook 완성
	//   - duration, loop 기능

	// 2. Camera에 대해 배워볼거에요.
	//		주말숙제 2048에는 카메라 안들어갑니다!!

	// 간단하게 if 문 동작원리
	//  - 상식으로 알고있으면 알쓸신잡
}


void Comment2()
{
	// if문 동작원리

	bool conditionHeavy1 = true;	// CheckCollision (아주 조금 무거웠죠?)
	bool conditionHeavy2 = false;
	bool conditionLight3 = true;	// 
	bool conditionLight4 = false;

	// if 문에서 
	//  || 연산동작은 true를 만나면 뒤에 연산을 하지 않는다.
	if (conditionLight4 || (conditionHeavy1 && conditionLight3))
	{
		printf("해당코드가 실행된다.\n");
	}
	else
	{
		printf("else일경우 실행된다.\n");
	}

	// if문에서
	//  - && 연산자 동작은 false를 만나면 뒤에 연산을 하지 않습니다.
	if (conditionLight3 && conditionHeavy2)
	{
		printf("둘다 참이면 실행된다.\n");
	}
	else
	{
		printf("그렇지 않으면 실행한다.\n");
	}


	// 어 이제 이런걸 알았으니까
	// 의식하면서 코딩해야겠다!!!!

	// 이러진 마세요.

	// 그냥 알쓸신잡 정도로 기억해주세요.

	RECT rc1;
	RECT rc2;
	if (Input->GetKeyDown(KeyCode::D) && Collision::RectInRect(rc1, rc2))
	{

	}

	// 이정도만 습관화 해주시면 됩니다.

	//말로 바꿀때도
	// (더)희귀한거일때, 뭐뭐했으면..

	// 키보드 눌렀을때가 희귀한거 아닌가요??
}

void Comment3()
{
	//Flipbook이란?
	
	// 종이 애니메이션

	// 여러장의 종이에 비슷하게 그림그려두고
	// 한장씩 넘기는 형식으로 가지고 놀았었죠? (초중 때)

	// 유니티 에는 Animation이라고 통합되어있습니다.
	// 언리얼 은 Flipbook 이라고 되어있어요.
}

void Comment4()
{
	//실습!

	// FlipbookActor를 상속받아서
	// CreatureActor, UserCharacterController를 만들고

	// Space를 누르면 
	// Attack
	// 화살표 위아래양옆 을 누르면
	// Move
	// 가만히 있으면
	// Idle 상태 

	// 만들기.


	// + 금방하시면 몬스터까지만들어서 
	//  공격하면 몬스터 사라지게

	// 몬스터 체력구현

	// 8시반까지 .
	// 9시까지로

	// 계속 개인 교습하는형식으로 오늘 진행할게요
	// 오늘 더진도나가면 안될거같아요!

	//숙제 : 오목!! 
	// 2048할수있다! => 2048
	// 잘모르겠다. => 오목
}