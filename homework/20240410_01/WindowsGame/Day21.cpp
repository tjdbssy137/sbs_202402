void Summary()
{
	// md 파일 (markdown)
	
	// 회사에서 자주 쓰이는
	// 슬랙, 노션 등등 모두 markdown 기반으로 만들어진 프로그램이다.

	// 그리고 회사에서 코드 문서화할 때 md 파일을 많이 사용

	// 유일하게 visual studio 단점이라고 생각하는 게
	// md 파일을 공식적으로 지원을 안 함.



	// 오늘 배울 것
	// 1. Actor, GameObject 개념 배우기
	// 2. Collision Manager
	// 3. 벽돌 깨기 만들기
}

void Comment1()
{
	// 1. Actor, GameObject
	// - 두 엔진(Unity, Unreal Engine)의 철학 차이
	// - Unity에서는 GameObject라고 부르고, Unreal Engine에서는 Actor라고 부름

	// Unity에서는 GameObject
	// -Scene에 [존재/등장]하는 최소 단위

	// - Unreal Engine에서 Actor란
	// - Scene에 등장하는 최소 단위

	// - Unreal Engine : Actor (배우)
	//		-> 우리는 영화를 만들건데, 여기에 등장하는 배우들을 위한 자료형이다
	//		-> 등장하는 것들을 위주로 많이 작성합니다.
	//			-> e.g. Enemy, Player, Brick, Wall
	
	// - Unity : GameObject (프로그래밍 자료형의 가장 기초 단위)
	//		-> Scene에서 동작하려면 GameObject를 무조건 생성해라
	//		-> 그리고 GameObject끼리 상화작용으로 게임을 만들 것이다.
	//		-> 이뜻은 게임에 등장하지 않아도 존재하는 것만으로도 효과를 낼 존재도 GameObject여야 한다. 
	 
	// Unreal Engine : Actor 자료형을 상속 받아서, Player을 만든다.
	//	-> Actor가 아니면 불가능한 게 너무 많아서 Actorㄹ르 상속 받아서 만들 수 밖에 없음
	// 
	// Unity : GameObject에  Component로 Player라는 Component를 붙임.
	// -> GameObject를 상속 받아서 무언가를 만들 수 없음.

	// 이름은 Actor라고 지어주고
	//	언리얼 뉘앙스로 따라감.


	// Unity -> Collider가 Component로 들어감
	// Unreal -> Actor 안에서 설정하게 끔 되어있음. (내부적으로 Component)

}

void Comment2()
{
	// Component
	
	// 컴포넌트가 게임에서 되게 중요한 패턴
	
	// CBD
	// Component Based Development
	// 컴포넌트 기반의 프로그래밍

	// 패턴 -> 기법 -> 꼼수
	// 디자인 패턴
	// 컴포넌트 패턴이라고 하는 디자인 패턴이 존재함.

	// 객체 하나를 만들고
	// 여기에 여러가지 Component를 붙여서
	// 객체 하나를 여러가지 느낌으로 커스텀마이징 가능하도록 만드는 기법

	// 1초마다 몇 미터씩 움직이는 Component가 있다
	// 은신상태를 하게 하는 Component가 있다
	
	// 
}