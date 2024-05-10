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
	
	for (int i = 0; i < 8; i++)
	{
		MoleActor* mole = new MoleActor();
		mole->SetBody(Shape::MakeCenterRect(_posX[i], _posY[i], 85, 113));

		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 85, 85));
			mole->AddComponent(collider);
		}

		mole->Init();
		_moles.push_back(mole);
		this->SpawnActor(_moles[i]);
	}
	

	// 망치
	{
		Resource->LoadTexture(L"T_Hammer", L"Mole/hammer.bmp");
		Resource->CreateSprite(L"S_Hammer_Idle", Resource->GetTexture(L"T_Hammer"), 0, 0, 51, 51);
		Resource->CreateSprite(L"S_Hammer_Hit", Resource->GetTexture(L"T_Hammer"), 51, 0, 51, 51);

		_hammer = new HammerActor();
		_hammer->Init();
		this->SpawnActor(_hammer);
	}
	
	//Controller
	{
		_playerhammerController = new PlayerHammerController();
		_playerhammerController->Init(_hammer, _moles);
	}

	_regenTimer = 0.5f;
	_playTime = 60.0f;
	_score = 0;
}
void MoleGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"MoleGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring pointStr = format(L"Point : {0}", _score);
	::TextOut(hdc, 0, 65, pointStr.c_str(), pointStr.length());

	wstring timeStr = format(L"Time : {0:*>.1f}", _playTime);
	::TextOut(hdc, 0, 85, timeStr.c_str(), timeStr.length());
}
void MoleGameScene::Update()
{
	Super::Update();
	_playerhammerController->Update();

	//-------------------------
	//		* Play Time *
	//-------------------------
	_playTime -= Time->GetDeltaTime();
	if (_playTime <= 0)
	{// 시간이 오버되면 다른 장면으로 넘어감
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}

	//-------------------------
	//		* Mole Code *
	//-------------------------
	// N초마다 랜덤한 두더지가 ChangeState(Out)으로 변한다.
	_regenTimer -= Time->GetDeltaTime();
	if (_regenTimer <= 0.0f)
	{
		MoleActor* randomMoleActor = _moles[Random->GetRandomInt(0, _moles.size() - 1)];
		if (randomMoleActor->GetGameState() == MoleActorState::In)
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
