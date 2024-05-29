#include "pch.h"
#include "MapToolController.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"

void MapToolController::SetLink(MapToolTilemapActor* mapToolActor)
{
	//매게변수 유효성 검증 (주로 외부에서 온 변수 검증)
	assert(mapToolActor != nullptr);

	_mapToolActor = mapToolActor;
}


void MapToolController::Update()
{
	if (Input->GetKeyDown(KeyCode::S))
	{
		_mapToolActor->Save();
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		_mapToolActor->Load();
	}

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		int x = 0;
		int y = 0;
		Tilemap* tileMap = _mapToolActor->GetTileMap();
		int tileSize = tileMap->GetTileSize();

		Vector2Int mousePos = Input->GetMousePos();

		Vector2 pos = _mapToolActor->GetBody().pos;
		int spriteSize = _mapToolActor->GetTileSprites().size();
		x = (mousePos.x - static_cast<int>(pos.x)) / tileSize;
		y = (mousePos.y - static_cast<int>(pos.y)) / tileSize;

		Tile* tile = tileMap->GetTileAt({ x, y });
		if (tile)
		{
			tile->value++;
			tile->value %= spriteSize;
		}
	}

}