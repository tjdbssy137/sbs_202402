#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"

void BrickActor::Init()
{
	Super::Init();

	for (int i = 0; i < 4; i++)
	{
		wstring textureKey = ::format(L"T_brick_{0}", i);
		wstring texturePath = ::format(L"BrickGame/brick_{0}.bmp", i);
		wstring spriteKey = ::format(L"S_brick_{0}", i);
		Resource->LoadTexture(textureKey, texturePath);
		Resource->CreateSprite(spriteKey, Resource->GetTexture(textureKey));
	}
	
	wstring spriteKey = ::format(L"S_brick_{0}", Random->GetRandomInt(0, 3));
	this->SetSprite(Resource->GetSprite(spriteKey));

	
	this->SetName("Brick");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 45, 22));
	this->AddComponent(collider);

}

void BrickActor::Render(HDC hdc)
{
	Super::Render(hdc);
	//_body.Draw(hdc);
}

void BrickActor::Update()
{
	Super::Update();
}

void BrickActor::Release()
{
	Super::Release();
}
void BrickActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

}