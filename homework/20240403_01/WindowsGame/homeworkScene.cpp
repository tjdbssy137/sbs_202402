#include "pch.h"
#include "homeworkScene.h"

void homeworkScene::Init()
{
	Super::Init();
	_ball = { Vector2(130, 200), 30, 30 };
	_leftPlayer = { Vector2(20, 200), 20, 120 };
	_rightPlayer = { Vector2(530, 200), 20, 120 };
	//공이 살아있는 x축 범위는 25~525
	_roofRect = { Vector2(250, 80), 600, 2};
	_floorRect = { Vector2(250, 320), 600, 2 };

	_moveRange1 = _roofRect.pos.y + _leftPlayer.height / 2;
	_moveRange2 = _floorRect.pos.y - _leftPlayer.height / 2;
}
void homeworkScene::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"HomeworkScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring str2 =  L"{ " + to_wstring(_leftPoint) + L" : " + to_wstring(_rightPoint) + L" }";
	::TextOut(hdc, 200, 45, str2.c_str(), str2.length());


	if (10 == _leftPoint)
	{
		wstring str3 = L"좌측 플레이어의 승리!";
		::TextOut(hdc, 200, 100, str3.c_str(), str3.length());
	}
	if (10 == _rightPoint)
	{
		wstring str3 = L"우측 플레이어의 승리!";
		::TextOut(hdc, 200, 100, str3.c_str(), str3.length());
	}

	_ball.Draw(hdc);
	_leftPlayer.Draw(hdc);
	_rightPlayer.Draw(hdc);
	_roofRect.Draw(hdc);
	_floorRect.Draw(hdc);
}
void homeworkScene::Update()
{
	Super::Update();

	// leftPlayer Controller
	{
		if (Input->GetKey(KeyCode::W))
		{
			_leftPlayerDir = Vector2(0, -1);
			_leftPlayer.pos += _leftPlayerDir * 100 * Time->GetDeltaTime();
		}
		if (Input->GetKey(KeyCode::S))
		{
			_leftPlayerDir = Vector2(0, 1);
			_leftPlayer.pos += _leftPlayerDir * 100 * Time->GetDeltaTime();
		}
		if (_leftPlayer.pos.y <= _moveRange1)
		{
			_leftPlayer.pos.y = _moveRange1 + 1;
		}
		if (_moveRange2 <= _leftPlayer.pos.y)
		{
			_leftPlayer.pos.y = _moveRange2 - 1;
		}
	}
	
	// rightPlayer Controller
	{
		if (Input->GetKey(KeyCode::Up))
		{
			_rightPlayerDir = Vector2(0, -1);
			_rightPlayer.pos += _rightPlayerDir * 100 * Time->GetDeltaTime();
		}
		if (Input->GetKey(KeyCode::Down))
		{
			_rightPlayerDir = Vector2(0, 1);
			_rightPlayer.pos += _rightPlayerDir * 100 * Time->GetDeltaTime();
		}
		if (_rightPlayer.pos.y <= _moveRange1)
		{
			_rightPlayer.pos.y = _moveRange1 + 1;
		}
		if (_moveRange2 <= _rightPlayer.pos.y)
		{
			_rightPlayer.pos.y = _moveRange2 - 1;
		}
	}

	// ball Controller
	{
		if (Input->GetKeyDown(KeyCode::LeftMouse))
		{
			if (_mouseTurn)
			{
				_mouseTurn = false;
				POINT pt = Input->GetMousePos();
				_targetPos = Vector2(pt.x, pt.y);
			}
			_ballDir = (_targetPos - _ball.pos).Normalize();
		}
	}

	//if (2 < (_targetPos - _ball.pos).Length())
	{
		_ball.pos += _ballDir * (Time->GetDeltaTime() * 400);
		
		if (_ball.pos.x < 15 || 535 < _ball.pos.x)
		{
			_ballDir = Vector2(0, 0);
			_mouseTurn = true;
			if (_ball.pos.x < 15)
			{
				_rightPoint++;
				_ball.pos = Vector2(130, 200);
			}
			if (535 < _ball.pos.x)
			{
				_leftPoint++;
				_ball.pos = Vector2(430, 200);
			}
		}
		
		if (Collision::RectInRect(_leftPlayer.ToRect(), _ball.ToRect()))
		{//상하좌우 충돌 판단하는 법 필요
			_ballDir.x *= -1;
			_ball.pos += _ballDir * (Time->GetDeltaTime() * 400);
		}
		if (Collision::RectInRect(_rightPlayer.ToRect(), _ball.ToRect()))
		{
			_ballDir.x *= -1; 
			_ball.pos += _ballDir * (Time->GetDeltaTime() * 400);
		}
		if (Collision::RectInRect(_roofRect.ToRect(), _ball.ToRect()))
		{
			_ballDir.y *= -1; 
			_ball.pos += _ballDir * (Time->GetDeltaTime() * 400);
		}
		if (Collision::RectInRect(_floorRect.ToRect(), _ball.ToRect()))
		{
			_ballDir.y *= -1; 
			_ball.pos += _ballDir * (Time->GetDeltaTime() * 400);
		}
	}
}
void homeworkScene::Release()
{
	Super::Release();
}