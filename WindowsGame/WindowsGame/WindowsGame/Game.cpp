#include "pch.h"
#include "Game.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->_hdc = ::GetDC(this->_hwnd); // 유저에게 보여줄 화면

	//더블버퍼링
	::GetClientRect(_hwnd, &_rect); // 윈도우 핸들에 크기를 지정해주겠다.

	_hdcBack = ::CreateCompatibleDC(_hdc);// 유저에게 보이지 않는 화면 생성, _hdc를 똑같이 따라 만듦
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // _hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); //  _hdcBack에 _bmp연결
	//_hdcBack이 이전에 갖고 있던 값을 prev로 return. SelectObject가 독특한 함수임.
	::DeleteObject(prev); // 이전에 만들어 둔 거 삭제
	

	//싱글톤 초기화
	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	_x++;
}

void Game::Render()
{
	//FPS 출력
	{
		uint32 fps = GET_SINGLE(TimeManager)->GetFps();
		float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length()); // 유저에게 보이지 않는 곳에 작성
	}


	wstring str = L"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세. 무궁화 삼천리 화려강산 대한사람 대한으로 길이 보전하세.";
	::TextOut(_hdcBack, 100 + _x % 700, 100, str.c_str(), str.length()); // 유저에게 보이지 않는 곳에 작성
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	//BitBlt 고속 복사
	//_hdcBack에 있는 값을 _hdc로 옮기는데. (0, 0)으로 _rect.right부터 _rect.bottom까지 SRCCOPY조건으로 복붙
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	// _hdcBack을 WHITENESS로 깔끔하게 지움
}