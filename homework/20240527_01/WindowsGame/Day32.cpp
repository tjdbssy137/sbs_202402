#include "pch.h"

void Comment01()
{
	// 1. 숙제 풀이
	
	// UI 룰 : 
	// 패널 안에 그릴 수 있는 UI요소가 들어간다.
	
	// 2. UI 중에서 제일 중요한 거
	//		- Button 구현
	//		- Console에서 새롭게 문법 하나 배움

}

void Comment02()
{
	// 이미지를 그릴 때, Render Position은 부모 패널의 영향을 받아야한다.
	// -> 부모 패널을 가져오는 방법은?
	// -> 못 가져오면, 가져올 수 있게끔 [변수]로 기억을 해준다.
	// 부모 세팅을 하는 곳은? -> 자식 세팅은 어디서 했지? AddChild, RemoveChild
	
	// Panel 안에 Panel이 있을 경우
	// 계층 구조

	// Inventory의 경우
	// Inventory Root Panel (Test Panel)
	//	- Icon List Panel  
	//		- BackgroundImage
	//		- IconImage1
	//		- IconImage2

	// 그림을 그릴 때, 부모의 부모의 부모의 ... 해서
	// 모든 부모를 가져온 position을 구해야한다.
}

void Comment03()
{
	//버튼의 특성
	// 내 마우스 위에 있느면 Hover로 보여줌
	// 내 마우스 위에 있고, 클릭하면 Pressed로 보여줌
	// Disabled면 그냥 Disabled로 보여줌
	// 그 외에는 전부 Default

	// BUTTON 수도 코드
	/*
	수도 코드
	if(상태 == Disabled) return;

	if(마우스가 자기 충돌영역 안에 있다면) ==> IsInMouse(UI에서 이미 구현해놓음)
	
	{
		if(마우스가 클릭중인 상태라면)
		{
			상태 = pressed;
		}
		else
		{
			if(상태 == pressed)
			{
				//딱 지금 클릭 했을 때 동작
			}
			상태 = Hover;
		}
	}
	else
	{
		상태 = Default;
	}
	*/

	// 보통 대부분의 함수들은 이미 누군가가 구현을 해놨음
	// 이미 있는 함수를 쓰는 게 좋은 이유
	// 문제가 생겼을 때, 저 함수만 고치면 됨.
	// -> 내가 만든 함수에 문제가 생기면, 다른 함수들으도 같이 검토해야함.
	// 옛날에 만들어진 코드는 보통 더 단단함. 예외처리 등등 면에서..
}