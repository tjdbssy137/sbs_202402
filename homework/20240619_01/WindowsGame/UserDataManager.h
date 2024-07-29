#pragma once

class UserDataManager
{
	DECLARE_SINGLE(UserDataManager);
public:
	void Init();
	void Release();

public:
	void MakeGold(int gold) { _gold += gold; }
	void PayGold(int gold) { _gold -= gold; }
	int GetGold() { return _gold; }

	void SetWave(int wave) { _wave = wave; };
	int GetWave() { return _wave; };

	void AddEnterEnemyCount() { _enterEnemy++; };
	int GetEnterEnemy() { return _enterEnemy; };

private:
	int _wave = 1;
	int _gold = 120;
	int _enterEnemy = 0;

};

