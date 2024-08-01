#pragma once
#include "BulletActor.h"

class BulletActorController
{
public:
	void Init();
public:
	void PushBullet(BulletActor* bullet);
	BulletActor* PopBullet();
	int BulletCount();
private:
	vector<BulletActor*> _bullets;
};