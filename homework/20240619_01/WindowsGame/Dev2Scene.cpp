#include "pch.h"
#include "Dev2Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CreatureActor.h"
#include "CameraComponent.h"
#include "Texture.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "TestPanel.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "MapToolTilemapActor.h"
#include "MapToolController.h"
#include "CreatureController.h"

void Dev2Scene::Init()
{
	LoadResource();
	{
		for (int i = 6; i <= 67; i++)
		{
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"T_BeachTileset%d", i);

				wchar_t valueName[128];
				swprintf_s(valueName, L"BeachTileset/BeachTileset_%d.bmp", i);

				Resource->LoadTexture(keyName, valueName);
			}

			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_BeachTileset%d", i);

				wchar_t textureKeyName[128];
				swprintf_s(textureKeyName, L"T_BeachTileset%d", i);

				Resource->CreateSprite(keyName, Resource->GetTexture(textureKeyName));
			}
		}

	}

	{
		Vector2Int mapSize = Vector2Int(55, 26);
		vector<vector<Tile>> tiles;
		for (int height = 0; height < mapSize.y; height++)
		{
			vector<Tile> tilesDummy;
			for (int width = 0; width < mapSize.x; width++)
			{
				Tile tile;
				tile.value = 0;
				tilesDummy.push_back(tile);
			}
			tiles.push_back(tilesDummy);
		}

		Resource->CreateTileMap(L"TM_Test", mapSize, 32, tiles);
	}

	_mapToolController = new MapToolController();

	{
		MapToolTilemapActor* actor = new MapToolTilemapActor();
		actor->SetTileMap(Resource->GetTileMap(L"TM_Test"));
		{
			vector<Sprite*> sprites;
			for (int i = 6; i <= 67; i++)
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_BeachTileset%d", i);
				sprites.push_back(Resource->GetSprite(keyName));
			}

			actor->SetTileSprites(sprites);
		}
		actor->SetLayer(LayerType::Background);
		actor->Init();

		//이 액터를 조종하겠습니다.
		_mapToolController->SetLink(actor);

		this->SpawnActor(actor);
		_tilemapActor = actor;
	}
	_creatureController = new CreatureController();
	{
		CreatureActor* boat = new CreatureActor();
		boat->SetLayer(LayerType::Character);
		boat->Init();
		_creatureController->SetLink(boat);
		this->SpawnActor(boat);
		boat->SetCellPos({ 20, 10 }, true);
	}
	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

	Super::Init();

}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Beach";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}
void Dev2Scene::Update()
{
	Super::Update();

	_mapToolController->Update();
	_creatureController->Update();
}
void Dev2Scene::Release()
{
	Super::Release();
}

void Dev2Scene::LoadResource()
{
	// -------------------------------------
	// 
	//			BOAT RESOURCE
	// 
	// ------------------------------------- 
	//direction
	wstring direction[8] = {L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight"};
	//EnemyBoat1
	{
		Resource->LoadTexture(L"T_EnemyBoat1", L"FlipbookTest/enemyBoat1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyBoat1 = {};
		info_enemyBoat1.start = 0;
		info_enemyBoat1.end = 2;
		info_enemyBoat1.line = 0;
		info_enemyBoat1.size = Vector2Int(32, 32);
		info_enemyBoat1.duration = 1.0f;
		info_enemyBoat1.loop = true;
		info_enemyBoat1.texture = Resource->GetTexture(L"T_EnemyBoat1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyBoat1_" + direction[i];
			info_enemyBoat1.line = i;
			Resource->CreateFlipbook(fullName, info_enemyBoat1);
		}
	}
	
	//EnemyBoat2
	{
		Resource->LoadTexture(L"T_EnemyBoat2", L"FlipbookTest/enemyBoat2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyBoat2 = {};
		info_enemyBoat2.start = 0;
		info_enemyBoat2.end = 2;
		info_enemyBoat2.line = 0;
		info_enemyBoat2.size = Vector2Int(32, 32);
		info_enemyBoat2.duration = 1.0f;
		info_enemyBoat2.loop = true;
		info_enemyBoat2.texture = Resource->GetTexture(L"T_EnemyBoat2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyBoat2_" + direction[i];
			info_enemyBoat2.line = i;
			Resource->CreateFlipbook(fullName, info_enemyBoat2);
		}
	}

	//EnemyShip1
	{
		Resource->LoadTexture(L"T_EnemyShip1", L"FlipbookTest/enemyShip1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship1 = {};
		info_enemyship1.start = 0;
		info_enemyship1.end = 2;
		info_enemyship1.line = 0;
		info_enemyship1.size = Vector2Int(32, 32);
		info_enemyship1.duration = 1.0f;
		info_enemyship1.loop = true;
		info_enemyship1.texture = Resource->GetTexture(L"T_EnemyShip1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip1_" + direction[i];
			info_enemyship1.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship1);
		}
	}

	//EnemyShip2
	{
		Resource->LoadTexture(L"T_EnemyShip2", L"FlipbookTest/enemyShip2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship2 = {};
		info_enemyship2.start = 0;
		info_enemyship2.end = 2;
		info_enemyship2.line = 0;
		info_enemyship2.size = Vector2Int(32, 32);
		info_enemyship2.duration = 1.0f;
		info_enemyship2.loop = true;
		info_enemyship2.texture = Resource->GetTexture(L"T_EnemyShip2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip2_" + direction[i];
			info_enemyship2.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship2);
		}
	}

	//EnemyShip3
	{
		Resource->LoadTexture(L"T_EnemyShip3", L"FlipbookTest/enemyShip3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_enemyship3 = {};
		info_enemyship3.start = 0;
		info_enemyship3.end = 2;
		info_enemyship3.line = 0;
		info_enemyship3.size = Vector2Int(32, 32);
		info_enemyship3.duration = 1.0f;
		info_enemyship3.loop = true;
		info_enemyship3.texture = Resource->GetTexture(L"T_EnemyShip3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip3_" + direction[i];
			info_enemyship3.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship3);
		}
	}
	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");

	//----------------------------------
	//  ## UI
	//----------------------------------

}

Vector2 Dev2Scene::GetTilemapPos(Vector2Int cellPos)
{
	assert(_tilemapActor != nullptr); // 유효성 검사
	if (_tilemapActor == nullptr)
	{
		return Vector2::Zero();
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return Vector2::Zero();
	}

	int tileSize = tilemap->GetTileSize();
	Vector2 pos = _tilemapActor->GetPos();

	Vector2 rv;
	rv.x = pos.x + cellPos.x * tileSize + (tileSize / 2);
	rv.y = pos.y + cellPos.y * tileSize + (tileSize / 2);
	return rv;
}

bool Dev2Scene::CanGo(Actor* actor, Vector2Int cellPos)
{
	assert(actor != nullptr);
	if (actor == nullptr)
	{
		return false;
	}
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return false;
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return false;
	}

	Tile* tile = tilemap->GetTileAt(cellPos);
	if (tile == nullptr)
	{
		return false;
	}
	// 위에는 전부 유효성 검사 
	if (tile->value == 51) // 51이 물
	{
		return true;
	}
	return false;
}

Tilemap* Dev2Scene::GetTilemap()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}

	Tilemap* tilemap = _tilemapActor->GetTileMap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return nullptr;
	}
	return tilemap;
}

TilemapActor* Dev2Scene::GetTilemapActor()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}
	return _tilemapActor;
}