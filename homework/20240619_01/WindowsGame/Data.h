#pragma once
#include <vector>

class DataBase
{
	virtual void FromJson(string json) = 0; // JSONÀ» °´Ã¼·Î
	virtual string ToJson() = 0; // °´Ã¼¸¦ JSONÀ¸·Î
};

struct BehicleData : public DataBase
{
	int64 Id;
	string Name;
	float BulletDamage;
	float BulletSpeed;
	float AttackTime;
	int ColliderSize;
	int InstallGold;
	int UpgradeTowerId;
	int UpgradeGold;
	int RefundGold;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};
struct BoatData : public DataBase
{
	int64 Id;
	string Name;
	float HP;
	float MoveSpeed;
	int Gold;
public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

struct WaveData : public DataBase
{
	int64 Id;
	vector<int> BoatCount;
public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

struct MonsterData : public DataBase
{
	int64 Id;
	string Name;
	float HP;
	float MoveSpeed;
	int64 SkillId;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

