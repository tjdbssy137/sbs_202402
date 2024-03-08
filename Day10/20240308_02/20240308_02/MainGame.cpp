#include "MainGame.h"
// 만든 헤더가 있다면 이곳에만 선언
// 구조체라든가.. 뭐 그런 걸 헤더로 만듦.
#include <iostream>
using namespace std;

MainGame::MainGame()
{
	printf("메인 게임 생성자");
	//여기를 void main()이라 생각하고 코딩하면 됨.

	// 변수 선언
	// 함수 선언/구현

	// 1. 변수 선언 하는 법
	// 헤더 파일로 가서
	// int _money = 1000; // _ <- 언더바 필수. 클래스 멤버변수라는 컨벤션을 가짐(의미).
	this->_money; // money;

	// 2. 함수 선언 하는 법
	// public 아래로 들어가서 선언.
	// void Bet();
}

void MainGame::Bet()
{
	cout << "배팅해주세요 : ";
	cin >> this->_money;
}

MainGame::~MainGame()
{
	printf("메인 게임 소멸자");
}