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
	//if (Input->GetKeyDown(KeyCode::LeftMouse))
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
		//int x = pos.x; // 이미 32를 곱해주고 있음! 그래서 안해줘도 됨.
		//int y = pos.y;
		//cout << "x : " << x << "	y : " << y << endl;
		_block->SetCellPos(pos, true);
	}
}