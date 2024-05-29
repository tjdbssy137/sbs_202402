#include "pch.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"

void MapToolTilemapActor::Save()
{
	Tilemap* tileMap = this->GetTileMap();
	if (tileMap == nullptr) return;

	tileMap->SaveFile(L"../Resources/Data/MapData.txt");

	printf("Save!");
}
void MapToolTilemapActor::Load()
{
	Tilemap* tileMap = this->GetTileMap();
	tileMap->LoadFile(L"../Resources/Data/MapData.txt");
	printf("Load!");
}
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
}
void MapToolTilemapActor::Release()
{
	Super::Release();
}
