#include "pch.h"
#include "Dev2Scene.h"
#include "BadukActor.h"//없어도될듯
void Dev2Scene::Init()
{
	Super::Init();

	{
		Resource->LoadTexture(L"T_BadukPlane", L"Baduk/plane.bmp");
		Resource->CreateSprite(L"S_BadukPlane", Resource->GetTexture(L"T_BadukPlane"));

		SpriteActor* background = new SpriteActor();
		background->SetName("BadukPlane");
		background->SetSprite(Resource->GetSprite(L"S_BadukPlane"));
		background->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		background->Init();
		this->SpawnActor(background);
	}

	{
		Resource->LoadTexture(L"T_Baduk", L"Baduk/Baduk_100.bmp");
		Resource->CreateSprite(L"S_White", Resource->GetTexture(L"T_Baduk"), 0, 0, 100, 100);
		Resource->CreateSprite(L"S_Black", Resource->GetTexture(L"T_Baduk"), 100, 0, 100, 100);

		for (int i = 0; i < 2; i++)
		{
			BadukActor* baduk = new BadukActor();
			baduk->Init();
			baduk->SetSprite(Resource->GetSprite(L"S_White"));
			baduk->SetPos(Vector2(100, 100*i));
			_whiteBaduks.push_back(baduk);
			SpawnActor(_whiteBaduks.back());
		}

		for (int i = 0; i < 2; i++)
		{
			BadukActor* baduk = new BadukActor();
			baduk->Init();
			baduk->SetSprite(Resource->GetSprite(L"S_Black"));
			baduk->SetPos(Vector2(300, 100 * i)); 
			_blackBaduks.push_back(baduk);
			SpawnActor(_blackBaduks.back());
		}
	}


}
void Dev2Scene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"Baduk";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev2Scene::Update()
{
	Super::Update();

}
void Dev2Scene::Release()
{
	Super::Release();
}