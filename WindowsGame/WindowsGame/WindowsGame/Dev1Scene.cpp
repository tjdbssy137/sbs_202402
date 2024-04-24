#include "pch.h"
#include "Dev1Scene.h"
#include "SpriteActor.h"
#include "BoxCollider.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
void Dev1Scene::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Character", L"FlipbookTest/character.bmp");
	FlipbookInfo info = {};
	info.start = 0;
	info.end = 12;
	info.size = Vector2Int(32, 32);
	info.texture = Resource->GetTexture(L"T_Character");
	Resource->CreateFlipbook(L"FB_characterIdle", info);
	{
		FlipbookActor* flipbookActor = new FlipbookActor();
		flipbookActor->SetFlipbook();

		flipbookActor->SetFlipbook(Resource->GetFlipbook(L"FB_characterIdle"));
		flipbookActor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y /2));
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