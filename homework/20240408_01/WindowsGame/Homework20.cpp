#include "pch.h"
#include "Homework20.h"

void Homework20::Init()
{
	Super::Init();
	_player = {Vector2(550, 500), 120, 20};
	_ball = Shape::MakeCenterRect(550, 400, 30, 30);
	_block = Shape::MakeCenterRect(50, 100, 100, 40);
	_wallLeft = Shape::MakeCenterRect(45, 300, 10, 460);
	_wallRight = Shape::MakeCenterRect(1055, 300, 10, 460);

	for (int i = 0; i < 40; i++)
	{
		_collisionCheck[i] = true;
	}
}
void Homework20::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"Homework20";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
	_wallLeft.Draw(hdc);
	_wallRight.Draw(hdc);

	int a = 0;
	int b = 0;
	for (int i = 0; i < 40; i++)
	{
		_blocks[i] = _block;
		_blocks[i].pos.x += 50 + a * 100;
		_blocks[i].pos.y += 40 * b;
		a++;
		if ((i + 1) % 10 == 0)
		{
			a = 0;
			b++;
		}

		if (_collisionCheck[i] == true)
		{
			_blocks[i].Draw(hdc);
		}
	}
	_ball.Draw(hdc);
	_player.Draw(hdc);
}
void Homework20::Update()
{
	Super::Update();
	//if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))//not work
	// 두 개를 입력 받을 때에는 둘 중 하나는 GetKey로 해야함. 둘 다 GetKeyDown으로 받으면 한 프레임에 동시에 두 개 눌러야 함.
	
	//player Movement
	if (Input->GetKey(KeyCode::A))
	{
		_playerDir = Vector2(-1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 300);
	}
	else if (Input->GetKey(KeyCode::D))
	{
		_playerDir = Vector2(1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 300);
	}
	if (Collision::RectInRect(_player.ToRect(), _wallLeft.ToRect()))
	{
		_player.pos.x += 5;
	}
	if (Collision::RectInRect(_player.ToRect(), _wallRight.ToRect()))
	{
		_player.pos.x -= 5;
	}

	if (_mouseTurn)
	{
		if (Input->GetKeyDown(KeyCode::LeftMouse))
		{
			_mouseTurn = false;
			POINT pt = Input->GetMousePos();
			_targetPos = Vector2(pt.x, pt.y);
			_ballDir = (_targetPos - _ball.pos).Normalize();
			//cout << "_ballDir.x : " << _ballDir.x << "/ _ballDir.y : " << _ballDir.y << endl;
		}
	}
	//ball
	if (Collision::RectInRect(_player.ToRect(), _ball.ToRect())
		|| Collision::RectInRect(_wallLeft.ToRect(), _ball.ToRect())
		|| Collision::RectInRect(_wallRight.ToRect(), _ball.ToRect()))
	{
		if (0 < _ballDir.x && 0 < _ballDir.y)
		{
			_ballDir = _ballDir.Reflect(Vector2(0, 1)).Normalize();
		}
		else if (_ballDir.x < 0 && 0 < _ballDir.y)
		{
			_ballDir = _ballDir.Reflect(Vector2(-1, 0)).Normalize();
		}
		else if (0 < _ballDir.x && _ballDir.y < 0)
		{
			_ballDir = _ballDir.Reflect(Vector2(1, 0)).Normalize();
		}
		else if (_ballDir.x < 0 && _ballDir.y < 0)
		{
			_ballDir = _ballDir.Reflect(Vector2(0, -1)).Normalize();
		}
	}

	//blocks
	for (int i = 0; i < 40; i++)
	{
		if (Collision::RectInRect(_blocks[i].ToRect(), _ball.ToRect()))
		{
			if (_collisionCheck[i] == true)
			{
				if (0 < _ballDir.x && 0 < _ballDir.y)
				{
					_ballDir = _ballDir.Reflect(Vector2(0, 1)).Normalize();
				}
				else if (_ballDir.x < 0 && 0 < _ballDir.y)
				{
					_ballDir = _ballDir.Reflect(Vector2(-1, 0)).Normalize();
				}
				else if (0 < _ballDir.x && _ballDir.y < 0)
				{
					_ballDir = _ballDir.Reflect(Vector2(1, 0)).Normalize();
				}
				else if (_ballDir.x < 0 && _ballDir.y < 0)
				{
					_ballDir = _ballDir.Reflect(Vector2(0, -1)).Normalize();
				}
				_collisionCheck[i] = false;

			}
		}
	}

	//ball Movement
	_ball.pos += _ballDir * (Time->GetDeltaTime() * 450);
	if (600 < _ball.pos.y || _ball.pos.y < 10)
	{
		_ballDir = _Vector2Zero;
		_ball.pos.x = 550;
		_ball.pos.y = 300;
		_mouseTurn = true;
	}
}
void Homework20::Release()
{
	Super::Release();
}