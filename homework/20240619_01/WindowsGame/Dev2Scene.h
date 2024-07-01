#pragma once
#include "TilemapScene.h" // 얘가 이미 Scene을 상속 받고 있음

class MapToolController;
class BoatController;
class Panel;
class TilemapActor;
class Tilemap;
class BehicleController;
class RedBlockController;
class InstallBehicle;
class BehicleActor;

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
	RedBlockController* GetRedBlockController() { return _redBlockController; }
	vector<BehicleActor*> GetBehicleActor(){ return _behicles; }
	InstallBehicle* GetInstallBehicle() { return _installBehicle; }
private:
	//Panel* panel = nullptr;
	TilemapActor* _tilemapActor = nullptr;
	MapToolController* _mapToolController = nullptr;
	BoatController* _boatController = nullptr;//vector<BoatController*> _boatController = {};
	vector<BehicleActor*> _behicles = {};
	vector<BehicleController*> _behicleControllers = {};
	RedBlockController* _redBlockController = nullptr;
	InstallBehicle* _installBehicle = nullptr;

private:
	int _max = 4;

};