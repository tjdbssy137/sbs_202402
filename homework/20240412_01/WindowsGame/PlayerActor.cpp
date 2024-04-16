#include "pch.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "PooGame.h"

void PlayerActor::Init()
{
	Super::Init();

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 30));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, 700, 60, 40));

	_speed = 400;
}
void PlayerActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void PlayerActor::Update()
{
	Super::Update();
}
void PlayerActor::Release()
{
	Super::Release();
}

void PlayerActor::Move(Vector2 moveDir)
{
	if (moveDir.Length() == 0.0f)
	{
		return;
	}
	if (moveDir.y != 0)
	{
		moveDir.y = 0;
		moveDir = moveDir.Normalize();
	}

	_body.pos += moveDir * Time->GetDeltaTime() * _speed;
}

void PlayerActor::SetPos(Vector2 position)
{
	this->_body.pos = position;
}

void PlayerActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	if (other->GetOwner()->GetName() == "Poo")
	{
		PooGame* currentScene = dynamic_cast<PooGame*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (currentScene != nullptr)
		{
			currentScene->ChangeGameState(GameState::Wait);
		}
	}
	
}