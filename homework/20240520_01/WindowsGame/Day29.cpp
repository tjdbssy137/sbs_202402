void Comment01()
{
	//- 앞으로 4개월 차에 공부할 것
	//		- 제대로된 게임 만들기
	
	//- 5개월 차에
	//		- 웹 서버 만들기
	//		- C# 배움(얕게)
	
	//- 6개월 차에
	//		- 게임 소켓 서버를 배울 지 
	//		- Direct X 배울지,
	//		- 포트폴리오 만들 시간을 가질 지,
	//		- 코딩 테스트를 할 지,
	// 택 1

	// ctrl + c + f 누르면 키워드 관련해서 찾기 쉬움
	// 코딩테스트 공부법,,
	// - 백준으로 하는 것이 좋은 듯
	// - 수도코드를 짜고
	// - 수도 코드를 내가 원하는 문법으로 바꾸는 게 <코딩 테스트>
	
	// 코딩 테스트 공부법
	// 1) 수도코드를 코드로 바꾸는 것
	// 2) 문제 이해력 -> 공부 안 하면 안 됨,,
	//		-> 알고리즘 유형 약 30개 정도에서 지문만 살짝 변경해서 나옴.
	//			- 알고리즘 유형은 자료집이 되게 많음
	//			- 프로그래머스, 책 etc..
	//			- 딱 한권만 사서 알고리즘을 외우거나, 한 번씩 따라 써보면 됨.
	//			- 코딩 테스트 공부 시점 (취준)
	//			- 하루 10시간 공부 기준 : 하루 5시간(코테 준비) + 5시간(이력서 쓰는 시간)
	//			- 이렇게 한 달하면 다 배움.

	// 코딩테스트
	// 1. 현업에서 쓸데 없다. (현업도 공부 안한지 오래되면 못 함)
	// 2. 근데 왜 보는 건지..? << 성의 문제.
}

void Comment02()
{
	// 4개월 차 중순까지는 프레임워크 완료
	// 그이후로는 포트폴리오점검 느낌으로 1:1
	// 이때는 웬만하면 오프라인 수업 추천
}

void Comment03()
{
	// 공격모션 하는 건
	// 수도코드 연장선에서 안 바뀜.
	
	// 1. 카메라
	// 2. 충돌체크 마무리 (그동안 충돌체크가 BoxCollider 밖에 없었음. CircleCollider까진 있어야 함)
	// 3. 시간 되면, UI 기초
}

void Commnet04()
{
	// 카메라란?
	// 씬을 구성하는 큰 단위에서
	// - 1. 카메라
	// - 2. World
	// 게임에서 Camera가 되게 중요함.
	// 그래서 카메라가 무엇인가?
	//		- 유저 모니터에 비쳐지는 호면을 어떻게 찍을 것인가?
	

	// 카메라를 연출 방법
	// 2가지 존재
	
	// 1. 카메라가 움직이기
	// 2. 나를 제외한 모든 배경이 움직이기 ( 보통 런 게임, 탄막슈팅게임)

	// 2번은 잘 안 쓸 거 같지만 은근 많이 사용됨..
	// e.g. 쿠키런

	// 다만 원리는 똑같다
	// 결국엔 눈속임이다.
}

void Comment05()
{
	// Component란
	// Actor한테 들어가는 기능들
	
	// CameraComponent는 액터를 찍는 카메라.
	// 우리가 지금 구현하는 건, 포켓몬스터(탑뷰) 카메라

	// 카메라 = 눈속임
	// 카메라가 오른쪽으로 이동하면, 모든 게 왼쪽으로 이동
	// 내가 그릴 좌표(캐릭터 좌표가 아무리 작아져도, 카메라도 같이 작아짐) e.g. 메이플
	// pos - cameraPos >> 이게 현재 내 창에서 보일 창의 좌표
}

void Comment06()
{
	// 개발도중 문제가 생겼을 때 값을 확인하는 방법
	
	// 1. 로그 찍기
	//	- 라이브 도중일 때
	//	- 재현이 안 될 떄 (재현 스텝)
	//	- 중간에 멈추면 안 될 때. (센서 같은 거 실시간으로 그래프를 그려야하는 데 틱 하나가 튄다.)
	// (주로 네트워크 이슈)

	// 2. 디버깅
	//	- 재현이 될 때
	//	- 개발 중일 떄
	//	- 중간에 멈춰도 될 때
}

void Comment07()
{
	// rv = Clamp(a, min, max)
	// a의 값을 main과 max사이로 제한을 둬서 rv로 리턴해준다.

	// Lerp
	// 게임에서는 되게 많이 쓰임
	// 만만한 연출 로직

	// rv = Lerp(start, end, percent);
	// start를 0, end를 1로 쳤을 때 percent의 수치는 몇인지 계산해주는 로직.
	// 선형그래프를 쉽게 그릴 수 있다.
}

void Comment08()
{
	// inline 명령어
	// CPU 캐시로 만드는 거라
	// 접근 속도가 빠름
	// #define처럼 빠름.

	// 그러면, 모든 애들을 inline으로 만들면 좋은 거 아닌가?
	// 제약..
	// 1. .h파일에서만 inline 쓸 수 있음
	// 2. CPU 캐시로 넣는 거라, 용량이 다 차면 못 넣는다
	// << 용량은 누가 제어하나?
	// << 런터임 때 제어. (더 많이 사용할 거 위주로)
}