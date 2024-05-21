#include "pch.h"
#include "Dev2Scene.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include  "NumberBlockActor.h"
#include "Game2048Controller.h"
void Dev2Scene::Init()
{
	Super::Init();
	RoadResource();
	
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
	/*
	for (int j = 0; j < 2; j++)
	{
		NumberBlockActor* numberBlock = new NumberBlockActor();
		numberBlock->Init();
		numberBlock->SetPos(Vector2(-200 + j * 100, -200));
		_blockTest.push_back(numberBlock);
		SpawnActor(_blockTest.back());
	}
	*/
	{
		_game2048Controller = new Game2048Controller();
		_game2048Controller->Init(_numberBlocks);
	}
}
void Dev2Scene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"2048";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev2Scene::Update()
{
	Super::Update();
	_game2048Controller->Update();
	/*
	if (Input->GetKeyDown(KeyCode::Down))
	{
		_blockTest[0]->ChangeDirectionState(NumberBlockDirState::Down);
		_blockTest[1]->ChangeDirectionState(NumberBlockDirState::Down);
	}
	else if (Input->GetKeyDown(KeyCode::Up))
	{
		_blockTest[0]->ChangeDirectionState(NumberBlockDirState::Up);
		_blockTest[1]->ChangeDirectionState(NumberBlockDirState::Up);
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		_blockTest[0]->ChangeDirectionState(NumberBlockDirState::Left);
		_blockTest[1]->ChangeDirectionState(NumberBlockDirState::Left);
	}
	else if (Input->GetKeyDown(KeyCode::Right))
	{
		_blockTest[0]->ChangeDirectionState(NumberBlockDirState::Right);
		_blockTest[1]->ChangeDirectionState(NumberBlockDirState::Right);
	}
	*/
}
void Dev2Scene::Release()
{
	Super::Release();
}

void Dev2Scene::RoadResource()
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
}