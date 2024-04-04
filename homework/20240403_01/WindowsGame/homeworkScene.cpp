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
			POINT pt = Input->GetMousePos();
			_targetPos = Vector2(pt.x, pt.y);
			_ballDir = (_targetPos - _ball.pos).Normalize();
		}
		
	}

	// ball Collision
	{
		//_ballDir -> 부딪힌 좌표(_ball.pos)를 구한다음
		//			-> 이전 좌표 * -1 한 방향을 구해서
		//			-> _ballDir = (이전 좌표 * -1, _ball.pos).Normalize();
		
	}
	
	// Game Over
	if (2 < (_targetPos - _ball.pos).Length())
	{
		_ball.pos += _ballDir * (Time->GetDeltaTime() * 100);
		
		if (_ball.pos.x < 15 || 535 < _ball.pos.x)
		{
			_ballDir = Vector2(0, 0);
			//공위치 원상복귀하는 것도
			//점수
			//마지막에 닿은 플레이어가 누군지 확인하고, 그 플레이어에게 점수
			if (_whoseTurn)
			{
				_leftPoint++;
			}
			else
			{
				_rightPoint++;
			}
		}
		
		if (Collision::RectInRect(_leftPlayer.ToRect(), _ball.ToRect()))
		{
			_whoseTurn = true;
			Vector2 _tempDir = Vector2(_ballDir.x * -1, _ballDir.y).Normalize(); // 반사각 수정
			_ball.pos += _tempDir * (Time->GetDeltaTime() * 100);
		}
		if (Collision::RectInRect(_rightPlayer.ToRect(), _ball.ToRect()))
		{
			_whoseTurn = false;
			Vector2 _tempDir = Vector2(_ballDir.x * -1, _ballDir.y).Normalize();
			_ball.pos += _tempDir * (Time->GetDeltaTime() * 100);
		}
		if (Collision::RectInRect(_roofRect.ToRect(), _ball.ToRect()))
		{
			Vector2 _tempDir = Vector2(_ballDir.x, _ballDir.y * -1).Normalize();
			_ball.pos += _tempDir * (Time->GetDeltaTime() * 100);
		}
		if (Collision::RectInRect(_floorRect.ToRect(), _ball.ToRect()))
		{
			Vector2 _tempDir = Vector2(_ballDir.x, _ballDir.y * -1).Normalize();
			_ball.pos += _tempDir * (Time->GetDeltaTime() * 100);
			//_ballDir * (-1) => 그대로 돌아감. 
			//Vector2 _tempDir = Vector2(_ballDir.x * -1, _ballDir.y);//경우에 따라 x축에만 -1하거나 y축에만 -1하기
		}
	}
	
}
void homeworkScene::Release()
{
	Super::Release();
}