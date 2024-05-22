#include "pch.h"

void Comment01()
{
	// 1. Circle Collider 만든 거 확인
	// 2. UI - 이론 설명
	// 3. 간단하게 UI 구현
}

void Comment02()
{
	// UI
	// UI = User Interface
	// 게임에는 크게 2가지가 있다
	// World(Scene)과 UI <- 유저한테 보여주는 전부
	// World와 Camera <- 게임을 만드는 전부
	// 
	// 비중이 높은 거에 비해 난이도가 그렇게 높지 않음
	// 신입이 많이 함
	

	// UI란, 인게임 월드에 존재하는 게 아니라 사용자만을 위해서 존재하는 화면 구성들.
	// 쉽게 말하면 [이미지 / 버튼 / 글자] 즉, 월드 요소를 제외한 전부
	// UI에서는 화면 비율이 달라져도 적당히 자기 위치를 찾아가게 하는 기능들이 다 있음. <-- 구현은 안함
	
	// UI 특징 1.
	//		1. UI를 구성할 때, 어떤 기준점(9개)을 기준으로 배치할 치 선택함 = Pivot
	//		2. 해당 점 기준으로 x, y, width, height를 결정
	// UI 특징 2.
	//		1. 상위 Panel을 기준으로 하위 UI들은 포지션이 모두 변경되어야 한다. - Hierarchy 구조

	// UX = User Experience(기획 단계; 버튼 위치를 어디에 두는 게 유저가 편할까? 어디에 캐시샵을 두는 게 더 많은 구매를 유도할까)
}

void Comment03()
{
	// UI를 구성할 때 제일 중요한 것
	// 1. Panel
	//	UI라는 Base클래스를 만들어야 함.

	// Base클래스를 만드는 이유
	// - 클래스 속성 중, 다형성을 활용하기 위해
	// - FlipActor, SpriteActor을 만듦
	// - Actor이기에 조작하기에 공통점으로 해줘야할 것들이 있는데
	// - 둘다 한 번에 Update라든지 하는 함수들을 호출 할 수 없음.
}

void Comment04()
{
	//SetIsShow라는 이름으로 함수로 안 만들고 Show, Hide라는 함수로 만드는 이유?

	// 함수는 가독성이 1순위 (SetIsShow보다는 Show, Hide가 유저[프로그래머]가 읽기에 더 수월)
	// SetCenterRect << 이런건 가독성이 너무 없음
	
	// 두번째로는 범용성.
}

void Comment05()
{
	// Panel은 계층구조(Hierachy)를 가진다.
	// Panel에서 다른 UI들을 가지고 있을 수만 있으면 된다.
}


void Comment06()
{
	//Image 클래스를 만들어서 Panel에 이미지를 붙여 띄우기

	//[Panel]
	// - Image
	// - Button
	// - Label(글자)
	//		- [Panel]
	//			- Image

}

void Comment07()
{
	// 실습 : Pamel에  Image를 넣어서 화면 가운데에 이미지 UI를 출력하기
	// Scene에서
	// 1. Panel을 만들고
	// 2. Image를 만들고
	// 3. Image를 Panel에 연결해주고
	// 4. Image에게 Sprite를 세팅해주고

	// Panel을 씬에서 
	//실행
}

void Comment08()
{
	// 숙제 : 
	// 이미지가 부모 패널에 따라서, 위치가 변하도록 프레임 워크 코드 수정
	// 이미지가 패널 기준으로 위치를 재생성할 수 있도록 수정하란 뜻.

	// ex1. Panel의 pos가 중앙으로 잡혀 있고, Image의 pos가 0, 0으로 잡혀 있을 때 Render를 하면 중앙에 나와야 함
	// ex2. Panel의 pos가 (100, 100)으로 잡혀 있고, Image의 pos가 (-10, 20)으로 잡혀 있을 때 Render를 하면 (90, 120)에 나와야 함
}