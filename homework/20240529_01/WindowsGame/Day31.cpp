#include "pch.h"

void Comment1()
{
	//숙제하신분들 항상 DM으로 주세요.
	
	//1. Circle Collider 만든거 확인.
	//2. UI - 이론설명
	//3. UI 간단하게 구현
}

void Comment2()
{
	//UI.

	
	// User Interface
	// 

	// 게임에는 크게 2가지
	// World (Actor), UI (UI), Camera (CameraPos) (유저한테 보여주는 전부)
	
	// 비중에 높은거에 비해 난인도가 그렇게 높진않아서
	// 신입분들한테 많이 시키곤해요.

}

void Comment3()
{
	//UI를 구성할때 제일 중요한거

	// 1. Panel
	//  UI라는 base클래스를 만들어줄게요.


	// base클래스를 만드는이유
	//  - 클래스 속성중, 다형성을 활용하기 위해
	//  - FlipActor, SpriteActor 
	//   - Actor이기 때문에 조작하기에 뭔가 공통점으로 해줘야할수있는데
	//   - 둘다 한번에 Update라던지, 이런 함수들을 호출할수가없습니다.
	
}

void Comment4()
{
	//SetIsShow라는 함수로 안들고
	// Show, Hide라는 함수로 만드는이유

	// 함수는 가독성이 1순위 (SetIsShow보다는 Show, Hide가 유저[프로그래머]가 읽기에 더 수월합니다.)
	// 
	// SetCenterRect << 이런건 가독성이 너무 없지않았나요?
	// 두번째로는 범용성

}

void Comment5()
{
	// Panel은 계층구조 Hierachy를 가진다.
	// Panel에서 다른 UI들을 가지고있을수만 있으면 된다.
}

void Comment6()
{
	// Image 클래스르 만들어서
	//  Panel에 이미지를 붙여서 띄워보겠습니다.


	// [Panel]
	//   - Image
	//   - Button
	//   - Label (글자)
	//   - [Panel]
	//       - Image

}

void Comment7()
{
	//실습 : Panel에 Image를 넣어서 화면가운데에 이미지UI 출력하기

	// Scene에서
	// 1. Panel을 만들고
	// 2. Image를 만들고
	// 3. Image를 Panel에 연결해주고
	// 4. Image에게 Sprite를 세팅해주고

	// Panel을 씬에서 
	// Init, Render, Update,Release를 실행해준다.

}

void Comment8()
{
	//숙제 : 
	// 이미지가 부모 패널에 따라서, 위치 변하도록 프레임워크 코드 수정

	// ex1. Panel의 pos이 중앙으로 잡혀있고
	//		- Image의 pos이 0,0 으로 잡혀있을때
	//		- Render를 하면, 중앙에 나와야한다.


	// ex2. Panel의 pos이 (100, 100)으로 잡혀있고
	//		- Image의 pos이 (-10, 20) 으로 잡혀있을때
	//		- Render를 하면, (90, 120)에 나와야한다.

}