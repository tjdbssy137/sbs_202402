#include "pch.h"

void Comment01()
{
	// 1. Event 기법 => Event Design Pattern
	//	- 기법. 즉, 디자인패턴 => 선임들이 생각했을 때 이런 식으로 하니까 편하더라~ 하는 코드 작성 방식
	//
	//	- Event 디자인 패턴 << Event로 무언가를 다루니까 뭔가 편하더라
	
	// -----------------------------------------------------------------
	// Observer 패턴 
	
	//	- 특정 개게를 관측하고 있다가, 그 객체가 변경되면 알려주는 패턴
	// MyClass a;
	// a.AddListen(&OnListen_AValueChanged);
	// a.SetChangeValue(10);
	// 특정함수 호출됨 (ex. OnListen_AValueChanged)
	// void OnListen_AValueChanged(){}

	// 간단하게, a 객체에 OnListen_AValueChanged 함수 포인터를 주입해주고
	// SetChagneValue라는 함수가 호출되면, OnListen_AValueChanged도 같이 호출되게끔 세팅해 준다.
	// -----------------------------------------------------------------

	// 그래서
	// Observer 패턴의 장점
	//	- 초기화 문에서, 모든 로직의 흐름을 파악할 수 있다.
	
	// 초기화문 : 
	// MyClass a;
	// a.AddListen(&OnListen_AValueChanged);

	// 주요 로직 : 
	// a.SetChangeValue(10);

	// <Observer 패턴을 사용시>
	// 초기화문 : 
	// User user;
	// user.AddListen(&OnListen_AValueChanged);

	// 주요 로직 : 
	// user.SetChangeValue(item);

	// <Observer 패턴을 미사용시>
	// 초기화문 : 
	// User user;

	// 주요 로직 :
	// user.AddItem(item); 
	// AddLog(user, item);

	//-> 주요 로직이 한두줄이 아님
	//-> 눈속임을 위한 코드, 더미용 코드 등등 되게 많음.

	// Observer 패턴의 단점
	//	- 코드 진입장벽이 좀 높음.
	//		- 함수포인터를 사용하기 때문에..

}
void Comment02()
{

}
void Comment03()
{

}
