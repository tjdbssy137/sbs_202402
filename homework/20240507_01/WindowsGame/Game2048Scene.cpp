#include "pch.h"
#include "Game2048Scene.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "NumberBlockActor.h"
#include "Game2048Controller.h"
void Game2048Scene::Init()
{
	Super::Init();
	RoadResource();


	{
		SpriteActor* background = new SpriteActor();
		background->Init();
		background->SetPos(Vector2(-50, -50));
		background->SetSprite(Resource->GetSprite(L"S_2048BackGound"));
		SpawnActor(background);
	}

	for (int i = 0; i < 4; i++)//INSTINATE_MAX
	{
		for (int j = 0; j < 4; j++)
		{
			NumberBlockActor* numberBlock = new NumberBlockActor();
			numberBlock->Init();
			numberBlock->SetPos(Vector2(-200 + i * 100, -200 + j * 100));
			_numberBlocks.push_back(numberBlock);
			SpawnActor(_numberBlocks.back());
		}
	}

	{
		_game2048Controller = new Game2048Controller();
		_game2048Controller->Init(_numberBlocks);
	}
}
void Game2048Scene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"2048";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring gameScore = format(L"Score : {0}", _game2048Controller->GetGameScore());
	::TextOut(hdc, 0, 65, gameScore.c_str(), gameScore.length());

}
void Game2048Scene::Update()
{
	Super::Update();
	_game2048Controller->Update();
}
void Game2048Scene::Release()
{
	Super::Release();
}

void Game2048Scene::RoadResource()
{
	Resource->LoadTexture(L"T_2048", L"2048/IMAGE2048.bmp");

	Resource->CreateSprite(L"S_Number_2", Resource->GetTexture(L"T_2048"), 0, 0, 100, 100);
	Resource->CreateSprite(L"S_Number_4", Resource->GetTexture(L"T_2048"), 100, 0, 100, 100);
	Resource->CreateSprite(L"S_Number_8", Resource->GetTexture(L"T_2048"), 200, 0, 100, 100);
	Resource->CreateSprite(L"S_Number_16", Resource->GetTexture(L"T_2048"), 300, 0, 100, 100);
	Resource->CreateSprite(L"S_Number_32", Resource->GetTexture(L"T_2048"), 0, 100, 100, 100);
	Resource->CreateSprite(L"S_Number_64", Resource->GetTexture(L"T_2048"), 100, 100, 100, 100);
	Resource->CreateSprite(L"S_Number_128", Resource->GetTexture(L"T_2048"), 200, 100, 100, 100);
	Resource->CreateSprite(L"S_Number_256", Resource->GetTexture(L"T_2048"), 300, 100, 100, 100);
	Resource->CreateSprite(L"S_Number_512", Resource->GetTexture(L"T_2048"), 0, 200, 100, 100);
	Resource->CreateSprite(L"S_Number_1024", Resource->GetTexture(L"T_2048"), 100, 200, 100, 100);
	Resource->CreateSprite(L"S_Number_2048", Resource->GetTexture(L"T_2048"), 300, 200, 100, 100);

	Resource->LoadTexture(L"T_2048BackGound", L"2048/IMAGE2048_Background.bmp");
	Resource->CreateSprite(L"S_2048BackGound", Resource->GetTexture(L"T_2048BackGound"));
}