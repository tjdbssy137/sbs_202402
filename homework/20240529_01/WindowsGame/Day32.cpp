#include "pch.h"

void Comment1()
{
	// 1. 숙제풀이.
	// 이미지가 부모 패널에 따라서, 위치 변하도록 프레임워크 코드 수정

	// ex1. Panel의 pos이 중앙으로 잡혀있고
	//		- Image의 pos이 0,0 으로 잡혀있을때
	//		- Render를 하면, 중앙에 나와야한다.


	// ex2. Panel의 pos이 (100, 100)으로 잡혀있고
	//		- Image의 pos이 (-10, 20) 으로 잡혀있을때
	//		- Render를 하면, (90, 120)에 나와야한다.


	// UI 룰 : 
	//	패널안에 (그릴 수 있는)UI요소가 들어간다.



	// 2. UI중에서 제일 중요한거.
	//  - Button 구현
	//  - Console에서 새롭게 문법하나 배울겁니다.
}


void Comment2()
{
	//이미지를 그릴때, Render Position은 부모 패널의 영향을 받아야한다.
	// -> 부모 패널은 어떻게 가져오지?
	// -> 못가져오면, 가져올수있게끔 [변수로 기억을해준다.] 
	// 변수를 만들기만하고, 세팅을 안해줬음.
	// 변수 사용
	

	// 패널안에 패널이 있을경우.
	// 계층구조

	// Inventory의 경우
	// Inventory Root Panel (Test Panel)
	//	- Icon List Panel  
	//		- BackgroundImage
	//		- IconImage1
	//		- IconImage2

	// vector<UI*> temp;
	// temp 이 변수안에 자신의 부모들을 모두 모아두는 형식으로 먼저 짜보시면 좋을것같습니다.

	// 요게 되면
	// for문돌아서 모든 포지션 더해주시면 됩니다.



	// => 그림을 그릴때, 부모의 부모의 부모의 ... 해서
	// 모든 부모를 가져온 position을 구해야한다.

	// Tree, Linked List 했을때 비슷하죠??
	// 계층구조 


	//그래서 이거를 지금 실습
}

void Comment3()
{
	//버튼.

}