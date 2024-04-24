#include "pch.h"
#include "PooGame.h"
#include "SpriteActor.h"
#include "BoxCollider.h"
#include "Pumpkin.h"

void PooGame::Init()
{
	Super::Init();

	//texture = T_
	//sprite = S_
	//Windows API에선 bmp밖에 사용 안 됨
	//하지만, 게임에선 png파일을 훨씬 더 많이 사용
	//png는 Direct X
	Resource->LoadTexture(L"T_PooBackground", L"Poo/background.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_PooBackground", Resource->GetTexture(L"T_PooBackground"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_PooBackground"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRect(WIN_SIZE_X/ 2, WIN_SIZE_Y /2, 700, 500));
		SpawnActor(spriteActor);
	}

	{
		for (int i = 0; i < PUMPKIN_MAX; i++)
		{
			Pumpkin* pumpkin = new Pumpkin();
			pumpkin->Init();
			pumpkin->SetName("Pumpkin");
			_pumpkin.push_back(pumpkin);
			this->SpawnActor(_pumpkin[i]);
		}
	}


	Resource->LoadTexture(L"T_Character", L"Poo/bunny.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Character", Resource->GetTexture(L"T_Character"));

	{
		_player = new SpriteActor();
		_player->SetSprite(Resource->GetSprite(L"S_Character"));
		_player->Init();

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 80, 100));
		_player->AddComponent(collider);

		_player->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, 483, 100, 100));
		SpawnActor(_player);
	}
	_throwTime = 0.5f;
}
void PooGame::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"PooGame";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
}
void PooGame::Update()
{
	Super::Update();
	
	_time += Time->GetDeltaTime();
	if (_throwTime <= _time)
	{
		if (_pumpkinOrder == PUMPKIN_MAX)
		{
			_pumpkinOrder = 0;
		}
		int _pumpkinPosX = rand() % 350 + 250;
		_pumpkin[_pumpkinOrder]->Throw(_pumpkinPosX);
		_pumpkinOrder++;
		_time = 0;
	}

	{
		for (int i = 0; i < PUMPKIN_MAX; i++)
		{
			if (750 < _pumpkin[i]->GetBody().pos.y)
			{
				_pumpkin[i]->SetMoveDir(Vector2::Zero());
			}
		}
	}
	PlayerMove();
	IsCollisionEnter();
}
void PooGame::Release()
{
	Super::Release();
}


void PooGame::PlayerMove()
{
	if (Input->GetKey(KeyCode::A))
	{
		float _x = Time->GetDeltaTime() * 400 * Vector2::Left().x + _player->GetBody().pos.x;
		_player->SetBody(Shape::MakeCenterRect(_x, _player->GetBody().pos.y, 100, 100));
	}
	if (Input->GetKey(KeyCode::D))
	{
		float _x = Time->GetDeltaTime() * 400 * Vector2::Right().x + _player->GetBody().pos.x;
		_player->SetBody(Shape::MakeCenterRect(_x, _player->GetBody().pos.y, 100, 100));
	}
}

void PooGame::IsCollisionEnter()
{
	for (int i = 0; i < 8; i++)
	{
		if (Collision::RectInRect(_pumpkin[i]->GetBody().ToRect(), _player->GetBody().ToRect()))
		{
			cout << "Game Over" << endl;
		}
	}
}