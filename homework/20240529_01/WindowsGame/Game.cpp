#include "pch.h"
#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
	GET_SINGLE(ResourceManager)->Release();
	GET_SINGLE(SoundManager)->Release();
}


void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->_hdc = ::GetDC(this->_hwnd);

	//더블버퍼링
	::GetClientRect(_hwnd, &_rect);		//윈도우핸들의 크기를 반환하겠다.

	_hdcBack = ::CreateCompatibleDC(_hdc);	//_hdc와 호환되는 화면 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	//_hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	//_hdcBack에 _bmp 연결
	::DeleteObject(prev);


	//싱글톤 초기화
	Time->Init();
	Input->Init(_hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	Resource->Init();
	Random->Init();
	GET_SINGLE(SoundManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
}
void Game::Update()
{
	//싱글톤 업데이트
	Time->Update();
	Input->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();


}
void Game::Render()
{



	//FPS 출력
	{
		uint32 fps = Time->GetFps();
		float deltaTime = Time->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}

	//마우스좌표 출력
	{
		POINT mousePos = Input->GetMousePos();
		wstring str = format(L"mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdcBack, 0, 20, str.c_str(), str.length());
	}


	GET_SINGLE(SceneManager)->Render(_hdcBack);
	

	//비트블릿 : 고속 복사
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}