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
	_tileSize = 88;
	{
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

	}

	{
		Vector2Int mapSize = Vector2Int(10, 10);
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

		Resource->CreateTileMap(L"TM_Test", mapSize, _tileSize, tiles);
	}

	_mapToolController = new MapToolController();

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
		actor->SetLayer(LayerType::Background);
		actor->Init();

		//이 액터를 조종하겠습니다.
		_mapToolController->SetLink(actor);

		this->SpawnActor(actor);
	}


	_creatureController = new CreatureController();

	{
		CreatureActor* actor = new CreatureActor();
		actor->SetLayer(LayerType::Character);
		actor->SetName("Player");
		actor->SetPos(Vector2(396, 300));
		actor->Init();
		_creatureController->SetLink(actor);
		this->SpawnActor(actor);
	}

	{
		CreatureActor* actor = new CreatureActor();
		actor->SetLayer(LayerType::Character);
		actor->SetName("Friend");
		actor->SetPos(Vector2(486, 300));
		actor->Init();
		this->SpawnActor(actor);
	}


	this->SetCameraPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

	Super::Init();

}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
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
	//----------------------------------
	//  ## Background
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_Background"
			, L"CameraStudy/backround_supermario.bmp");
		Resource->CreateSprite(L"S_Background", texture);
	}


	// -------------------------------------
	// 
	//			CREATURE RESOURCE
	// 
	// ------------------------------------- 
	// PlayerDown
	{
		Resource->LoadTexture(L"T_Character", L"FlipbookTest/PlayerDown.bmp", RGB(128, 128, 128));
		FlipbookInfo _downInfo = {};
		_downInfo.start = 0;
		_downInfo.end = 9;
		_downInfo.line = 0;
		_downInfo.size = Vector2Int(200, 200);
		_downInfo.duration = 1.0f;
		_downInfo.loop = true;
		_downInfo.texture = Resource->GetTexture(L"T_Character");

		Resource->CreateFlipbook(L"FB_CharacterDown_Idle", _downInfo);

		_downInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterDown_Move", _downInfo);

		_downInfo.line = 3;
		_downInfo.end = 7;
		_downInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterDown_Attack", _downInfo);
	}

	// PlayerUp
	{
		Resource->LoadTexture(L"T_Character2", L"FlipbookTest/PlayerUp.bmp", RGB(128, 128, 128));
		FlipbookInfo _upInfo = {};
		_upInfo.start = 0;
		_upInfo.end = 9;
		_upInfo.line = 0;
		_upInfo.size = Vector2Int(200, 200);
		_upInfo.duration = 1.0f;
		_upInfo.loop = true;
		_upInfo.texture = Resource->GetTexture(L"T_Character2");

		Resource->CreateFlipbook(L"FB_CharacterUp_Idle", _upInfo);

		_upInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterUp_Move", _upInfo);

		_upInfo.line = 3;
		_upInfo.end = 7;
		_upInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterUp_Attack", _upInfo);
	}

	// PlayerLeft
	{
		Resource->LoadTexture(L"T_Character3", L"FlipbookTest/PlayerLeft.bmp", RGB(128, 128, 128));
		FlipbookInfo _leftInfo = {};
		_leftInfo.start = 0;
		_leftInfo.end = 9;
		_leftInfo.line = 0;
		_leftInfo.size = Vector2Int(200, 200);
		_leftInfo.duration = 1.0f;
		_leftInfo.loop = true;
		_leftInfo.texture = Resource->GetTexture(L"T_Character3");

		Resource->CreateFlipbook(L"FB_CharacterLeft_Idle", _leftInfo);

		_leftInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterLeft_Move", _leftInfo);

		_leftInfo.line = 3;
		_leftInfo.end = 7;
		_leftInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterLeft_Attack", _leftInfo);
	}

	// PlayerRight
	{
		Resource->LoadTexture(L"T_Character4", L"FlipbookTest/PlayerRight.bmp", RGB(128, 128, 128));
		FlipbookInfo _rightInfo = {};
		_rightInfo.start = 0;
		_rightInfo.end = 9;
		_rightInfo.line = 0;
		_rightInfo.size = Vector2Int(200, 200);
		_rightInfo.duration = 1.0f;
		_rightInfo.loop = true;
		_rightInfo.texture = Resource->GetTexture(L"T_Character4");

		Resource->CreateFlipbook(L"FB_CharacterRight_Idle", _rightInfo);

		_rightInfo.line = 1;
		Resource->CreateFlipbook(L"FB_CharacterRight_Move", _rightInfo);

		_rightInfo.line = 3;
		_rightInfo.end = 7;
		_rightInfo.loop = false;
		Resource->CreateFlipbook(L"FB_CharacterRight_Attack", _rightInfo);
	}

	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");

	//----------------------------------
	//  ## UI
	//----------------------------------

}