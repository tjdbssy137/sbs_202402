#include "pch.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"

void MapToolTilemapActor::Init()
{
	Super::Init();
}
void MapToolTilemapActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MapToolTilemapActor::Update()
{
	Super::Update();
	Update_Picking();
	if (Input->GetKeyDown(KeyCode::S))
	{
		this->Save();
	}
	if (Input->GetKeyDown(KeyCode::L))
	{
		this->Load();
	}
}
void MapToolTilemapActor::Release()
{
	Super::Release();
}

void MapToolTilemapActor::Update_Picking()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 타일이 클릭되었는지?
		// 타일이 클릭 되었다면
		// 해당 타일의 Value + 1

		int x = 0;
		int y = 0;
		Tilemap* tileMap = this->GetTileMap();
		int tileSize = tileMap->GetTileSize();
		Vector2Int mousePos = Input->GetMousePos();
		x = (mousePos.x - static_cast<int>(this->_body.pos.x)) / tileSize;
		y = (mousePos.y - static_cast<int>(this->_body.pos.y)) / tileSize;

		Tile* tile = tileMap->GetTileAt({x, y});
		if (tile)
		{
			tile->value++;
			tile->value %= this->_sprites.size();//++를 계속 하다보면 저장해둔 Sprite의 개수를 넘어갈 수도 있기 때문에 방지하기 위한 코드
		}
	}
}

void MapToolTilemapActor::Save()
{
	Tilemap* tileMap = this->GetTileMap();
	if (tileMap == nullptr)
	{
		return;
	}

	tileMap->SaveFile(L"../Resources/Data/MapData.txt");
	printf("Save");
}

void MapToolTilemapActor::Load()
{
	Tilemap* tileMap = this->GetTileMap();
	if (tileMap == nullptr)
	{
		return;
	}

	tileMap->LoadFile(L"../Resources/Data/MapData.txt");
	printf("Load");
}