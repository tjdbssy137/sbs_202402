#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"
void BrickActor::Init()
{
	Super::Init();
	//강사님 코드 다시 확인
	for (int i = 0; i < 4; i++)
	{
		wstring textureKey = ::format(L"T_brick_{0}", i);
		wstring texturePath = ::format(L"BrickGame/brick_{0}.bmp", i);
		wstring spriteKey = ::format(L"S_brick_{0}", i);

		Resource->LoadTexture(textureKey, texturePath);//확장자명은 내가 쓰는 거 아님.
		Resource->CreateSprite(spriteKey, Resource->GetTexture(textureKey));
	}
	wstring spriteKey = ::format(L"S_brick_{0}", Random->GetRandomInt(0, 3));
	this->SetSprite(Resource->GetSprite(spriteKey));

	this->SetName("Brick");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 40));
	this->AddComponent(collider);

	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, 30, 100, 40));

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