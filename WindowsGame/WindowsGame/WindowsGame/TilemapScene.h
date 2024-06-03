#pragma once
#include "Scene.h"
class Actor;
class TilemapScene : public Scene
{
	DECLARE_CHILD(TilemapScene, Scene);
public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) = 0;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) = 0;
};

