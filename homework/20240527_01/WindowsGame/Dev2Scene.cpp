#include "pch.h"
#include "Dev2Scene.h"
#include "TestPanel.h"
#include "Flipbook.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "MapToolTilemapActor.h"
#include "CreatureActor.h"
#include "CameraComponent.h"

void Dev2Scene::Init()
{
	LoadResource();
	for (int i = 0; i <= 12; i++)
	{
		{
			wchar_t keyName[128];
			swprintf_s(keyName, L"T_Pocket%d", i);

			wchar_t valueName[128];
			swprintf_s(valueName, L"TileStudy/pocket_%d.bmp", i);

			Resource->LoadTexture(keyName, valueName);
		}

		{
			wchar_t keyName[128];
			swprintf_s(keyName, L"S_Pocket%d", i);

			wchar_t textureKeyName[128];
			swprintf_s(textureKeyName, L"T_Pocket%d", i);

			Resource->CreateSprite(keyName, Resource->GetTexture(textureKeyName));
		}
	}

	int array[100] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 2, 3, 3, 3, 4, 7, 7, 8,
		7, 2, 5, 3, 3, 3, 6, 4, 7, 8,
		7, 5, 5, 3, 3, 3, 6, 6, 7, 8,
		7, 5, 5, 3, 3, 3, 6, 6, 7, 8,
		7, 5, 9, 0, 0, 0, 11, 6, 7, 8,
		7, 9, 0, 0, 0, 0, 0, 11, 7, 8,
		7, 7, 1, 1, 7, 7, 7, 1, 7, 8,
		7, 7, 1, 7, 7, 7, 7, 1, 7, 8,
		7, 7, 1, 7, 7, 7, 7, 1, 7, 8
	};

	{
		Vector2Int mapSize = Vector2Int(10, 10);
		vector<vector<Tile>> tiles;
		int i = 0;
		for (int height = 0; height < mapSize.y; height++)
		{
			vector<Tile> tilesDummy;
			for (int width = 0; width < mapSize.x; width++)
			{
				Tile tile;
				tile.value = array[i];
				tilesDummy.push_back(tile);
				i++;
			}
			tiles.push_back(tilesDummy);
		}
		Resource->CreateTileMap(L"TM_Test", mapSize, 88, tiles);
	}

	{
		MapToolTilemapActor* actor = new MapToolTilemapActor();
		actor->SetTileMap(Resource->GetTileMap(L"TM_Test"));
		{
			vector<Sprite*> sprites;
			for (int i = 0; i <= 12; i++)
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_Pocket%d", i);
				sprites.push_back(Resource->GetSprite(keyName));
			}
			actor->SetTileSprites(sprites);
		}
		actor->Init();
		this->SpawnActor(actor);
	}

	{
		_creature = new CreatureActor();
		_creature->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		_creature->SetName("Creature");
		{
			CameraComponent* component = new CameraComponent();
			component->SetLTWH(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
			component->Init();
			_creature->AddComponent(component);
		}
		_creature->Init();
		_creature->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Idle"));
		SpawnActor(_creature); // 왜 안될까
	}

	/*
	{
		TestPanel* testPanel = new TestPanel();
		_uis.push_back(testPanel);
	}
	*/
	Super::Init();
}
void Dev2Scene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"Dev2Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}
void Dev2Scene::Update()
{
	Super::Update();
	_creature->Update();
}
void Dev2Scene::Release()
{
	Super::Release();
}

void Dev2Scene::LoadResource()
{
	//----------------------------------
	//  ## PlayerDown Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerDown", L"FlipbookTest/PlayerDown.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## PlayerUp Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerUp"
			, L"FlipbookTest/PlayerUp.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## PlayerLeft Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerLeft"
			, L"FlipbookTest/PlayerLeft.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftAttack", flipbookInfo);
		}
	}

	//----------------------------------
	//  ## PlayerRight Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerRight"
			, L"FlipbookTest/PlayerRight.bmp"
			, RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightAttack", flipbookInfo);
		}
	}
}