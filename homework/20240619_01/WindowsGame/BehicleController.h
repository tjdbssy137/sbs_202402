#pragma once
class BehicleActor;
class BoatActor;
class BulletActorController;

class BehicleController
{
private:
	BehicleActor* _behicle = nullptr;
public:
	void SetLink(BehicleActor* behicle);
	void Update();

public:
	void UpdateAttack();
	void UpdateIdle();
	void UseBullet();
	void SettingBehicle(int id);
	void DeleteBehicle();
public:
	BehicleData GetBehicleData() { return _data; }

private:
	BehicleData _data;
	vector<BoatActor*> _boats;
	BoatActor* _targetBoat = nullptr;
	BulletActorController* _bulletActorController = nullptr;
	float _attackCoolDown;


};