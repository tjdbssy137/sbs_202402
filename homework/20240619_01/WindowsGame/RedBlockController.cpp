#include "pch.h"
#include "RedBlockController.h"
#include "RedBlockActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"

void RedBlockController::SetLink(RedBlockActor* block)
{
	assert(block != nullptr);
	_block = block;
}

void RedBlockController::Update()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}
		TilemapActor* tilemapActor = scene->GetTilemapActor();
		assert(tilemapActor != nullptr);
		if (tilemapActor == nullptr)
		{
			return;
		}
		Vector2Int pos = tilemapActor->GetTileIndexByPos(Input->GetMousePos());
		//cout << "pos.x : " << pos.x << "	pos.y : " << pos.y << endl;
		int x = pos.x * 32;
		int y = pos.y * 32;
		//cout << "x : " << x << "	y : " << y << endl;

		_block->SetCellPos({ x, y }, true);
	}
}