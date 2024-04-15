#include "pch.h"
#include "MoleHouseActor.h"

void MoleHouseActor::Init()
{
	Super::Init();
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 100));
}
void MoleHouseActor::Render(HDC hdc)
{
	Super::Render(hdc);
	_body.Draw(hdc);
}
void MoleHouseActor::Update()
{
	Super::Update();
}
void MoleHouseActor::Release()
{
	Super::Release();
}