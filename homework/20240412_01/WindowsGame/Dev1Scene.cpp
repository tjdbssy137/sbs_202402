#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "PooActor.h"
#include "BoxCollider.h"

/// <summary>
/// �����ϱ����
/// </summary>
void Dev1Scene::Init()
{
	Super::Init();

	{
		PlayerActor* player = new PlayerActor();
		player->Init();
		player->SetName("�÷��̾�");
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
	{// �� ���� �Է� ���� ������ �� �� �ϳ��� GetKey�� �ؾ���. �� �� GetKeyDown���� ������ �� �����ӿ� ���ÿ� �� �� ������ ��.
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

	RECT collision = {}; // �浹������ �����ִ� ����
	RECT playerCollision = _player.ToRect();
	RECT wallCollision = _wall.ToRect();
	if (::IntersectRect(&collision, &playerCollision, &wallCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;

		// �� ª�� ���� �ε��� ��
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "�Ʒ����� ���� �浹 �Ǿ���" << endl;
				//_player.pos.y += collisionHeight;
				_wall.pos.y -= collisionHeight;
			}
			if (collision.bottom == playerCollision.bottom)
			{
				cout << "������ �Ʒ��� �浹 �Ǿ���" << endl;
				//_player.pos.y -= collisionHeight;
				_wall.pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "�����ʿ��� �������� �浹 �Ǿ���" << endl;
				//_player.pos.x += collisionWidth;
				_wall.pos.x -= collisionWidth;
			}
		
			if (collision.right == playerCollision.right)
			{
				cout << "���ʿ��� ���������� �浹 �Ǿ���" << endl;
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