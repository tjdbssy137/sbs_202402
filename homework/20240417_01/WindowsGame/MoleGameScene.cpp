#include "pch.h"
#include "MoleGameScene.h"
#include "SpriteActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"

void MoleGameScene::Init()
{
	Super::Init();

	// ���
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

	// �δ���
	Resource->LoadTexture(L"T_Mole", L"Mole/mole.bmp");
	Resource->CreateSprite(L"S_Mole_Idle", Resource->GetTexture(L"T_Mole"), 0, 0, 85, 113); // �׸��� �� ���� ����
	Resource->CreateSprite(L"S_Mole_Die", Resource->GetTexture(L"T_Mole"), 85, 0, 85, 113);
	//�ѹ� �ε��ϸ� ������ �����ص� ��� ����
	
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
		_mole.push_back(mole);
		this->SpawnActor(_mole[i]);
	}
	

	// ��ġ
	{
		Resource->LoadTexture(L"T_Hammer", L"Mole/hammer.bmp");
		Resource->CreateSprite(L"S_Hammer_Idle", Resource->GetTexture(L"T_Hammer"), 0, 0, 51, 51);
		Resource->CreateSprite(L"S_Hammer_Hit", Resource->GetTexture(L"T_Hammer"), 51, 0, 51, 51);

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
	_playTime = 60.0f;

}
void MoleGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"MoleGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring pointStr = format(L"Point : {0}", _point);
	::TextOut(hdc, 0, 65, pointStr.c_str(), pointStr.length());

	wstring timeStr = format(L"Time : {0:*>.1f}", _playTime);
	::TextOut(hdc, 0, 85, timeStr.c_str(), timeStr.length());
}
void MoleGameScene::Update()
{
	Super::Update();

	//-------------------------
	//		* Play Time *
	//-------------------------
	_playTime -= Time->GetDeltaTime();
	if (_playTime <= 0)
	{// �ð��� �����Ǹ� �ٸ� ������� �Ѿ
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}

	//-------------------------
	//		* Hammer Code *
	//-------------------------
	MovementMouse();

	//-------------------------
	//		* Mole Code *
	//-------------------------
	// N�ʸ��� ������ �δ����� ChangeState(Out)���� ���Ѵ�.
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

	// ���� �δ����� �ִ��� Ȯ���ϰ� state ���� �� ���� �߰�.
	for (int i = 0; i < 8; i++)
	{
		if (Collision::RectInRect(_mole[i]->GetBody().ToRect(), _hammer->GetBody().ToRect()))
		{
			if (_isHit == true)
			{
				_isHit = false;
				if (_mole[i]->GetIsDie() == false) // ����Ŭ�� ���� ����
				{
					_point++;
				}
				_mole[i]->ChangeState(MoleActorState::Die);
			}
		}
	}
}
void MoleGameScene::Release()
{
	Super::Release();
}

void MoleGameScene::MovementMouse()
{
	POINT mousePos = Input->GetMousePos();
	_hammer->SetBody(Shape::MakeCenterRect(mousePos.x, mousePos.y, 51, 51));
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_hammer->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));
		_isHit = true;
	}
	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		_hammer->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
		_isHit = false;
	}
}
