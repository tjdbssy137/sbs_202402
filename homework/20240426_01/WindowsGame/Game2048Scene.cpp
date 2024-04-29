#include "pch.h"
#include "Game2048Scene.h"
#include "NumberRectActor.h"
#include "BoxCollider.h"

void Game2048Scene::Init()
{
	Super::Init();
	{
		Resource->LoadTexture(L"T_2048", L"2048/IMAGE2048.bmp");
		Resource->CreateSprite(L"S_Number_2", Resource->GetTexture(L"T_2048"), 0, 0, 300, 300);
		Resource->CreateSprite(L"S_Number_4", Resource->GetTexture(L"T_2048"), 300, 0, 300, 300);
		Resource->CreateSprite(L"S_Number_8", Resource->GetTexture(L"T_2048"), 600, 0, 300, 300);
		Resource->CreateSprite(L"S_Number_16", Resource->GetTexture(L"T_2048"), 900, 0, 300, 300);
		Resource->CreateSprite(L"S_Number_32", Resource->GetTexture(L"T_2048"), 0, 300, 300, 300);
		Resource->CreateSprite(L"S_Number_64", Resource->GetTexture(L"T_2048"), 300, 300, 300, 300);
		Resource->CreateSprite(L"S_Number_128", Resource->GetTexture(L"T_2048"), 600, 300, 300, 300);
		Resource->CreateSprite(L"S_Number_256", Resource->GetTexture(L"T_2048"), 900, 300, 300, 300);
		Resource->CreateSprite(L"S_Number_512", Resource->GetTexture(L"T_2048"), 0, 600, 300, 300);
		Resource->CreateSprite(L"S_Number_1024", Resource->GetTexture(L"T_2048"), 300, 600, 300, 300);
		Resource->CreateSprite(L"S_Number_2048", Resource->GetTexture(L"T_2048"), 600, 600, 300, 300);
	
		for (int i = 0; i < INSTINATE_MAX; i++)
		{
			NumberRectActor* numberRect = new NumberRectActor();
			numberRect->Init();
			_numberRects.push_back(numberRect);
			SpawnActor(_numberRects.back());
		}
	}

}

void Game2048Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Game 2048 Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());


}
void Game2048Scene::Update()
{
	Super::Update();


}
void Game2048Scene::Release()
{
	Super::Release();

}