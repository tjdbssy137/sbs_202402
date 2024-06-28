#include "pch.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include <queue>

void BehicleController::SetLink(BehicleActor* behicle)
{
	assert(behicle != nullptr);

	_behicle = behicle;
}
void BehicleController::Update()
{
	InstallBehicle();
}
void BehicleController::InstallBehicle()
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
		
		int x = pos.x * 32;
		int y = pos.y * 32;

	}


}