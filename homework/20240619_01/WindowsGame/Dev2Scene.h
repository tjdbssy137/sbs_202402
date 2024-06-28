#pragma once
#include "TilemapScene.h" // 얘가 이미 Scene을 상속 받고 있음

class MapToolController;
class BoatController;
class Panel;
class TilemapActor;
class Tilemap;
class BehicleController;
class RedBlockController;
class Dev2Scene : public TilemapScene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void LoadResource();

public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) override;
	virtual Tilemap* GetTilemap() override;
	virtual TilemapActor* GetTilemapActor() override;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) override;
public:
	MapToolController* GetMapToolController() { return _mapToolController;	}
private:
	//Panel* panel = nullptr;
	TilemapActor* _tilemapActor = nullptr;
	MapToolController* _mapToolController = nullptr;
	BoatController* _boatController = nullptr;
	BehicleController* _behicleController = nullptr;
	RedBlockController* _redBlockController = nullptr;
};