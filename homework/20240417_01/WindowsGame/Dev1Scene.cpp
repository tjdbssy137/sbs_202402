#include "pch.h"
#include "Dev1Scene.h"
#include "SpriteActor.h"
#include "BoxCollider.h"

void Dev1Scene::Init()
{
	Super::Init();

	//texture = T_
	//sprite = S_
	//Windows API���� bmp�ۿ� ��� �� ��
	//������, ���ӿ��� png������ �ξ� �� ���� ���
	//png�� Direct X
	Resource->LoadTexture(L"T_MoleBackground", L"Mole/bg_mole.bmp");//Ȯ���ڸ��� ���� ���� �� �ƴ�.
	Resource->CreateSprite(L"S_MoleBackground", Resource->GetTexture(L"T_MoleBackground"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_MoleBackground"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 795, 381));
		SpawnActor(spriteActor);
	}

	Resource->LoadTexture(L"T_Character", L"Mole/idle.bmp");//Ȯ���ڸ��� ���� ���� �� �ƴ�.
	Resource->CreateSprite(L"S_Character", Resource->GetTexture(L"T_Character"));

	{
		SpriteActor* spriteActor = new SpriteActor();
		spriteActor->SetSprite(Resource->GetSprite(L"S_Character"));
		spriteActor->Init();
		spriteActor->SetBody(Shape::MakeCenterRectLTRB(0, 0, 258, 328));
		SpawnActor(spriteActor);
	}
}
void Dev1Scene::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
}
void Dev1Scene::Update()
{
	Super::Update();
	
}
void Dev1Scene::Release()
{
	Super::Release();
}