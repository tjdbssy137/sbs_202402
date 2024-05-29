#include "pch.h"
#include "MoleGameScene.h"
#include "SpriteActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "HammerActor.h"
#include "PlayerHammerController.h"

void MoleGameScene::Init()
{
	Super::Init();

	{
		Resource->LoadTexture(L"T_MoleBackground", L"Mole/background.bmp");
		Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

		SpriteActor* background = new SpriteActor();
		background->SetName("Background");
		background->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		background->SetBody(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
		background->Init();

		this->SpawnActor(background);
	}

	Resource->LoadTexture(L"T_Mole", L"Mole/mole.bmp");
	Resource->CreateSprite(L"S_Mole_Idle", Resource->GetTexture(L"T_Mole"), 0, 0, 85, 113);
	Resource->CreateSprite(L"S_Mole_Die", Resource->GetTexture(L"T_Mole"), 85, 0, 85, 113);
	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(219, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(219, 237, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(223, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}


	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 86, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
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
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(620, 405, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(427, 162, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}

	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(427, 312, 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(mole);
	}


	{
		Resource->LoadTexture(L"T_Hammer", L"Mole/hammer.bmp");
		Resource->CreateSprite(L"S_Hammer_Idle", Resource->GetTexture(L"T_Hammer"),0, 0, 51, 51);
		Resource->CreateSprite(L"S_Hammer_Hit", Resource->GetTexture(L"T_Hammer"), 51, 0, 51, 51);

		_hammer = new HammerActor();
		_hammer->Init();

		this->SpawnActor(_hammer);
	}

	{
		_playerHammerController = new PlayerHammerController();
		_playerHammerController->Init(_hammer, _moles);
	}


	_regenTimer = 0.5f;
}
void MoleGameScene::Render(HDC hdc)
{
	Super::Render(hdc);


	wstring str1 = L"MoleGameScene";
	::TextOut(hdc, 0, 45, str1.c_str(), str1.length());


	wstring str2 = std::format(L"Score : {0}", _score);
	::TextOut(hdc, WIN_SIZE_X - 100, 45, str2.c_str(), str2.length());
}
void MoleGameScene::Update()
{
	Super::Update();

	_playerHammerController->Update();
	
	//------------------------------------
	//	# 두더지 나오게 하기 #
	//------------------------------------
	_regenTimer -= Time->GetDeltaTime();
	if (_regenTimer <= 0.0f)
	{
		_regenTimer = 0.5f;
		MoleActor* randomMoleActor = _moles[Random->GetRandomInt(0, _moles.size() - 1)];
		if (randomMoleActor->GetState() == MoleActorState::In)
		{
			randomMoleActor->ChangeState(MoleActorState::Out);
		}
	}

}
void MoleGameScene::Release()
{
	Super::Release();
}
void MoleGameScene::ChangeGameState(MoleGameState state)
{

}