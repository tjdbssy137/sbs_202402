#pragma once
class TowerDefensePanel;

class UserDataManager
{
	DECLARE_SINGLE(UserDataManager);
public:
	void Init();
	void Update();
	void Release();

public:
	void MakeGold(int gold) { _gold += gold; }
	void PayGold(int gold) { _gold -= gold; }
	int GetGold() { return _gold; }

	void SetWave(int wave) { _wave = wave; };

	void AddEnterEnemyCount() { _enterEnemy++; };
	int GetEnterEnemy() { return _enterEnemy; };

private:
	int _wave = 1;
	int _gold = 120;
	int _enterEnemy = 0;

private:
	TowerDefensePanel* _mainPanel = nullptr;
};

