#pragma once
#include "Scene.h"
class Actor;
class TilemapActor;
class TilemapScene : public Scene
{
	DECLARE_CHILD(TilemapScene, Scene);
public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) = 0;
	virtual Tilemap* GetTilemap() = 0;
	virtual TilemapActor* GetTilemapActor() = 0;
	virtual bool CanGo(Vector2Int cellPos) = 0;

};

