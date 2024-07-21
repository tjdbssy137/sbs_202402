#pragma once
#include "TilemapScene.h" // 얘가 이미 Scene을 상속 받고 있음


class BoatController;
class Panel;
class TilemapActor;
class Tilemap;
class BehicleController;
class RedBlockController;
class BehicleActor;
class BoatActor;
class BulletActorController;
class GameWave;
class InstallPanel;
class InstallSubmarinePanel;
class ActionButtonsPanel;
class BulletActorController;

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
	RedBlockController* GetRedBlockController() { return _redBlockController; }
	
	vector<BoatActor*> GetBoatActor() { return _boats; }

	BulletActorController* GetBulletActorController() { return _bulletController; }
	
	vector<BehicleController*> GetBehicleController() { return _behicleControllers; }
	void SetBehicleController(BehicleController* behicleController) { _behicleControllers.push_back(behicleController); }
	vector<BehicleActor*> GetBehicleActor() { return _behicles; }
	void SetBehicleActor(BehicleActor* behicles) { _behicles.push_back(behicles); }

	GameWave* GetGameWave() { return _gameWave; }

	//Panel
	InstallPanel* GetInstallPanel() { return _installPanel; }
	InstallSubmarinePanel* GetInstallSubmarinePanel() { return _installSubmarinePanel; }
	ActionButtonsPanel* GetActionButtonsPanel() { return _actionButtonsPanel; }
private:
	//Actors
	TilemapActor* _tilemapActor = nullptr;
	vector<BoatActor*> _boats = {};
	vector<BehicleActor*> _behicles = {};

	//Controller
	vector<BoatController*> _boatControllers = {};
	vector<BehicleController*> _behicleControllers = {};
	RedBlockController* _redBlockController = nullptr;
	BulletActorController* _bulletController = nullptr;
	GameWave* _gameWave = nullptr;

	//Panel
	InstallPanel* _installPanel = nullptr;
	InstallSubmarinePanel* _installSubmarinePanel = nullptr;
	ActionButtonsPanel* _actionButtonsPanel = nullptr;
};