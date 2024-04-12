void Summary()
{
	// 1. 벽돌깨기 만들기

	// 게임 만들기 위한 프레임워크
	// - 충돌 매니저
	// - Actor라는 객체
	//		씬에 등장하는 최소 단위
	//		그러면 벽돌 깨기에 등장하는 모든 객체는 Actor를 상속 받아야한다.

	// - Actor에 Collider라는 컴포넌트를 추가해서
	// - 충돌 매니저에서 알아서 관리하게 끔 만들었습니다.

	// 수도 코드는 기본 중의 기분이고
	// 게임을 만드는 거
	// 프로그램을 만드는 건
	// 먼저, 아키텍쳐를 만들어야함.

	// 아키텍쳐란?
	//	어떤 걸 Class로 만들 것인가
	//	어떤 Class랑 어떤 Class를 어떻게 접점을 만들 것인가

	// 지금 해야할 것
	// 벽돌 깨기에 들어가는 객체를 구성해보기
	
	// 1. 어떤 클래스(객체)를 만들어야하는가?
	// - 어떤 Actor를 만드어야 하는가?
	// - 어떤 Component를 만들어야 하는가?

	// 개발을 할 때 무작정 코드부터 짜기 시작하는 건 나쁜 습관임.
}

void Comment01()
{
	// Player
	// - 플레이어의 이동
	//		이동 거리 제한

	// Ball 
	// - 공의 이동
	//		이동 거리 제한
	// - 충돌 시
	//		반사
	
	// Brick
	// - 공과 충돌 시 벽돌 삭제

	// 아키텍처 : 사람마다 다르게 나올 수밖에 없음.
	//			-> 사람의 철학에 따라서 갈림.

	// 1. Paddle : Actor
	// - Move
	// 
	// 2. Ball : Actor
	// - Move
	// 
	// 3. Bricks : Actor 
	// - Broken(Destroy) Ball과 OnTriggerEnter 되었을 때
	// 
	// 4. PlayerController
	// - Update (인풋에 따라, Paddle움직일 수 있게)
	// -		(게임 처음 시작 할 때, 볼 위치)
	//
	// 5. GameState
	// - 게임 상태 알려주기
	//		지금이 대기 상태인지, 플레이 중인지.

	// 굳이 PlayerController을 만드는 이유
	// 나중에 Paddle이 추가로 생길 수 있다.
	// 아니면 나중에 기획적인 요소로 가만히 있어야하는 paddle을 추가할 수 있다.
	// 그 패들이 모두 사용자의 입력으로 움직이지 않음.
	// 그러면 그런 종류의 패들은 새롭게 만들거냐?
	//		-> if문을 계속 적다보면 코드가 더러워짐

	// SRP(단일책임원칙)
	// 하나의 클래스에는 하나의 기능만 하게 하는 것이 좋다.
}