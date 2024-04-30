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
		_creature->SetName("Creature");

		_creature->Init();
		_creature->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Idle"));

		SpawnActor(_creature);
	}
	{
		_monster = new MonsterActor();
		_monster->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2 - 60));
		_monster->SetName("Monster");
		
		_monster->Init();
		_monster->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Down_Idle"));

		SpawnActor(_monster);
	}
	/*
	{
		_userCharacterController = new UserCharacterController();
		_userCharacterController->Init(_creature, _monster);
	}
	*/
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
	_monster->Update();
	_monster->LookAtPlayer(_creature->GetPos());

}
void Dev1Scene::Release()
{
	Super::Release();

}

void Dev1Scene::LoadResource()
{

	// -------------------------------------
	// 
	//			CREATURE RESOURCE
	// 
	// ------------------------------------- 
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


	// -------------------------------------
	// 
	//			MONSTER RESOURCE
	// 
	// -------------------------------------

	{
		Resource->LoadTexture(L"T_Monster", L"FlipbookTest/Monster2.bmp", RGB(192, 192, 192));
		FlipbookInfo _info = {};
		_info.start = 0;
		_info.end = 6;
		_info.line = 0;
		_info.size = Vector2Int(62, 45);
		_info.duration = 1.0f;
		_info.loop = true;
		_info.texture = Resource->GetTexture(L"T_Monster");

		Resource->CreateFlipbook(L"FB_Monster_Down_Idle", _info);

		_info.line = 1;
		Resource->CreateFlipbook(L"FB_Monster_Left_Idle", _info);

		_info.line = 2;
		Resource->CreateFlipbook(L"FB_Monster_Right_Idle", _info);

		_info.end = 5;
		_info.line = 3;
		Resource->CreateFlipbook(L"FB_Monster_Up_Idle", _info);

		_info.end = 3;
		_info.line = 4;
		_info.loop = false;
		Resource->CreateFlipbook(L"FB_Monster_Die", _info);

		_info.end = 1;
		_info.line = 5;
		Resource->CreateFlipbook(L"FB_Monster_GetHit", _info);
	}
}