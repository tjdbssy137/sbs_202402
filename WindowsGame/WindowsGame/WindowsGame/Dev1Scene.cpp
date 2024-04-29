#include "pch.h"
#include "Dev1Scene.h"
#include "BoxCollider.h"
#include "CreatureActor.h"
#include "MonsterActor.h"
#include "UserCharacterController.h"
#include "Flipbook.h"
void Dev1Scene::Init()
{
	this->LoadResource();
	Super::Init();
	{
		_creature = new CreatureActor();
		_creature->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 55, 60));
		_creature->AddComponent(collider);
		
		_creature->Init();
		_creature->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Idle"));

		SpawnActor(_creature);
	}
	{
		_monster = new MonsterActor();
		_monster->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2 - 60));

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 28, 28));
		_monster->AddComponent(collider);
		
		_monster->Init();
		SpawnActor(_monster);
	}
	{
		_userCharacterController = new UserCharacterController();
		_userCharacterController->Init(_creature, _monster);
	}
}

void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Zelda";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());



}
void Dev1Scene::Update()
{
	Super::Update();
	//_userCharacterController->Update();
	_creature->Update();

}
void Dev1Scene::Release()
{
	Super::Release();

}

void Dev1Scene::LoadResource()
{
	// PlayerDown
	{
		Resource->LoadTexture(L"T_Character", L"FlipbookTest/PlayerDown.bmp", RGB(128, 128, 128));
		FlipbookInfo _downInfo = {};
		_downInfo.start = 0;
		_downInfo.end = 9;
		_downInfo.line = 0;
		_downInfo.size = Vector2Int(200, 200);
		_downInfo.duration = 1.0f;
		_downInfo.loop = true;
		_downInfo.texture = Resource->GetTexture(L"T_Character");

		Resource->CreateFlipbook(L"FB_CharacterDown_Idle", _downInfo);

		_downInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterDown_Move", _downInfo);

		_downInfo.line = 3;
		_downInfo.end = 7;
		_downInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterDown_Attack", _downInfo);
	}

	// PlayerUp
	{
		Resource->LoadTexture(L"T_Character2", L"FlipbookTest/PlayerUp.bmp", RGB(128, 128, 128));
		FlipbookInfo _upInfo = {};
		_upInfo.start = 0;
		_upInfo.end = 9;
		_upInfo.line = 0;
		_upInfo.size = Vector2Int(200, 200);
		_upInfo.duration = 1.0f;
		_upInfo.loop = true;
		_upInfo.texture = Resource->GetTexture(L"T_Character2");

		Resource->CreateFlipbook(L"FB_CharacterUp_Idle", _upInfo);

		_upInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterUp_Move", _upInfo);

		_upInfo.line = 3;
		_upInfo.end = 7;
		_upInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterUp_Attack", _upInfo);
	}

	// PlayerLeft
	{
		Resource->LoadTexture(L"T_Character3", L"FlipbookTest/PlayerLeft.bmp", RGB(128, 128, 128));
		FlipbookInfo _leftInfo = {};
		_leftInfo.start = 0;
		_leftInfo.end = 9;
		_leftInfo.line = 0;
		_leftInfo.size = Vector2Int(200, 200);
		_leftInfo.duration = 1.0f;
		_leftInfo.loop = true;
		_leftInfo.texture = Resource->GetTexture(L"T_Character3");

		Resource->CreateFlipbook(L"FB_CharacterLeft_Idle", _leftInfo);

		_leftInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterLeft_Move", _leftInfo);

		_leftInfo.line = 3;
		_leftInfo.end = 7;
		_leftInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterLeft_Attack", _leftInfo);
	}

	// PlayerRight
	{
		Resource->LoadTexture(L"T_Character4", L"FlipbookTest/PlayerRight.bmp", RGB(128, 128, 128));
		FlipbookInfo _rightInfo = {};
		_rightInfo.start = 0;
		_rightInfo.end = 9;
		_rightInfo.line = 0;
		_rightInfo.size = Vector2Int(200, 200);
		_rightInfo.duration = 1.0f;
		_rightInfo.loop = true;
		_rightInfo.texture = Resource->GetTexture(L"T_Character4");

		Resource->CreateFlipbook(L"FB_CharacterRight_Idle", _rightInfo);

		_rightInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterRight_Move", _rightInfo);

		_rightInfo.line = 3;
		_rightInfo.end = 7;
		_rightInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterRight_Attack", _rightInfo);
	}
}