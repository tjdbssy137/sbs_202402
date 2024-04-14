#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "PooActor.h"
#include "BoxCollider.h"

/// <summary>
/// 똥피하기게임
/// </summary>
void Dev1Scene::Init()
{
	Super::Init();

	{
		PlayerActor* player = new PlayerActor();
		player->Init();
		player->SetName("플레이어");
		this->SpawnActor(player);
	}

	{
		PooActor* poo = new PooActor();
		poo->Init();
		poo->SetName("Poo");
		this->SpawnActor(poo);
	}
}
void Dev1Scene::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
	_wall.Draw(hdc);
	_player.Draw(hdc);
}
void Dev1Scene::Update()
{
	Super::Update();
	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))//not work
	{// 두 개를 입력 받을 때에는 둘 중 하나는 GetKey로 해야함. 둘 다 GetKeyDown으로 받으면 한 프레임에 동시에 두 개 눌러야 함.
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}

	/*
	if (Input->GetKey(KeyCode::Left))
	{
		_playerDir = Vector2(-1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Up))
	{
		_playerDir = Vector2(0, -1);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		_playerDir = Vector2(1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		_playerDir = Vector2(0, 1);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	*/

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_playerDir = (_targetPos - _player.pos).Normalize();
	}
	
	if(2 < (_targetPos - _player.pos).Length())
	{
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}

	RECT collision = {}; // 충돌영역을 구해주는 변수
	RECT playerCollision = _player.ToRect();
	RECT wallCollision = _wall.ToRect();
	if (::IntersectRect(&collision, &playerCollision, &wallCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;

		// 더 짧은 쪽이 부딪힌 쪽
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "아래에서 위로 충돌 되었다" << endl;
				//_player.pos.y += collisionHeight;
				_wall.pos.y -= collisionHeight;
			}
			if (collision.bottom == playerCollision.bottom)
			{
				cout << "위에서 아래로 충돌 되었다" << endl;
				//_player.pos.y -= collisionHeight;
				_wall.pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "오른쪽에서 왼쪽으로 충돌 되었다" << endl;
				//_player.pos.x += collisionWidth;
				_wall.pos.x -= collisionWidth;
			}
		
			if (collision.right == playerCollision.right)
			{
				cout << "왼쪽에서 오른쪽으로 충돌 되었다" << endl;
				//_player.pos.x -= collisionWidth;
				_wall.pos.x += collisionWidth;
			}
		}
	}
}
void Dev1Scene::Release()
{
	Super::Release();
}