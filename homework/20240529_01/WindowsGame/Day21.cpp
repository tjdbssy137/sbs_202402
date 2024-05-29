#include "pch.h"
void Comment1()
{
	//md 파일 (markdown)

	//회사에서 자주쓰이는
	// 슬랙, 노션 등등 모두 markdown 기반으로 만들어진 프로그램 입니다.

	// 그리고 회사에서 코드 문서화할때
	// md 파일을 많이 사용합니다.

	//유일하게 visual studio 단점이라고 생각되는게
	//저 md 파일이 공식적으로 지원을 안해요. (Preview버전에서는 지원한다고 예전에 본적있는데)
}

void Comment2()
{
	//오늘 배울거

	//1. Actor, GameObject 개념 배우기
	//2. Collision Manager
	//3. 벽돌깨기 만들기
}

void Comment3()
{
	//1. Actor, GameObject
	// - 두 엔진의 철학차이
	//   => Unity, Unreal Engine의 철학차이입니다.
	// 
	// - Unity에서는 GameObject라고 부릅니다.
	// - Unreal에서는 Actor라고 부릅니다.
	// 
	// - Unity에서 GameObject란 
	//  - Scene에 [존재/등장]하는 최소 단위

	// - Unreal에서 Actor란
	//  - Scene에 등장하는 최소 단위

	// Unreal : Actor (배우)
	// Unity : GameObject (프로그래밍 자료형의 가장 기초단위)


	// Unreal : 우리는 영화를 만들건데, 여기에 등장하는 배우들을 위한 자료형이다.
	//		등장하는 것들을 위주로 많이 작성합니다
	//		(Enemy, Player, Brick, Wall)

	// Unity : 자료형의 가장 기초단위
	//			- Scene에서 동작하려면 GameObject를 무조건 생성해라.
	//			- 그리고 GameObject 끼리 상호작용으로 게임을 만들것이다.
	//			- 이뜻은 게임에 등장하지 않아도 존재하는것만으로도 효과를 낼 존재도 GameObject여야한다.

	// 저희만의 Framework
	// 그리고 사실 유니티나 언리얼이나 만들때 비슷합니다.
	// Player를 만들고싶다.
	
	// Unreal : Actor자료형을 상속받아서, Player 를 만듭니다.
	//		Actor가 아니면 불가능한게 너무 많아서 Actor를 상속받아서 만들수밖에 없습니다.
	
	// Unity : GameObject에 Component로 Player라는 Component를 붙입니다.
	//		GameObject를 상속받아서 무언가를 만들수가 없습니다.


	//이름은 Actor지어주고
	// 언리얼 늬양스로 좀 따라갈게요



	//Unity -> Collider 가 Component로 들어갑니다
	//Unreal -> Actor안에서 설정하게끔 되어있어요 (내부적으론 Component)

}

void Comment4()
{
	//Component (컴포넌트)

	//컴포넌트가 게임에서 되게 중요한 패턴

	//CBD 
	//Component Based Development
	//컴포넌트 기반의 프로그래밍

	// 패턴 => 기법 => 꼼수
	// 디자인패턴
	// 컴포넌트 패턴이라고는 디자인패턴이 존재합니다.

	// 객체하나를 만들고
	// 여기에 여러가지 Component를 붙여서
	// 객체하나를 여러가지 느낌으로 커스텀마이징 가능하도록 만드는 기법

	// 1초마다 몇미터씩 움직이는 Component
	// 은신상태를 하게하는 Component가 있다.

	// 롤 - 상태이상
	//  - StunComponent
	//  - 은신컴포넌트
}