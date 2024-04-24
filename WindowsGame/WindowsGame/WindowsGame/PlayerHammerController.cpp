#include "pch.h"
#include "PlayerHammerController.h"
#include "HammerActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "MoleGameScene.h"
void PlayerHammerController::Init(HammerActor* playerHammer, vector<MoleActor*> mole)
{
	//Linking 작업
	// Init말고 SetLink라고도 함
	_playerHammer = playerHammer;
	_mole = mole;
}

void PlayerHammerController::Update()
{
	this->ChangePlayerHammerPos();
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Hit);
		this->CatchMole();
	}
	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Idle);
	}
	
}

void PlayerHammerController::CatchMole()
{
	POINT mousePos = Input->GetMousePos();

	for (MoleActor* mole : _mole)
	{
		BoxCollider* moleCollider = mole->GetComponent<BoxCollider>();
		if (Collision::PtInRect(mousePos, moleCollider->GetCollision().ToRect()))
		{
			if (mole->GetGameState() == MoleActorState::Out)
			{
				//현재 씬을 가지고 올 수 있다.
				MoleGameScene* currentScene = dynamic_cast<MoleGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
				if (currentScene != nullptr)
				{
					// 코드는 평생 감
					// 오류를 방어하기 위해 if()문 추가
					//MoleGameScene일 때만 동작
					currentScene->PlusScore();
				}
				mole->ChangeState(MoleActorState::Die);
			}
		}
	}
}

void PlayerHammerController::ChangePlayerHammerPos()
{
	POINT mousePos = Input->GetMousePos();
	_playerHammer->SetPos(mousePos);
}