#pragma once

class DataBase
{
	virtual void FromJson(string json) = 0; // JSONÀ» °´Ã¼·Î
	virtual string ToJson() = 0; // °´Ã¼¸¦ JSONÀ¸·Î
};
struct TowerData : public DataBase
{

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

