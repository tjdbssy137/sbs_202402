#include "pch.h"
#include "MoleGameScene.h"
#include "SpriteActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"

void MoleGameScene::Init()
{
	Super::Init();
	// 배경
	{
		Resource->LoadTexture(L"T_Molebackground", L"Mole/background.bmp");
		Resource->CreateSprite(L"S_Molebackground", Resource->GetTexture(L"T_Molebackground"));

		SpriteActor* background = new SpriteActor();
		background->SetName("Background");
		background->SetSprite(Resource->GetSprite(L"S_Molebackground"));
		background->SetBody(Shape::MakeCenterRectLTWH(0,0,WIN_SIZE_X, WIN_SIZE_Y));
		background->Init();
		this->SpawnActor(background);
	}

	// 두더지
	Resource->LoadTexture(L"T_Mole", L"Mole/mole.bmp");
	Resource->CreateSprite(L"S_Mole_Idle", Resource->GetTexture(L"T_Mole"), 0, 0, 85, 113); // 그림을 두 개로 찢음
	Resource->CreateSprite(L"S_Mole_Die", Resource->GetTexture(L"T_Mole"), 85, 0, 85, 113);
	//한번 로드하면 재사용은 자주해도 상관 없음
	//세로 1번째 줄
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(220, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(220, 237, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(224, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	//세로 3번째 줄
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 237, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(622, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	//세로 2번째 줄
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(428, 160, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}
	{

		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(428, 313, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_mole.push_back(mole);
		this->SpawnActor(_mole.back());
	}

	// 망치
	{
		Resource->LoadTexture(L"T_Hammer", L"Mole/hammer.bmp");
		Resource->CreateSprite(L"S_Hammer_Idle", Resource->GetTexture(L"T_Hammer"), 0, 0, 50, 50);
		Resource->CreateSprite(L"S_Hammer_Hit", Resource->GetTexture(L"T_Hammer"), 50, 0, 50, 50);

		_hammer = new SpriteActor();
		_hammer->SetName("Hammer");
		_hammer->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
			_hammer->AddComponent(collider);
		}

		_hammer->Init();
		this->SpawnActor(_hammer);
	}
	_regenTimer = 0.5f;
}
void MoleGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"MoleGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void MoleGameScene::Update()
{
	Super::Update();


	//-------------------------
	// * Hammer Code *
	//-------------------------
	POINT mousePos = Input->GetMousePos();
	_hammer->SetBody(Shape::MakeCenterRect(mousePos.x, mousePos.y, 51, 51));
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_hammer->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));
	}
	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		_hammer->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
	}

	//-------------------------
	// * Mole Code *
	//-------------------------
	// N초마다 랜덤한 두더지가 ChangeState(In)으로 변한다.
	_regenTimer -= Time->GetDeltaTime();
	if (_regenTimer <= 0.0f)
	{
		MoleActor* randomMoleActor = _mole[Random->GetRandomInt(0, _mole.size() - 1)];
		if (randomMoleActor->ChangeState() == MoleActorState::In)
		{
			randomMoleActor->ChangeState(MoleActorState::Out);
			_regenTimer = 0.5f;
		}
	}
}
void MoleGameScene::Release()
{
	Super::Release();

}