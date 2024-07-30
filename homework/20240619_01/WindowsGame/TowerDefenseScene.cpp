#include "pch.h"
#include "TowerDefenseScene.h"
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
#include "TilemapActor.h"
#include "Tilemap.h"
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
#include "TowerDefenseStartPanel.h"
#include "GameStatePanel.h"
void TowerDefenseScene::Init()
{
	LoadResource();
	//타일맵
	{
		_tilemapActor = new TilemapActor();
		_tilemapActor->SetTileMap(Resource->GetTileMap(L"TM_Background"));

		{
			vector<Sprite*> sprites;
			for (int i = 6; i <= 67; i++)
			{
				wchar_t keyName[128];
				swprintf_s(keyName, L"S_BeachTileset%d", i);
				sprites.push_back(Resource->GetSprite(keyName));
			}
			_tilemapActor->SetTileSprites(sprites);
		}

		_tilemapActor->Init();
		_tilemapActor->LoadTilemap(L"../Resources/Data/MapData.txt");

		this->SpawnActor(_tilemapActor);
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
			boat->SetCellPos(STARTPOS, true); //boat->SetCellPos({ 25 + i, 13 }, true);
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
	{//보물 상자
		_treasure = new SpriteActor();
		_treasure->SetLayer(LayerType::Object);
		_treasure->SetSprite(Resource->GetSprite(L"S_Treasure_Closed"));
		this->SpawnActor(_treasure);
		_treasure->SetPos({ 4 * 28, 4 * 28 });
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

	{
		_towerDefenseStartPanel = new TowerDefenseStartPanel();
		_towerDefenseStartPanel->Init();
		//_towerDefenseStartPanel->Hide();
	}

	{
		_gameStatePanel = new GameStatePanel();
		_gameStatePanel->Init();
		_gameStatePanel->Hide();
	}
	
	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

	Super::Init();

}
void TowerDefenseScene::Render(HDC hdc)
{
	Super::Render(hdc);

	_installPanel->Render(hdc);
	_installSubmarinePanel->Render(hdc);
	_actionButtonsPanel->Render(hdc);
	_towerDefenseStartPanel->Render(hdc);
	_gameStatePanel->Render(hdc);
}
void TowerDefenseScene::Update()
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

	_installPanel->Update();
	_installSubmarinePanel->Update();
	_actionButtonsPanel->Update();
	_towerDefenseStartPanel->Update();

	_gameWave->Update();

	if (_isGameStart)
	{
		_gameStatePanel->Show();
		_gameStatePanel->Update();
	}

	this->EnterEnemyCheck();
}
void TowerDefenseScene::Release()
{
	Super::Release();
	_installPanel->Release();
	_installSubmarinePanel->Release();
	_actionButtonsPanel->Release();
	_towerDefenseStartPanel->Release();
	_gameStatePanel->Release();
}

void TowerDefenseScene::EnterEnemyCheck()
{
	if (GAMEOVER < UserDatas->GetEnterEnemy())
	{
		_treasure->SetSprite(Resource->GetSprite(L"S_Treasure_Opened"));
		// 게임 끝나는 pannel을 띄우기.
	}
}

void TowerDefenseScene::LoadResource()
{
	// -------------------------------------
	// 
	//			BOAT RESOURCE
	// 
	// ------------------------------------- 
	//direction
	wstring direction[8] = { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	//EnemyBoat1
	{
		Resource->LoadTexture(L"T_EnemyBoat1", L"Flipbook/enemyBoat1.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_EnemyBoat2", L"Flipbook/enemyBoat2.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_EnemyShip1", L"Flipbook/enemyShip1.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_EnemyShip2", L"Flipbook/enemyShip2.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_EnemyShip3", L"Flipbook/enemyShip3.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_DrillTank1", L"Flipbook/drillTank1.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_DrillTank2", L"Flipbook/drillTank2.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_DrillTank3", L"Flipbook/drillTank3.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_Tank1", L"Flipbook/tank1.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_Tank2", L"Flipbook/tank2.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_Tank3", L"Flipbook/tank3.bmp", RGB(255, 0, 255));
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

	//Submarine
	{
		Resource->LoadTexture(L"T_Submarine", L"Flipbook/submarine.bmp", RGB(255, 0, 255));
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
		Resource->LoadTexture(L"T_Bomb", L"Flipbook/bomb.bmp", RGB(255, 0, 255));
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
	Texture* dock = Resource->LoadTexture(L"T_BeachTileset_2", L"BeachTileset/BeachTileset_2.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_BeachTileset_2", dock);

	Texture* treasure = Resource->LoadTexture(L"T_BeachTileset_Treasure", L"BeachTileset/BeachTileset_Treasure.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Treasure_Closed", treasure, 0, 0, 32, 32); 	// 털리기 전
	Resource->CreateSprite(L"S_Treasure_Opened", treasure, 64, 0, 32, 32); 	// 털린 후

	Texture* redTile = Resource->LoadTexture(L"T_RedTile", L"UIs/RedTile.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_RedTile", redTile);

	Texture* hpBackground = Resource->LoadTexture(L"T_HP_Background", L"UIs/HP_Background.bmp");
	Resource->CreateSprite(L"S_HP_Background", hpBackground);

	Texture* hpBar = Resource->LoadTexture(L"T_HP_Bar", L"UIs/HP_Bar.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_HP_Bar", hpBar);

	Texture* bullet = Resource->LoadTexture(L"T_Bullet", L"UIs/Bullet.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_Bullet", bullet);

	//----------------------------------
	//  ## UI
	//----------------------------------
	Texture* Buttons = Resource->LoadTexture(L"T_Buttons", L"UIs/Buttons.bmp");
	Resource->CreateSprite(L"S_Button_L", Buttons, 0, 0, 100, 40);
	Resource->CreateSprite(L"S_Button_S", Buttons, 100, 0, 40, 40);

	Texture* Buttons2 = Resource->LoadTexture(L"T_Buttons2", L"UIs/Buttons2.bmp");

	// 시작 화면
	Texture* startPanel = Resource->LoadTexture(L"T_StartPanel", L"UIs/startPanel.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_StartPanel", startPanel);
	Texture* startButton = Resource->LoadTexture(L"T_StartButton", L"UIs/startButtons.bmp", RGB(255, 0, 255));
	Texture* pauseButton = Resource->LoadTexture(L"T_PauseButton", L"UIs/pauseButton.bmp", RGB(255, 0, 255));
	Resource->CreateSprite(L"S_PauseButton", pauseButton);

	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");

	//----------------------------------
	//  ## Map
	//----------------------------------
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
		Resource->CreateTileMap(L"TM_Background", mapSize, 32, tiles);
	}
}


Vector2 TowerDefenseScene::GetTilemapPos(Vector2Int cellPos)
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

bool TowerDefenseScene::CanGo(Vector2Int cellPos)
{
	for (BehicleActor* behicle : _behicles)
	{
		if (behicle->GetBehicleData().Id == 7) // 7은 Submarine
		{
			if (behicle->GetCellPos() == cellPos) // 잠수함을 설치해도 바로 적용 안 됨.
			{
				return false;
			}
		}
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

Tilemap* TowerDefenseScene::GetTilemap()
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

TilemapActor* TowerDefenseScene::GetTilemapActor()
{
	assert(_tilemapActor != nullptr);
	if (_tilemapActor == nullptr)
	{
		return nullptr;
	}
	return _tilemapActor;
}