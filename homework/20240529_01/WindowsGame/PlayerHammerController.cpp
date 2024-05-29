#include "pch.h"
#include "PlayerHammerController.h"
#include "HammerActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "MoleGameScene.h"
void PlayerHammerController::Init(HammerActor* playerHammer, vector<MoleActor*> moles)
{
	_playerHammer = playerHammer;
	_moles = moles;
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
void PlayerHammerController::ChangePlayerHammerPos()
{
	POINT mousePos = Input->GetMousePos();
	_playerHammer->SetPos(mousePos);
}
void PlayerHammerController::CatchMole()
{
	POINT mousePos = Input->GetMousePos();
	for (MoleActor* mole : _moles)
	{
		BoxCollider* moleCollider = mole->GetComponent<BoxCollider>();

		if (Collision::PtInRect(mousePos, moleCollider->GetCollision().ToRect()))
		{
			if (mole->GetState() == MoleActorState::Out)
			{
				//점수는 씬에있죠.

				//현재씬을 가지고올수있다.
				MoleGameScene* currentScene = dynamic_cast<MoleGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
				if (currentScene != nullptr)
				{
					//MoleGameScene일때만 동작

					currentScene->PlusScore();
				}

				mole->ChangeState(MoleActorState::Die);
			}
		}
	}
}