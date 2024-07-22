#include "pch.h"
#include "Dev2Scene.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "BoatActor.h"
#include "BehicleActor.h"
#include "CameraComponent.h"
#include "Texture.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "TestPanel.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "MapToolTilemapActor.h"
#include "BoatController.h"
#include "BehicleController.h"
#include "RedBlockActor.h"
#include "RedBlockController.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "GameWave.h"
#include "InstallPanel.h"
#include "InstallSubmarinePanel.h"
#include "ActionButtonsPanel.h"

void Dev2Scene::Init()
{
	LoadResource();
	{// Day54에서 쓴 코드랑 비교해서 수정
		// TilemapActor 에서 LoadTimemap(wstring filename); 추가
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
		actor->Load();

		this->SpawnActor(actor);
		_tilemapActor = actor;
	}

	{
		_bulletController = new BulletActorController();
		for (int i = 0; i < 30; i++) // ObjectPooling
		{
			BulletActor* bullet = new BulletActor();
			bullet->SetLayer(LayerType::Object);
			bullet->SetPos({ 2000, 2000 });
			bullet->Init();
			this->SpawnActor(bullet);
			_bulletController->PushBullet(bullet);
		}
	}

	for (int i = 0; i < 47; i++)
	{
		BoatController* boatController = new BoatController();
		_boatControllers.push_back(boatController);
		{
			BoatActor* boat = new BoatActor();
			boat->SetLayer(LayerType::Character);
			boat->Init();
			_boatControllers[i]->SetLink(boat);
			this->SpawnActor(boat);
			boat->SetCellPos({ 54, 25 }, true); //boat->SetCellPos({ 25 + i, 13 }, true);
			_boats.push_back(boat);
		}
	}

	_redBlockController = new RedBlockController();
	{
		RedBlockActor* redBlock = new RedBlockActor();
		redBlock->SetLayer(LayerType::Object);
		redBlock->Init();
		_redBlockController->SetLink(redBlock);
		this->SpawnActor(redBlock);
		redBlock->SetCellPos({ 1, 1 }, true);
	}
	{//도착지점
		SpriteActor* actor = new SpriteActor();
		actor->SetLayer(LayerType::Object);
		actor->SetSprite(Resource->GetSprite(L"S_BeachTileset_2"));
		this->SpawnActor(actor);
		actor->SetPos({ 5 * 31, 4 * 30 });
	}

	{
		_gameWave = new GameWave();
		_gameWave->SetLink(_boats);
	}

	{
		_installPanel = new InstallPanel();
		_installPanel->Init();
		_installPanel->Hide();
	}

	{
		_installSubmarinePanel = new InstallSubmarinePanel();
		_installSubmarinePanel->Init();
		_installSubmarinePanel->Hide();
	}

	{
		_actionButtonsPanel = new ActionButtonsPanel();
		_actionButtonsPanel->Init();
		_actionButtonsPanel->Hide();
	}

	// behicle을 여러개 생성해두고? 마우스 좌표로 비히클 위치를 지정해주는 클래스를 새로 만들어야할 듯.
	// 마우스를 가져다 대면 빨간색의 작은 타일이 생기고 그곳을 누르면 설치.. (panel이 마우스를 따라다니며 어떤 걸 설치할 지 메뉴)

	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

	Super::Init();

}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Beach";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	_installPanel->Render(hdc);
	_installSubmarinePanel->Render(hdc);
	_actionButtonsPanel->Render(hdc);
}
void Dev2Scene::Update()
{
	Super::Update();

	for (BoatController* boatController : _boatControllers)
	{
		boatController->Update();
	}
	for (BehicleController* behicleController : _behicleControllers)
	{
		behicleController->Update();
	}
	_redBlockController->Update();

	_gameWave->Update();
	if (Input->GetKeyDown(KeyCode::W))
	{
		_gameWave->SetGameWaveState(GameWaveState::Wave);
	}
	_installPanel->Update();
	_installSubmarinePanel->Update();
	_actionButtonsPanel->Update();
}
void Dev2Scene::Release()
{
	Super::Release();
	_installPanel->Release();
	_installSubmarinePanel->Release();
	_actionButtonsPanel->Release();
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
		info_enemyBoat1.duration = 0.6f;
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
		info_enemyBoat2.duration = 0.6f;
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
		info_enemyship1.duration = 0.6f;
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
		info_enemyship2.duration = 0.6f;
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
		info_enemyship3.duration = 0.6f;
		info_enemyship3.loop = true;
		info_enemyship3.texture = Resource->GetTexture(L"T_EnemyShip3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_EnemyShip3_" + direction[i];
			info_enemyship3.line = i;
			Resource->CreateFlipbook(fullName, info_enemyship3);
		}
	}

	// -------------------------------------
	// 
	//			BEHICLE RESOURCE
	// 
	// ------------------------------------- 
	//DrillTank1
	{
		Resource->LoadTexture(L"T_DrillTank1", L"FlipbookTest/drillTank1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank1 = {};
		info_drillTank1.start = 0;
		info_drillTank1.end = 2;
		info_drillTank1.line = 0;
		info_drillTank1.size = Vector2Int(32, 32);
		info_drillTank1.duration = 0.6f;
		info_drillTank1.loop = true;
		info_drillTank1.texture = Resource->GetTexture(L"T_DrillTank1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank1_" + direction[i];
			info_drillTank1.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank1);
		}
	}

	//DrillTank2
	{
		Resource->LoadTexture(L"T_DrillTank2", L"FlipbookTest/drillTank2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank2 = {};
		info_drillTank2.start = 0;
		info_drillTank2.end = 2;
		info_drillTank2.line = 0;
		info_drillTank2.size = Vector2Int(32, 32);
		info_drillTank2.duration = 0.6f;
		info_drillTank2.loop = true;
		info_drillTank2.texture = Resource->GetTexture(L"T_DrillTank2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank2_" + direction[i];
			info_drillTank2.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank2);
		}
	}

	//DrillTank3
	{
		Resource->LoadTexture(L"T_DrillTank3", L"FlipbookTest/drillTank3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_drillTank3 = {};
		info_drillTank3.start = 0;
		info_drillTank3.end = 2;
		info_drillTank3.line = 0;
		info_drillTank3.size = Vector2Int(32, 32);
		info_drillTank3.duration = 0.6f;
		info_drillTank3.loop = true;
		info_drillTank3.texture = Resource->GetTexture(L"T_DrillTank3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_DrillTank3_" + direction[i];
			info_drillTank3.line = i;
			Resource->CreateFlipbook(fullName, info_drillTank3);
		}
	}

	//Tank1
	{
		Resource->LoadTexture(L"T_Tank1", L"FlipbookTest/tank1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank1 = {};
		info_tank1.start = 0;
		info_tank1.end = 2;
		info_tank1.line = 0;
		info_tank1.size = Vector2Int(32, 32);
		info_tank1.duration = 0.6f;
		info_tank1.loop = true;
		info_tank1.texture = Resource->GetTexture(L"T_Tank1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank1_" + direction[i];
			info_tank1.line = i;
			Resource->CreateFlipbook(fullName, info_tank1);
		}
	}

	//Tank2
	{
		Resource->LoadTexture(L"T_Tank2", L"FlipbookTest/tank2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank2 = {};
		info_tank2.start = 0;
		info_tank2.end = 2;
		info_tank2.line = 0;
		info_tank2.size = Vector2Int(32, 32);
		info_tank2.duration = 0.6f;
		info_tank2.loop = true;
		info_tank2.texture = Resource->GetTexture(L"T_Tank2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank2_" + direction[i];
			info_tank2.line = i;
			Resource->CreateFlipbook(fullName, info_tank2);
		}
	}

	//Tank3
	{
		Resource->LoadTexture(L"T_Tank3", L"FlipbookTest/tank3.bmp", RGB(255, 0, 255));
		FlipbookInfo info_tank3 = {};
		info_tank3.start = 0;
		info_tank3.end = 2;
		info_tank3.line = 0;
		info_tank3.size = Vector2Int(32, 32);
		info_tank3.duration = 0.6f;
		info_tank3.loop = true;
		info_tank3.texture = Resource->GetTexture(L"T_Tank3");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Tank3_" + direction[i];
			info_tank3.line = i;
			Resource->CreateFlipbook(fullName, info_tank3);
		}
	}
	/*
	//Balloon1
	{
		Resource->LoadTexture(L"T_Balloon1", L"FlipbookTest/balloon1.bmp", RGB(255, 0, 255));
		FlipbookInfo info_balloon1 = {};
		info_balloon1.start = 0;
		info_balloon1.end = 2;
		info_balloon1.line = 0;
		info_balloon1.size = Vector2Int(32, 32);
		info_balloon1.duration = 0.6f;
		info_balloon1.loop = true;
		info_balloon1.texture = Resource->GetTexture(L"T_Balloon1");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Balloon1_" + direction[i];
			info_balloon1.line = i;
			Resource->CreateFlipbook(fullName, info_balloon1);
		}
	}

	//Balloon2
	{
		Resource->LoadTexture(L"T_Balloon2", L"FlipbookTest/balloon2.bmp", RGB(255, 0, 255));
		FlipbookInfo info_balloon2 = {};
		info_balloon2.start = 0;
		info_balloon2.end = 2;
		info_balloon2.line = 0;
		info_balloon2.size = Vector2Int(32, 32);
		info_balloon2.duration = 0.6f;
		info_balloon2.loop = true;
		info_balloon2.texture = Resource->GetTexture(L"T_Balloon2");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Balloon2_" + direction[i];
			info_balloon2.line = i;
			Resource->CreateFlipbook(fullName, info_balloon2);
		}
	}
	*/
	//Submarine
	{
		Resource->LoadTexture(L"T_Submarine", L"FlipbookTest/submarine.bmp", RGB(255, 0, 255));
		FlipbookInfo info_submarine = {};
		info_submarine.start = 0;
		info_submarine.end = 2;
		info_submarine.line = 0;
		info_submarine.size = Vector2Int(32, 32);
		info_submarine.duration = 0.6f;
		info_submarine.loop = true;
		info_submarine.texture = Resource->GetTexture(L"T_Submarine");

		for (int i = 0; i < 8; i++)
		{
			wstring fullName = L"FB_Submarine_" + direction[i];
			info_submarine.line = i;
			Resource->CreateFlipbook(fullName, info_submarine);
		}
	}

	// Die Effect
	{
		Resource->LoadTexture(L"T_Bomb", L"FlipbookTest/bomb.bmp", RGB(255, 0, 255));
		FlipbookInfo info_bomb = {};
		info_bomb.start = 0;
		info_bomb.end = 6;
		info_bomb.line = 0;
		info_bomb.size = Vector2Int(24, 24);
		info_bomb.duration = 0.6f;
		info_bomb.loop = false;
		info_bomb.texture = Resource->GetTexture(L"T_Bomb");
		Resource->CreateFlipbook(L"FB_Bomb", info_bomb);
	}

	//----------------------------------
	//  ## Sprite
	//----------------------------------
	Texture* redTile = Resource->LoadTexture(L"T_RedTile", L"UIStudy/RedTile.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_RedTile", redTile);

	Texture* dock = Resource->LoadTexture(L"T_BeachTileset_2", L"BeachTileset/BeachTileset_2.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_BeachTileset_2", dock);

	Texture* hpBackground = Resource->LoadTexture(L"T_HP_Background", L"UIStudy/HP_Background.bmp");
	Resource->CreateSprite(L"S_HP_Background", hpBackground);

	Texture* hpBar = Resource->LoadTexture(L"T_HP_Bar", L"UIStudy/HP_Bar.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_HP_Bar", hpBar);
	
	Texture* bullet = Resource->LoadTexture(L"T_Bullet", L"UIStudy/Bullet.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Bullet", bullet);

	//----------------------------------
	//  ## UI
	//----------------------------------
	Texture* Buttons = Resource->LoadTexture(L"T_Buttons", L"UIStudy/Buttons.bmp");
	Resource->CreateSprite(L"S_Button_L", Buttons, 0, 0, 100, 40);
	Resource->CreateSprite(L"S_Button_S", Buttons, 100, 0, 40, 40);

	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");
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
	for (BehicleActor* behicle : _behicles)
	{
		if (behicle->GetBehicleType() == L"FB_Submarine_")
		{
			if (behicle->GetCellPos() == cellPos) // 잠수함을 설치해도 바로 적용 안 됨.
			{
				return false;
			}
		}
	}

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
	if (46 <= tile->value && tile->value < 62) // 51이 물
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