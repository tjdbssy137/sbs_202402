#pragma once
#include "TilemapScene.h" // �갡 �̹� Scene�� ��� �ް� ����

#define DESTPOS		Vector2Int{ 5, 3 }
#define	STARTPOS	Vector2Int{ 54, 25 }
#define GAMEOVER	12

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
class BulletActorController;
class SpriteActor;
//panel
class InstallPanel;
class InstallSubmarinePanel;
class ActionButtonsPanel;
class TowerDefenseStartPanel;
class GameStateController;
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
	/*ActionButtonsPanel* GetActionButtonsPanel() { return _actionButtonsPanel; }
	TowerDefenseStartPanel* GetTowerDefenseStartPanel() { return _towerDefenseStartPanel; }
	*/
	GameStateController* GetGameStateController() { return _gameStateController; }
	
	// Gold
	void MakeGold(int gold) { _gold += gold; }
	void PayGold(int gold) { _gold -= gold; }
	int GetGold() { return _gold; }

	// Treasure
	void AddEnterEnemyCount() { _enterEnemyCount++; }
	int GetEnterEnemyCount() { return _enterEnemyCount; }
	void EnterEnemyCheck();

	// Game
	void SetGameStart(bool isGameStart) { _isGameStart = isGameStart; }
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
	TowerDefenseStartPanel* _towerDefenseStartPanel = nullptr;
	GameStateController* _gameStateController = nullptr;
	// Gold
	int _gold = 1000; // �⺻ �ݾ� 120

	// Treasure
	SpriteActor* _treasure = nullptr;
	int _enterEnemyCount = 0;

	// Game
	bool _isGameStart = false;
};