#include "pch.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "WhacAMole.h"

void MoleActor::Init()
{
	Super::Init();
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 70, 70));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 70, 70));
	_isCollision = false;
}
void MoleActor::Render(HDC hdc)
{
	Super::Render(hdc);
	_body.Draw(hdc);
}
void MoleActor::Update()
{
	Super::Update();
}
void MoleActor::Release()
{
	Super::Release();
}

void MoleActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	if (other->GetOwner()->GetName() == "hammer" && _isTrigger == false)
	{
		_fight = true;
	}
}

void MoleActor::OnTriggerExit(Collider* collider, Collider* other)
{
	Super::OnTriggerExit(collider, other);
	if (other->GetOwner()->GetName() == "hammer")
	{
		_fight = false;
	}
}

void MoleActor::MoleGetsSmaller(RECT rect)
{
	_isTrigger = false;
	_body = CenterRect(Vector2(rect.right - (rect.right - rect.left)/2, rect.bottom - (rect.bottom - rect.top) / 2), 70, 70);
}
void MoleActor::MoleGetsBigger(RECT rect)
{
	_isTrigger = true;
	_body = CenterRect(Vector2(rect.right - (rect.right - rect.left) / 2, rect.bottom - (rect.bottom - rect.top) / 2), 100, 100);
}