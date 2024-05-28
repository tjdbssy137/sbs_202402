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
		// Ÿ���� Ŭ���Ǿ�����?
		// Ÿ���� Ŭ�� �Ǿ��ٸ�
		// �ش� Ÿ���� Value + 1

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
			tile->value %= this->_sprites.size();//++�� ��� �ϴٺ��� �����ص� Sprite�� ������ �Ѿ ���� �ֱ� ������ �����ϱ� ���� �ڵ�
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