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
class BoatActor;
class BulletActorController;
class GameWave;
class InstallPanel;
class InstallSubmarinePanel;
class ActionButtonsPanel;

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
	
	InstallBehicle* GetInstallBehicle() { return _installBehicle; }
	vector<BoatActor*> GetBoatActor() { return _boats; }
	BulletActorController* GetBulletActorController() { return _bulletActorController; }
	
	vector<BehicleController*> GetBehicleController() { return _behicleControllers; }
	void SetBehicleController(BehicleController* behicleController) { _behicleControllers.push_back(behicleController); }
	vector<BehicleActor*> GetBehicleActor() { return _behicles; }
	void SetBehicleActor(BehicleActor* behicles) { _behicles.push_back(behicles); }

	InstallPanel* GetInstallPanel() { return _installPanel; }
	InstallSubmarinePanel* GetInstallSubmarinePanel() { return _installSubmarinePanel; }
	ActionButtonsPanel* GetActionButtonsPanel() { return _actionButtonsPanel; }
private:
	TilemapActor* _tilemapActor = nullptr;
	vector<BoatActor*> _boats = {};
	vector<BehicleActor*> _behicles = {};

	//Controller
	MapToolController* _mapToolController = nullptr;
	vector<BoatController*> _boatControllers = {};
	vector<BehicleController*> _behicleControllers = {};
	RedBlockController* _redBlockController = nullptr;
	InstallBehicle* _installBehicle = nullptr;
	BulletActorController* _bulletActorController = nullptr;
	GameWave* _gameWave = nullptr;

	//Panel
	InstallPanel* _installPanel = nullptr;
	InstallSubmarinePanel* _installSubmarinePanel = nullptr;
	ActionButtonsPanel* _actionButtonsPanel = nullptr;
};