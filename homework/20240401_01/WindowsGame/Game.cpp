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

	//------------------------------
	//	## 코드 짜는 곳
	//------------------------------
	_player.left = 100;
	_player.right = 200;
	_player.top = 100;
	_player.bottom = 200;

	_enemy.left = 550;
	_enemy.right = 600;
	_enemy.top = 100;
	_enemy.bottom = 150;

	int a = 0;
	int b = 0;
	for (int i = 1; i <= 9; i++)
	{
		RECT _temp = {};
		_temp.left = 200 + a;
		_temp.right = 300 + a;
		_temp.top = 200 + b;
		_temp.bottom = 300 + b;
		_gugudanVec.push_back(_temp);
		a += 110;
		if (i % 3 == 0)
		{
			a = 0;
			b += 110;
		}
	}
}

void Game::Update()
{
	//싱글톤 업데이트
	Time->Update();
	Input->Update();

	//------------------------------
	//	## 코드 짜는 곳
	//------------------------------
	//------------------------------
	//실습
	// 1. WASD 나 방향키로,
	//    _player를 움직일수 있게한다.
	// 2. _player와 _enmey가 부딪히면
	//   ::MessageBox(_hwnd, L"알림", L"충돌되었습니다", 0);
	//  를 실행한다.
	//------------------------------

	// 이동 스크립트
	POINT _direction = {};
	int _moveDistance = 10;
	if (Input->GetKeyDown(KeyCode::Right))
	{
		_player.left += _moveDistance;
		_player.right += _moveDistance;
		_direction = { 0, 1 };
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		_player.left -= _moveDistance;
		_player.right -= _moveDistance;
		_direction = { 0, -1 };
	}
	else if (Input->GetKeyDown(KeyCode::Up))
	{
		_player.top -= _moveDistance;
		_player.bottom -= _moveDistance;
		_direction = { -1, 0 };
	}
	else if (Input->GetKeyDown(KeyCode::Down))
	{
		_player.top += _moveDistance;
		_player.bottom += _moveDistance;
		_direction = { 1, 0 };
	}

	// _enemy와의 충돌&이동 스크립트
	if (Collision::RectInRect(_player, _enemy))
	{
		//::MessageBox(_hwnd, L"충돌되었습니다", L"알림", 0);
		_enemy.left += _moveDistance * _direction.y;
		_enemy.right += _moveDistance * _direction.y;
		_enemy.top += _moveDistance * _direction.x;
		_enemy.bottom += _moveDistance * _direction.x;
	}


	// 마우스 클릭 스크립트
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		for (int i = 0; i < _gugudanVec.size(); i++)
		{
			if (Collision::PtInRect(Input->GetMousePos(), _gugudanVec[i]))
			{
				_dan = i + 1;
			}
		}
	}

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

		if (_dan != 0)
		{
			for (int i = 1; i <= 9; i++)
			{
				wstring _gugudanStr = format(L"({0}) X ({1}) = ({2})", _dan, i, i * _dan);
				::TextOut(_hdcBack, mousePos.x, mousePos.y + i * 15, _gugudanStr.c_str(), _gugudanStr.length());
			}
		}
	}
	//------------------------------
	//	## 코드 짜는 곳
	//------------------------------
	::Rectangle(_hdcBack, _player.left, _player.top, _player.right, _player.bottom);
	::Rectangle(_hdcBack, _enemy.left, _enemy.top, _enemy.right, _enemy.bottom);

	for (int i = 0; i < _gugudanVec.size(); i++)
	{
		::Rectangle(_hdcBack, _gugudanVec[i].left, _gugudanVec[i].top, _gugudanVec[i].right, _gugudanVec[i].bottom);
	}

	//비트블릿 : 고속 복사
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}