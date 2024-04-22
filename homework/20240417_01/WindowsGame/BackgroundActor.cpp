#include "pch.h"
#include "BackgroundActor.h"

void BackgroundActor::Init()
{
	Super::Init();

	this->SetName("Mole");
	Resource->LoadTexture(L"T_Background", L"Mole/background.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Background", Resource->GetTexture(L"T_Background"));

	this->SetSprite(Resource->GetSprite(L"S_Background"));

	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2 , WIN_SIZE_Y / 2, 800, 600));
}
void BackgroundActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BackgroundActor::Update()
{
	Super::Update();
}
void BackgroundActor::Release()
{
	Super::Release();
}