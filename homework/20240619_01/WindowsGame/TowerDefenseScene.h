#pragma once
#include "TilemapScene.h" // 얘가 이미 Scene을 상속 받고 있음

#define DESTPOS		Vector2Int{ 5, 3 }
#define	STARTPOS	Vector2Int{ 54, 25 }

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
class SpriteActor;

class TowerDefenseScene : public TilemapScene
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
	virtual bool CanGo(Vector2Int cellPos) override;
public:
	RedBlockController* GetRedBlockController() { return _redBlockController; }
	BulletActorController* GetBulletActorController() { return _bulletController; }
	vector<BehicleController*> GetBehicleController() { return _behicleControllers; }
	void SetBehicleController(BehicleController* behicleController) { _behicleControllers.push_back(behicleController); }
	GameWave* GetGameWave() { return _gameWave; }

	// Actor
	vector<BoatActor*> GetBoatActor() { return _boats; }	
	vector<BehicleActor*> GetBehicleActor() { return _behicles; }
	void SetBehicleActor(BehicleActor* behicles) { _behicles.push_back(behicles); }

	//Panel
	InstallPanel* GetInstallPanel() { return _installPanel; }
	InstallSubmarinePanel* GetInstallSubmarinePanel() { return _installSubmarinePanel; }
	ActionButtonsPanel* GetActionButtonsPanel() { return _actionButtonsPanel; }

	// Gold
	void MakeGold(int gold) { _gold += gold; }
	void PayGold(int gold) { _gold -= gold; }
	int GetGold() { return _gold; }

	// Treasure
	void AddEnterEnemyCount() { _enterEnemyCount++; }
	int GetEnterEnemyCount() { return _enterEnemyCount; }
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

	// Gold
	int _gold = 110; // 기본 금액

	// Treasure
	SpriteActor* _treasure = nullptr;
	int _enterEnemyCount = 0;
};